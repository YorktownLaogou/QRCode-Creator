#pragma once
#include <stdexcept>

#include "QRSpec_Capacity.h"
#include "QRSpec_Patterns.h"
#include "QRSpec_Blocks.h"


enum class QREccLevel : uint8_t
{
	L,
	M,
	Q,
	H
};
enum class EncodeMode : uint8_t
{
	NUMERIC,
	ALPHA,
	BYTE,
	KANJI
};


namespace QRSpec
{
	static int ChooseVersion(size_t inputLength, QREccLevel ECC, EncodeMode EncodMode)
	{
		for (int i = 0; i < 40; ++i)
		{
			int capacityBytes = QRSpec_Internal::SourceDataCapacityInfo
								.Version[i]
								.Mode[static_cast<uint8_t>(EncodMode)]
								.EccStrength[static_cast<uint8_t>(ECC)];

			if (inputLength <= capacityBytes)
				return i + 1;
		}

		#ifndef NDEBUG
			throw std::runtime_error("Data too large");
		#else
			return 40;
		#endif
	}


	static int GetByteCapacity(int iVersion , QREccLevel ECC)
	{
		// Since a check was done at the very beginning, no boundary check is performed here
		return QRSpec_Internal::CodeWordCapacityInfo
				.Version[iVersion - 1]
				.EccStrength[static_cast<uint8_t>(ECC)];
	}


	static int GetBlockEccLen		(int iVersion, QREccLevel ECC)
	{
		return QRSpec_Internal::CodewordSplittingTable
				.Version[iVersion - 1]
				.EccStrength[static_cast<uint8_t>(ECC)]
				.EccLength;
	}


	static int GetSmallBlockNumber	(int iVersion, QREccLevel ECC)
	{
		return QRSpec_Internal::CodewordSplittingTable
				.Version[iVersion - 1]
				.EccStrength[static_cast<uint8_t>(ECC)]
				.SmallBlockNumber;
	}


	static int GetSmallBlockSize	(int iVersion, QREccLevel ECC)
	{
		return  QRSpec_Internal::CodewordSplittingTable
				.Version[iVersion - 1]
				.EccStrength[static_cast<uint8_t>(ECC)]
				.SmallBlockSize;
	}


	static int GetLargeBlockNumber	(int iVersion, QREccLevel ECC)
	{
		return  QRSpec_Internal::CodewordSplittingTable
				.Version[iVersion - 1]
				.EccStrength[static_cast<uint8_t>(ECC)]
				.LargeBlockNumber;
	}


	static int GetLargeBlockSize	(int iVersion, QREccLevel ECC)
	{
		return  QRSpec_Internal::CodewordSplittingTable
				.Version[iVersion - 1]
				.EccStrength[static_cast<uint8_t>(ECC)]
				.LargeBlockSize;
	}


	static int GetTotalBlocksNumber	(int iVersion, QREccLevel ECC)
	{
		return GetSmallBlockNumber(iVersion, ECC) + GetLargeBlockNumber(iVersion, ECC);
	}


	static uint32_t GetQRSide(int iVersion)
	{
		return QRSpec_Internal::SideOfVersion[iVersion - 1];
	}


	static uint32_t GetQRSize(int iVersion)
	{
		return QRSpec_Internal::SizeOfVersion[iVersion - 1];
	}


	static int GetAlignmentStep(int iVersion)
	{
		return QRSpec_Internal::AlignmentPatternPositionsList[iVersion - 1][0];
	}


	static int GetAlignmentPos(int iVersion, int Step)
	{
		#ifdef DEBUG
			if  (AlignmentPatternPositionsList[iVersion - 1][Step] == 0)
			{
				throw std::invalid_argument("Out of bounds");
			}
		#endif 

		return QRSpec_Internal::AlignmentPatternPositionsList[iVersion - 1][Step + 1];
		
	}


	static char const(&GetVersionInfo(int version))[18]
	{
		return QRSpec_Internal::VersionInformationBitStream[version - 1];
	}


	static char const(&GetFormatInfo(uint32_t id, QREccLevel ecc))[15]
	{
		return QRSpec_Internal::formatInfoAfterMasking[static_cast<uint32_t>(ecc)][id];
	}
	
};