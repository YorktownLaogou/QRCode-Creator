#pragma once
#include "QRMatrix.h"


class QRMasks
{
public:

	static void CoverageMask(QRMatrix& m, uint32_t id)
	{
		uint32_t Side = m.GetSide();
		QRMatrix_Operator Matrix(m);

		for (uint32_t y = 0; y < Side; y++)
		{
			for (uint32_t x = 0; x < Side; x++)
			{
				if (Matrix.NeedMask(x, y) && Patterns(id, x, y))
					Matrix.ReversePixel(x, y);
			}
		}
	}


private:


	static inline bool Patterns(uint8_t id, uint32_t x, uint32_t y)
	{
		switch (id)
		{
		case 0: return (x + y) % 2 == 0;
		case 1: return y % 2 == 0;
		case 2: return x % 3 == 0;
		case 3: return (x + y) % 3 == 0;
		case 4: return ((y / 2) + (x / 3)) % 2 == 0;
		case 5: return (x * y) % 2 + (x * y) % 3 == 0;
		case 6: return ((x * y) % 2 + (x * y) % 3) % 2 == 0;
		case 7: return ((x + y) % 2 + (x * y) % 3) % 2 == 0;
		default: return false;
		}
	}
};


uint32_t RatingMask(QRMatrix& m)
{


	uint32_t Penalty = 0;
	uint32_t side = m.GetSide();


	//Rule 1 (2x2)
	int penalty = 0;
	for (uint32_t y = 0; y < side; ++y)
	{
		int runLength = 1;
		int prev = m.GetPixel(0, y);

		for (uint32_t x = 1; x < side; ++x)
		{
			int curr = m.GetPixel(x, y);

			if (curr == prev)
			{
				runLength++;
			}
			else
			{
				if (runLength >= 5)
					penalty += 3 + (runLength - 5);

				runLength = 1;
				prev = curr;
			}
		}

		// ÐÐÎ²½áËã
		if (runLength >= 5)
			penalty += 3 + (runLength - 5);
	}
	for (uint32_t x = 0; x < side; ++x)
	{
		int runLength = 1;
		int prev = m.GetPixel(x, 0);

		for (uint32_t y = 1; y < side; ++y)
		{
			int curr = m.GetPixel(x, y);

			if (curr == prev)
			{
				runLength++;
			}
			else
			{
				if (runLength >= 5)
					penalty += 3 + (runLength - 5);

				runLength = 1;
				prev = curr;
			}
		}

		if (runLength >= 5)
			penalty += 3 + (runLength - 5);
	}



	//Rule 2 (2x2)
	for (uint32_t y = 0; y < side - 1; y++)
	{
		for (uint32_t x = 0; x < side - 1; x++)
		{
			bool Pixel = m.GetPixel(x, y);
			if
				(
					Pixel == m.GetPixel(x, y + 1) &&
					Pixel == m.GetPixel(x + 1, y) &&
					Pixel == m.GetPixel(x + 1, y + 1)
					) Penalty += 3;
		}
	}


	//Rule 3
	static const bool pattern1[11] = { 0,0,0,0,1,0,1,1,1,0,1 };
	static const bool pattern2[11] = { 1,0,1,1,1,0,1,0,0,0,0 };
	uint32_t Counter = 0;
	for (uint32_t y = 0; y < side; y++)
	{
		for (uint32_t x = 0; x < side - 11; x++)
		{
			Counter = 0;
			for (uint32_t i = 0; i < 11; i++)
			{
				if (m.GetPixel(x + i, y) == pattern1[i]) Counter++;
				else break;
			}
			if (Counter == 11)Penalty += 40;

			Counter = 0;
			for (uint32_t i = 0; i < 11; i++)
			{
				if (m.GetPixel(x + i, y) == pattern2[i]) Counter++;
				else break;
			}
			if (Counter == 11)Penalty += 40;
		}
	}
	for (uint32_t y = 0; y < side - 11; y++)
	{
		for (uint32_t x = 0; x < side; x++)
		{
			Counter = 0;
			for (uint32_t i = 0; i < 11; i++)
			{
				if (m.GetPixel(x, y + i) == pattern1[i]) Counter++;
				else break;
			}
			if (Counter == 11)Penalty += 40;

			Counter = 0;
			for (uint32_t i = 0; i < 11; i++)
			{
				if (m.GetPixel(x, y + i) == pattern2[i]) Counter++;
				else break;
			}
			if (Counter == 11)Penalty += 40;
		}
	}


	//Rule 4
	uint32_t total_modules = side * side;
	uint32_t black_count = 0;
	for (uint32_t y = 0; y < side; y++)
	{
		for (uint32_t x = 0; x < side; x++)
		{
			if (m.GetPixel(x, y) == 1)black_count++;
		}
	}
	uint32_t ratio = (black_count * 100) / total_modules;
	Penalty += ((ratio - 50) < 0 ? ratio - 50 : (ratio - 50) * -1) / 5 * 10;


	return Penalty;
}


uint32_t SetMask(QRMatrix& m)
{
	uint32_t BestScore = 0xFFFFFFFF, BestID = 0, ScoreBuffer;


	for (int i = 0; i < 8; i++)
	{
		QRMasks::CoverageMask(m, i);
		ScoreBuffer = RatingMask(m);
		if (ScoreBuffer < BestScore)
		{
			BestID = i;
			BestScore = ScoreBuffer;
		}
		QRMasks::CoverageMask(m, i);
	}


	QRMasks::CoverageMask(m, BestID);


	return BestID;
}