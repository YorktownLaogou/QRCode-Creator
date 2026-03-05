#pragma once
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <string_view>

#include "QRSpec.h"

class BitBuffer
{
public:
	explicit BitBuffer(size_t DataCodewordLen) :data_(DataCodewordLen, 0)
	{
	}

	void AppendBits(uint32_t value, int bitCount)
	{
#ifdef DEBUG
		if (bitCount < 0 || bitCount > 32)
			throw std::invalid_argument("invalid bitCount");
#endif // DEBUG


		for (int i = bitCount - 1; i >= 0; --i) {
			bool bit = (value >> i) & 1;
			appendBit(bit);
		}
	}

	void AppendByte(uint8_t b)
	{
		AppendBits(b, 8);
	}

	size_t bitSize()const noexcept
	{
		return bit_size_;
	}

	const std::vector<uint8_t> toBytes()
	{
		return data_;
	}

	const size_t GetByteSize()
	{
		return bit_size_ / 8;
	}


private:
	void appendBit(bool bit)
	{
		size_t byteIndex = bit_size_ >> 3;
		size_t bitIndex = 7 - (bit_size_ & 7);

		if (bit)
			data_[byteIndex] |= (1 << bitIndex);

		bit_size_++;
	}

private:
	std::vector<uint8_t> data_;
	size_t bit_size_ = 0;
};





std::pair<std::vector<uint8_t>, int> encode(std::string_view text, QREccLevel ecc)
{
	EncodeMode Encodemode = EncodeMode::BYTE;


	int iVersion = QRSpec::ChooseVersion(text.size(), ecc, Encodemode);
	int DATA_CODEWORDS = QRSpec::GetByteCapacity(iVersion, ecc);
	int TOTAL_DATA_BITS = DATA_CODEWORDS * 8;
	BitBuffer buffer(DATA_CODEWORDS);


	// (1 Mode indicator (Byte mode = 0100)
	buffer.AppendBits(0b0100, 4);


	// (2 Character count (8 bits for V1 byte mode)
	buffer.AppendBits(static_cast<uint32_t>(text.size()), 8);


	// (3 Data
	for (unsigned char c : text)
		buffer.AppendByte(c);


	// (4 Terminator (×î¶à²¹µ½ 4 bits)
	int remaining = TOTAL_DATA_BITS - static_cast<int>(buffer.bitSize());
	if (remaining < 0)
		throw std::runtime_error("Data overflow");

	int terminatorBits = std::min(4, remaining);
	buffer.AppendBits(0, terminatorBits);


	// (5 Pad to byte boundary
	while (buffer.bitSize() % 8 != 0)
		buffer.AppendBits(0, 1);


	// (6 Pad bytes (0xEC, 0x11 alternating)
	static constexpr uint8_t PAD0 = 0xEC;
	static constexpr uint8_t PAD1 = 0x11;
	bool toggle = true;
	while (buffer.GetByteSize() < DATA_CODEWORDS)
	{
		buffer.AppendByte(toggle ? PAD0 : PAD1);
		toggle = !toggle;
	}

	std::vector<uint8_t> result = buffer.toBytes();
	return { result,iVersion };
}