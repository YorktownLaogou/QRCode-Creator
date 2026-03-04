#pragma once
#include "QRMatrix.h"
#include "VersionInfo.h"

void SetupFormatHolder(QRMatrix& m)
{
	uint32_t i;
	uint32_t side = m.GetSide();

	// top left horizontal
	for (i = 0; i <= 5; ++i)
		m.Placeholder(i, 8);
	m.Placeholder(7, 8);


	// Top left vertical
	for (i = 0; i <= 5; ++i)
		m.Placeholder(8, i);
	m.Placeholder(8, 7);
	m.Placeholder(8, 8);


	// VBottom left
	for (i = side - 7; i <= side - 1; ++i)
		m.Placeholder(8, i);


	// Upper right
	for (i = side - 8; i <= side - 1; ++i)
		m.Placeholder(i, 8);


	// Dark Module
	m.SetTemplate(8, side - 8, 1);
};





void SetupVersionInfo(QRMatrix& m, int version)
{
	if (version < 7)
		return;

	const int size = m.GetSide();
	const char (&bits)[18] = QRVersionInfo::GetVersionInfo(version);

	int bitIndex = 0;

	// ÓÒÉÏ
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m.SetTemplate(size - 11 + j, i, bits[bitIndex++]);
		}
	}

	bitIndex = 0;

	// ×óÏÂ
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m.SetTemplate(i, size - 11 + j,bits[bitIndex++]);
		}
	}
}





void SetupAlignment(QRMatrix& m, uint32_t cx, uint32_t cy)
{
	static constexpr int pattern[5][5] =
	{
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,0,1,0,1},
		{1,0,0,0,1},
		{1,1,1,1,1}
	};
	
	if(m.GetPixel(cx, cy) == 0)
	{
		for (uint32_t dy = 0; dy < 5; dy++)
		{
			for (uint32_t dx = 0; dx < 5; dx++)
			{
				m.SetTemplate(cx - 2 + dx, cy - 2 + dy, pattern[dy][dx]);
			}
		}
	}

}





void SetupFinder(QRMatrix& m, uint32_t cx, uint32_t cy)
{
	static constexpr int pattern[9][9] =
	{
		{0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,0},
		{0,1,0,0,0,0,0,1,0},
		{0,1,0,1,1,1,0,1,0},
		{0,1,0,1,1,1,0,1,0},
		{0,1,0,1,1,1,0,1,0},
		{0,1,0,0,0,0,0,1,0},
		{0,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0}
	};

	for (uint32_t dy = 0; dy < 9; dy++)
	{
		for (uint32_t dx = 0; dx < 9; dx++)
		{
			if (cx - 4u + dx < m.GetSide() && cy - 4u + dy < m.GetSide() )
				m.SetTemplate(cx - 4u + dx, cy - 4u + dy, pattern[dy][dx]);
		}
	}
}





void SetupTimingPattern(QRMatrix& m) noexcept
{
	const uint32_t Side = m.GetSide();
	const uint32_t Border = Side - 8;

	for (uint32_t r = 8; r < Border; r += 2)
	{
		m.SetTemplate(r, 6, 1);
		m.SetTemplate(6, r, 1);
	}

	for (uint32_t r = 9; r < Border; r += 2)
	{
		m.SetTemplate(r, 6, 0);
		m.SetTemplate(6, r, 0);
	}

}





void SetupFinalCodeword(QRMatrix& m, std::vector<uint8_t>& codeword)
{
	int side = m.GetSide();
	int x = side - 1;
	int y = side - 1;
	int direction = -1;

	size_t bitIndex = 0;
	size_t totalBits = codeword.size() * 8;

	while (x > 0)
	{
		if (x == 6) x--;

		while (true)
		{
			for (int dx = 0; dx < 2; dx++)
			{
				int xx = x - dx;

				if (m.IsEmpty(xx, y))
				{
					int bit = 0;

					if (bitIndex < totalBits)
					{
						uint8_t byte = codeword[bitIndex / 8];
						bit = (byte >> (7 - (bitIndex % 8))) & 1;
						bitIndex++;
					}

					m.SetData(xx, y, bit);
				}
			}

			y += direction;

			if (y < 0 || y >= side)
			{
				y -= direction;
				direction = -direction;
				break;
			}
		}

		x -= 2;
	}
}





void Filltemplate(QRMatrix& m , uint32_t version, std::vector<uint8_t>& codeword)
{
	// SetupFinder
	SetupFinder(m, 3, 3);
	SetupFinder(m, m.GetSide() - 4, 3);
	SetupFinder(m, 3, m.GetSide() - 4);
	
	
	// SetupAlignment
	uint32_t AlignmentStep = QRVersionInfo::GetAlignmentStep(version);
	for (uint32_t Y = 0; Y < AlignmentStep; Y++)
	{
		for (uint32_t X = 0; X < AlignmentStep; X++)
		{
			SetupAlignment(m, QRVersionInfo::GetAlignmentPos(version, X), QRVersionInfo::GetAlignmentPos(version, Y));
		}
	}


	// SetupTimingPattern
	SetupTimingPattern(m);


	// VersionInfo
	if (version >= 7) SetupVersionInfo(m, version);


	// Format holder
	SetupFormatHolder(m);

	
	// FinalCodeword
	SetupFinalCodeword(m, codeword);
}





void SetupFormatInfo(QRMatrix& m, uint32_t MaskID, QREccLevel ecc)
{
	uint32_t i ,Counter;
	uint32_t side = m.GetSide();
	const char(&bits)[15] = QRVersionInfo::GetFormatInfo(MaskID, ecc);


	// top left horizontal
	for (i = 0, Counter = 0; i <= 5; i++, Counter++)
		m.SetTemplate(i, 8, bits[Counter]);
	m.SetTemplate(7, 8, bits[6]);


	// Top left vertical 0 - 7
	for (i = 0, Counter = 14; i <= 5; i++, Counter--)
		m.SetTemplate(8, i, bits[Counter]);
	m.SetTemplate(8, 7, bits[8]);
	m.SetTemplate(8, 8, bits[7]);


	// Bottom left
	for (i = side - 7, Counter = 6; i <= side - 1; i++, Counter--)
		m.SetTemplate(8, i, bits[Counter]);
		 

	// Upper right
	for (i = side - 8, Counter = 7; i <= side - 1; i++, Counter++)
		m.SetTemplate(i, 8, bits[Counter]);
}