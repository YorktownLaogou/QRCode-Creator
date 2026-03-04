#pragma once
#include <vector>
#include <cstdint>

#include "VersionInfo.h"
#include "ECCCalculator.h"

class BlocksBuffer
{
	public:
		BlocksBuffer(int iVersion, QREccLevel ECC)
		{
			const size_t smallCount = QRVersionInfo::GetSmallBlockNumber(iVersion, ECC);
			const size_t smallSize  = QRVersionInfo::GetSmallBlockSize(iVersion, ECC);
			const size_t largeCount = QRVersionInfo::GetLargeBlockNumber(iVersion, ECC);
			const size_t largeSize  = QRVersionInfo::GetLargeBlockSize(iVersion, ECC);
			const size_t EccLen     = QRVersionInfo::GetBlockEccLen(iVersion, ECC);

		
			blocks_.reserve(QRVersionInfo::GetTotalBlocksNumber(iVersion, ECC));

			// small blocks
			for (size_t i = 0; i < smallCount; ++i)
				blocks_.emplace_back(smallSize + EccLen);

			// large blocks
			for (size_t i = 0; i < largeCount; ++i)
				blocks_.emplace_back(largeSize + EccLen);
		}

		void WriteDataWord(std::vector<uint8_t>& src,  uint32_t BlockId)
		{
			std::vector<uint8_t>& dst = getBlock(BlockId);
			std::copy(src.begin(), src.end(), dst.begin());
		}

		void WriteECC(const std::vector<uint8_t>& src, uint32_t BlockId ,uint32_t DataWordLen)
		{
			std::vector<uint8_t>& dst = getBlock(BlockId );
			std::copy(src.begin(), src.end(), dst.begin() + DataWordLen);
		}

		std::vector<uint8_t>& getBlock(uint32_t BlockId)
		{
			return blocks_[BlockId];
		}

		uint8_t GetBlockByte(uint32_t BlockId , uint32_t Offset)
		{
			return blocks_[BlockId][Offset];
		};
	private:

		std::vector<std::vector<uint8_t>> blocks_;
};


std::vector<uint8_t> BuildFinalStream (int iVersion, QREccLevel ECC, std::vector<uint8_t>& Text)
{
	const uint32_t smallCount = QRVersionInfo::GetSmallBlockNumber(iVersion, ECC);
	const uint32_t smallSize  = QRVersionInfo::GetSmallBlockSize(iVersion, ECC);
	const uint32_t largeCount = QRVersionInfo::GetLargeBlockNumber(iVersion, ECC);
	const uint32_t largeSize  = QRVersionInfo::GetLargeBlockSize(iVersion, ECC);
	const uint32_t EccLen     = QRVersionInfo::GetBlockEccLen(iVersion, ECC);
	const uint32_t BlockNum   = QRVersionInfo::GetTotalBlocksNumber(iVersion, ECC);
	BlocksBuffer buffer(iVersion, ECC);


	// (1 Segment block
	uint32_t i = 0,byetCounter = 0;
	for (; i < smallCount; i++)
	{
		std::vector<uint8_t>BlockDataWordTemp;
		BlockDataWordTemp.reserve(smallSize);
		BlockDataWordTemp.assign(Text.begin() + byetCounter , Text.begin() + byetCounter + smallSize);
		
		buffer.WriteDataWord(BlockDataWordTemp , i);
		buffer.WriteECC(CalculateECC(BlockDataWordTemp , EccLen) , i , smallSize);

		byetCounter += smallSize;
	}
	for (; i < largeCount + smallCount; i++)
	{
		std::vector<uint8_t>BlockDataWordTemp;
		BlockDataWordTemp.reserve(largeSize);
		BlockDataWordTemp.assign(Text.begin() + byetCounter, Text.begin() + byetCounter + largeSize);

		buffer.WriteDataWord(BlockDataWordTemp, i);
		buffer.WriteECC(CalculateECC(BlockDataWordTemp, EccLen), i, largeSize);

		byetCounter += largeSize;
	}


	// (2 The first part loops through and extracts each one, while the second part only extracts large block.
	std::vector<uint8_t> FinalCodeWord;
	FinalCodeWord.reserve(Text.size() + BlockNum * EccLen);
	for (i = 0; i < smallSize + EccLen; i++)
	{
		for(uint32_t j = 0 ; j < BlockNum ; j++)
		{
			FinalCodeWord.emplace_back(buffer.GetBlockByte(j, i));
		}
	}
	for (; i < largeSize; i++)
	{
		for (uint32_t j = smallCount + EccLen; j < BlockNum; j++)
		{
			FinalCodeWord.emplace_back(buffer.GetBlockByte(j, i));
		}
	}

	return FinalCodeWord;
}