#pragma once
#include <vector>
#include <cstdint>

#include "VersionInfo.h"

#define DEBUG

class QRMatrix
{
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

		QRMatrix(uint32_t Verson):_data(QRVersionInfo::GetQRSize(Verson))
		{
			_Side = QRVersionInfo::GetQRSide(Verson);
		}

	
		uint32_t GetSide()
		{
			return _Side;
		}


		bool GetPixel(uint32_t X , uint32_t Y)
		{
			return _data[Index(X, Y)].Value;
		}


		void Placeholder(uint32_t X, uint32_t Y)
		{
			SetTemplate(X, Y, 1);
		}


		void SetData(uint32_t X, uint32_t Y, bool data)
		{
			QRPixel& p = _data[Index(X, Y)];
			p.Status = status::DATA;
			p.Value = data;
		}


		void SetTemplate(uint32_t X, uint32_t Y, bool data)
		{
			_data[Index(X, Y)].Status = status::TEMPLATE;
			_data[Index(X, Y)].Value = data;
		}


		bool NeedMask(uint32_t X, uint32_t Y)
		{
			return _data[Index(X, Y)].Status == status::DATA;
		}


		bool IsEmpty(uint32_t X, uint32_t Y)
		{
			return _data[Index(X, Y)].Status == status::EMPTY;
		}


		void ReversePixel(uint32_t X, uint32_t Y)
		{
			#ifdef DEBUG
				// data interface should not make any logic fallback decisions.
				if (_data[Index(X, Y)].Status != status::DATA)
				{
					throw std::invalid_argument("Flipped pixels that shouldn't have been changed");
				}
			#endif
			
			
			_data[Index(X,Y)].Value = not(_data[Index(X, Y)].Value);
		}


	private:

		inline uint32_t Index(uint32_t X, uint32_t Y) const
		{
			#ifdef DEBUG
				if  ( X >= _Side || Y >= _Side)
				{
					throw std::invalid_argument("Out of bounds");
				}
			#endif

			return Y * _Side + X;
		}


		uint32_t _Side;
		std::vector<QRPixel> _data;
};