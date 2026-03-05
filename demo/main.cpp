#include "QRcreator.h"

int main()
{
	int version  = 3;
	QRMatrix mTemp = GenerateQRcode("https://github.com/YorktownLaogou/QRCode-Creator" , 0);


	for (size_t y = 0; y < QRSpec::GetQRSide(version); y++)
	{
		for (size_t x = 0; x < QRSpec::GetQRSide(version); x++)
		{
			if(mTemp.GetPixel(x,y) == 0)
			{ 
				printf("■");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}

	return 0;
}