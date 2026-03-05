#pragma once
#include <vector>
#include <cstdint>

#include "QRSpec.h"

//#define DEBUG

class QRMatrix
{
	friend class QRMatrix_Operator;
	private:
		enum class status : uint8_t
		{
			EMPTY,
			DATA,
			TEMPLATE,
			RESERVED
		};

		struct QRPixel
		{
			bool Value;
			status Status;
		};

	public:

		QRMatrix(uint32_t Verson) :_data(QRSpec::GetQRSize(Verson), { false, status::EMPTY })
		{
			_Side = QRSpec::GetQRSide(Verson);
		}

		bool GetPixel(uint32_t X, uint32_t Y)
		{
			return _data[Index(X, Y)].Value;
		}

		uint32_t GetSide()
		{
			return _Side;
		}

	private:
		
		constexpr  uint32_t Index(uint32_t X, uint32_t Y) const noexcept
		{
			#ifdef DEBUG
				if (X >= _Side || Y >= _Side)
				{
					throw std::invalid_argument("Out of bounds");
				}
			#endif

			return Y * _Side + X;
		}


		uint32_t _Side;
		std::vector<QRPixel> _data;
};


class QRMatrix_Operator
{

	public:

		QRMatrix_Operator(QRMatrix& _Data):Data(_Data)
		{}

	
		uint32_t GetSide() const
		{
			return Data._Side;
		}


		bool GetPixel(uint32_t X , uint32_t Y) const
		{
			return Data._data[Data.Index(X, Y)].Value;
		}


		void Placeholder(uint32_t X, uint32_t Y) const
		{
			SetTemplate(X, Y, 1);
		}


		void SetData(uint32_t X, uint32_t Y, bool data) const
		{
			QRMatrix::QRPixel& p = Data._data[Data.Index(X, Y)];
			p.Status = QRMatrix::status::DATA;
			p.Value = data;
		}


		void SetTemplate(uint32_t X, uint32_t Y, bool data) const
		{
			Data._data[Data.Index(X, Y)].Status = QRMatrix::status::TEMPLATE;
			Data._data[Data.Index(X, Y)].Value = data;
		}


		bool NeedMask(uint32_t X, uint32_t Y) const
		{
			return Data._data[Data.Index(X, Y)].Status == QRMatrix::status::DATA;
		}


		bool IsEmpty(uint32_t X, uint32_t Y) const
		{
			return Data._data[Data.Index(X, Y)].Status == QRMatrix::status::EMPTY;
		}


		void ReversePixel(uint32_t X, uint32_t Y) const
		{
			#ifdef DEBUG
				// data interface should not make any logic fallback decisions.
				if (_data[Index(X, Y)].Status != status::DATA))
				{
					throw std::invalid_argument("Flipped pixels that shouldn't have been changed");
				}
			#endif
			
			
				Data._data[Data.Index(X,Y)].Value = not(Data._data[Data.Index(X, Y)].Value);
		}

	private:

		QRMatrix& Data;
};



