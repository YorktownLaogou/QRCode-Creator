#pragma once
#include <cstdint>


#include "VersionInfo.h"
#include "ByteEncoder.h"
#include "FinalSream.h"
#include "StructureBuilder.h"
#include "QRMatrix.h"
#include "Mask.h"


namespace {
	QRMatrix GenerateQRcode_(std::span<const uint8_t> text, uint32_t ECCLevel)
	{
		QREccLevel ecc;
		switch (ECCLevel)
		{
			case 0:ecc = QREccLevel::L; break;
			case 1:ecc = QREccLevel::M; break;
			case 2:ecc = QREccLevel::Q; break;
			case 3:ecc = QREccLevel::H; break;
			default:ecc = QREccLevel::L;break;
		}
		

		auto [Codeword, version] = QRcreator::encode(reinterpret_cast<const char*>(text.data()), ecc);


		Codeword = BuildFinalStream(version, ecc, Codeword);


		QRMatrix QRMatrix_(version);
		Filltemplate(QRMatrix_, version, Codeword);


		uint32_t maskid = SetMask(QRMatrix_);		


		SetupFormatInfo(QRMatrix_, maskid, ecc);

		return QRMatrix_;
	}
}





QRMatrix GenerateQRcodeText(const char* text,uint32_t ECCLevel)
{
	
	#ifdef DEBUG
		if (!text)
			throw std::invalid_argument("null pointer");
	#endif


	size_t len = std::strlen(text);

	return GenerateQRcode_
	(
		std::span<const uint8_t>
		(
			reinterpret_cast<const uint8_t*>(text),len
		),
		ECCLevel
	);
}





QRMatrix GenerateQRcode(std::vector<uint8_t>& text, uint32_t ECCLevel)
{
	return GenerateQRcode_(text, ECCLevel);
}






//char* GenerateQRcode(const char* text, uint32_t ECCLevel)
//{
//	std::vector<uint8_t> text_(text, text + strlen(text));
//	GenerateQRcode_(text_ , ECCLevel);
//}





//char* GenerateQRcode(const char* text)
//{
//	GenerateQRcode(text , 2);
//}
