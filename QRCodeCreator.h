#pragma once
#include<stdlib.h>





/************************************************************/
/*															*/
/*	QR fixed parameter										*/
/*	Used for quick calculations by looking up tables		*/
/*															*/
/************************************************************/


const int SideOfVersion[] = {21, 25, 29, 33, 37, 41, 45, 49, 53, 57, 61, 65, 69, 73, 77, 81, 85, 89, 93, 97, 101, 105, 109, 113, 117, 121, 125, 129, 133, 137, 141, 145, 149, 153, 157, 161, 165, 169, 173, 177};
const int SizeOfVersion[] = {441, 625, 841, 1089, 1369, 1681, 2025, 2401, 2809, 3249, 3721, 4225, 4761, 5329, 5929, 6561, 7225, 7921, 8649, 9409, 10201, 11025, 11881, 12769, 13689, 14641, 15625, 16641, 17689, 18769, 19881, 21025, 22201, 23409, 24649, 25921, 27225, 28561, 29929, 31329};
const int FinalMessageCodewordsLenList[40] = { 26,44,70,100,134,172,196,242,292,346,404,466,532,581,655,733,815,901,991,1085,1156,1258,1364,1474,1588,1706,1828,1921,2051,2185,2323,2465,2611,2761,2876,3034,3196,3362,3532,3706 };
const int AlignmentPatternPositionsList[40][8] = 
{
    {{0},	{0},    {0},    {0},    {0},    {0},    {0},    {0}},		// 版本 1: 无对齐图案
    {{2},	{6},    {18},   {0},    {0},    {0},    {0},    {0}},		// 版本 2
    {{2},	{6},    {22},   {0},    {0},    {0},    {0},    {0}},		// 版本 3
    {{2},	{6},    {26},   {0},    {0},    {0},    {0},    {0}},		// 版本 4
    {{2},	{6},    {30},   {0},    {0},    {0},    {0},    {0}},		// 版本 5
    {{2},	{6},    {34},   {0},    {0},    {0},    {0},    {0}},		// 版本 6
    {{3},	{6},    {22},   {38},   {0},    {0},    {0},    {0}},		// 版本 7
    {{3},	{6},    {24},   {42},   {0},    {0},    {0},    {0}},		// 版本 8
    {{3},	{6},    {26},   {46},   {0},    {0},    {0},    {0}},		// 版本 9
    {{3},	{6},    {28},   {50},   {0},    {0},    {0},    {0}},		// 版本 10
    {{3},	{6},    {30},   {54},   {0},    {0},    {0},    {0}},		// 版本 11
    {{3},	{6},    {32},   {58},   {0},    {0},    {0},    {0}},		// 版本 12
    {{3},	{6},    {34},   {62},   {0},    {0},    {0},    {0}},		// 版本 13
    {{4},	{6},    {26},   {46},   {66},   {0},    {0},    {0}},		// 版本 14
    {{4},	{6},    {26},   {48},   {70},   {0},    {0},    {0}},		// 版本 15
    {{4},	{6},    {26},   {50},   {74},   {0},    {0},    {0}},		// 版本 16
    {{4},	{6},    {30},   {54},   {78},   {0},    {0},    {0}},		// 版本 17
    {{4},	{6},    {30},   {56},   {82},   {0},    {0},    {0}},		// 版本 18
    {{4},	{6},    {30},   {58},   {86},   {0},    {0},    {0}},		// 版本 19
    {{4},	{6},    {34},   {62},   {90},   {0},    {0},    {0}},		// 版本 20
    {{5},	{6},    {28},   {50},   {72},   {94},   {0},    {0}},		// 版本 21
    {{5},	{6},    {26},   {50},   {74},   {98},   {0},    {0}},		// 版本 22
    {{5},	{6},    {30},   {54},   {78},   {102},  {0},    {0}},		// 版本 23
    {{5},	{6},    {28},   {54},   {80},   {106},  {0},    {0}},		// 版本 24
    {{5},	{6},    {32},   {58},   {84},   {110},  {0},    {0}},		// 版本 25
    {{5},	{6},    {30},   {58},   {86},   {114},  {0},    {0}},		// 版本 26
    {{5},	{6},    {34},   {62},   {90},   {118},  {0},    {0}},		// 版本 27
    {{6},	{6},    {26},   {50},   {74},   {98},   {122},  {0}},		// 版本 28
    {{6},	{6},    {30},   {54},   {78},   {102},  {126},  {0}},		// 版本 29
    {{6},	{6},    {26},   {52},   {78},   {104},  {130},  {0}},		// 版本 30
    {{6},	{6},    {30},   {56},   {82},   {108},  {134},  {0}},		// 版本 31
    {{6},	{6},    {34},   {60},   {86},   {112},  {138},  {0}},		// 版本 32
    {{6},	{6},    {30},   {58},   {86},   {114},  {142},  {0}},		// 版本 33
    {{6},	{6},    {34},   {62},   {90},   {118},  {146},  {0}},		// 版本 34
    {{7},	{6},    {30},   {54},   {78},   {102},  {126},  {150}},		// 版本 35
    {{7},	{6},    {24},   {50},   {76},   {102},  {128},  {154}},		// 版本 36
    {{7},	{6},    {28},   {54},   {80},   {106},  {132},  {158}},		// 版本 37
    {{7},	{6},    {32},   {58},   {84},   {110},  {136},  {162}},		// 版本 38
    {{7},	{6},    {26},   {54},   {82},   {110},  {138},  {166}},		// 版本 39
    {{7},	{6},    {30},   {58},   {86},   {114},  {142},  {170}}		// 版本 40
};
const int QRcodeVersionCapacityData[40][4] =
{
	{  17,  14,  11,   7},	// Lv  1
	{  32,  26,  20,  14},
	{  53,  42,  32,  24},
	{  78,  62,  46,  34},
	{ 106,  84,  60,  44},
	{ 134, 106,  74,  58},	// Lv  6
	{ 154, 122,  86,  64},
	{ 192, 152, 108,  84},
	{ 230, 180, 130,  98},
	{ 271, 213, 151, 119},
	{ 321, 251, 177, 137},	// Lv 11
	{ 367, 287, 203, 155},
	{ 425, 331, 241, 177},
	{ 458, 362, 258, 194},
	{ 520, 412, 292, 220},
	{ 586, 450, 322, 250},	// Lv 16
	{ 644, 504, 364, 280},
	{ 718, 560, 394, 310},
	{ 792, 624, 442, 338},
	{ 858, 666, 482, 382},
	{ 929, 711, 509, 403},	// Lv 21
	{1003, 779, 565, 439},
	{1091, 857, 611, 461},
	{1171, 911, 661, 511},
	{1273, 997, 715, 535},
	{1367,1059, 751, 593},	// Lv 26
	{1465,1125, 805, 625},
	{1528,1190, 868, 658},
	{1628,1264, 908, 698},
	{1732,1370, 982, 742},
	{1840,1452,1030, 790},	// Lv 31
	{1952,1538,1112, 842},
	{2068,1628,1168, 898},
	{2188,1722,1228, 958},
	{2303,1809,1283, 983},
	{2431,1911,1351,1051},	// Lv 36
	{2563,1989,1423,1093},
	{2699,2099,1499,1139},
	{2809,2213,1579,1219},
	{2953,2331,1663,1273}
};
const int DataCodewordsLenList[40][4] =
{
	{   19,    16,    13,     9 },   // 1
	{   34,    28,    22,    16 },   // 2
	{   55,    44,    34,    26 },   // 3
	{   80,    64,    48,    36 },   // 4
	{  108,    86,    62,    46 },   // 5
	{  136,   108,    76,    60 },   // 6
	{  156,   124,    88,    66 },   // 7
	{  194,   154,   110,    86 },   // 8
	{  232,   182,   132,   100 },   // 9
	{  274,   216,   154,   122 },   // 10
	{  324,   254,   180,   140 },   // 11
	{  370,   290,   206,   158 },   // 12
	{  428,   334,   244,   180 },   // 13
	{  461,   365,   261,   197 },   // 14
	{  523,   415,   295,   223 },   // 15
	{  589,   453,   325,   253 },   // 16
	{  647,   507,   367,   283 },   // 17
	{  721,   563,   397,   313 },   // 18
	{  795,   627,   445,   341 },   // 19
	{  861,   669,   485,   385 },   // 20
	{  932,   714,   512,   406 },   // 21
	{ 1006,   782,   568,   442 },   // 22
	{ 1094,   860,   614,   464 },   // 23
	{ 1174,   914,   664,   514 },   // 24
	{ 1276,  1000,   718,   538 },   // 25
	{ 1370,  1062,   754,   596 },   // 26
	{ 1468,  1128,   808,   628 },   // 27
	{ 1531,  1193,   871,   661 },   // 28
	{ 1631,  1267,   911,   701 },   // 29
	{ 1735,  1373,   985,   745 },   // 30
	{ 1843,  1455,  1033,   793 },   // 31
	{ 1955,  1541,  1115,   845 },   // 32
	{ 2071,  1631,  1171,   901 },   // 33
	{ 2191,  1725,  1231,   961 },   // 34
	{ 2306,  1812,  1286,	986 },   // 35
	{ 2434,  1914,  1354,  1054 },   // 36
	{ 2566,  1992,  1426,  1096 },   // 37
	{ 2702,  2102,  1502,  1142 },   // 38
	{ 2812,  2216,  1582,  1222 },   // 39
	{ 2956,  2334,  1666,  1276 }    // 40
};
const int CharacterCountIndicatorLengthList[40][4] = 
{
	{10,	9,		8,		8},		// Lv1
	{10,	9,		8,		8},
	{10,	9,		8,		8},
	{10,	9,		8,		8}, 
	{10,	9,		8,		8},
	{10,	9,		8,		8},		// Lv6
	{10,	9,		8,		8},
	{10,	9,		8,		8},
	{10,	9,		8,		8},
	{12,	11,		16,		10},
	{12,	11,		16,		10},	// Lv11
	{12,	11,		16,		10},
	{12,	11,		16,		10},
	{12,	11,		16,		10},
	{12,	11,		16,		10},
	{12,	11,		16,		10},	// Lv16
	{12,	11,		16,		10},
	{12,	11,		16,		10},
	{12,	11,		16,		10},
	{12,	11,		16,		10},
	{12,	11,		16,		10},	//	Lv21
	{12,	11,		16,		10},
	{12,	11,		16,		10},
	{12,	11,		16,		10},
	{12,	11,		16,		10},
	{12,	11,		16,		10},	// Lv26
	{14,	13,		16,		12},
	{14,	13,		16,		12},
	{14,	13,		16,		12},
	{14,	13,		16,		12},
	{14,	13,		16,		12},	// Lv31
	{14,	13,		16,		12},
	{14,	13,		16,		12},
	{14,	13,		16,		12},
	{14,	13,		16,		12},
	{14,	13,		16,		12},	// Lv36
	{14,	13,		16,		12},
	{14,	13,		16,		12},
	{14,	13,		16,		12},
	{14,	13,		16,		12}
};
const int CodewordSplittingData[40][4][5] =
{					
	{{  7,  1, 19,  0,  0},{ 10,  1, 16,  0,  0},{ 13,  1, 13,  0,  0},{ 17,  1,  9,  0,  0}},	// Lv  1
	{{ 10,  1, 34,  0,  0},{ 16,  1, 28,  0,  0},{ 22,  1, 22,  0,  0},{ 28,  1, 16,  0,  0}},
	{{ 15,  1, 55,  0,  0},{ 26,  1, 44,  0,  0},{ 18,  2, 17,  0,  0},{ 22,  2, 13,  0,  0}},
	{{ 20,  1, 80,  0,  0},{ 18,  2, 32,  0,  0},{ 26,  2, 24,  0,  0},{ 16,  4,  9,  0,  0}},
	{{ 26,  1,108,  0,  0},{ 24,  2, 43,  0,  0},{ 18,  2, 15,  2, 16},{ 22,  2, 11,  2, 12}},
	{{ 18,  2, 68,  0,  0},{ 16,  4, 27,  0,  0},{ 24,  4, 19,  0,  0},{ 28,  4, 15,  0,  0}},	// Lv  6
	{{ 20,  2, 78,  0,  0},{ 18,  4, 31,  0,  0},{ 18,  2, 14,  4, 15},{ 26,  4, 13,  1, 14}},
	{{ 24,  2, 97,  0,  0},{ 22,  2, 38,  2, 39},{ 22,  2, 38,  2, 39},{ 22,  4, 14,  2, 15}},
	{{ 30,  2,116,  0,  0},{ 22,  3, 36,  2, 37},{ 20,  4, 16,  4, 17},{ 24,  4, 12,  4, 13}},
	{{ 18,  2, 68,  2, 69},{ 26,  4, 43,  1, 44},{ 24,  6, 19,  2, 20},{ 28,  6, 15,  2, 16}},
	{{ 20,  4, 81,  0,  0},{ 30,  1, 50,  4, 51},{ 28,  4, 22,  4, 23},{ 24,  3, 12,  8, 13}},	// Lv 11
	{{ 24,  2, 92,  2, 93},{ 22,  6, 36,  2, 37},{ 26,  4, 20,  6, 21},{ 28,  7, 14,  4, 15}},
	{{ 26,  4,107,  0,  0},{ 22,  8, 37,  1, 38},{ 24,  8, 20,  4, 21},{ 22, 12, 11,  4, 12}},
	{{ 30,  3,115,  1,116},{ 24,  4, 40,  5, 41},{ 20, 11, 16,  5, 17},{ 24, 11, 12,  5, 13}},
	{{ 22,  5, 87,  1, 88},{ 24,  5, 41,  5, 42},{ 30,  5, 24,  7, 25},{ 24, 11, 12,  7, 13}},
	{{ 24,  5, 98,  1, 99},{ 28,  7, 45,  3, 46},{ 24, 15, 19,  2, 20},{ 30,  3, 15, 13, 16}},	// Lv 16
	{{ 28,  1,107,  5,108},{ 28, 10, 46,  1, 47},{ 28,  1, 22, 15, 23},{ 28,  2, 14, 17, 15}},
	{{ 30,  5,120,  1,121},{ 26,  9, 43,  4, 44},{ 28, 17, 22,  1, 23},{ 28,  2, 14, 19, 15}},
	{{ 28,  3,113,  4,114},{ 26,  3, 44, 11, 45},{ 26, 17, 21,  4, 22},{ 26,  9, 13, 16, 14}},
	{{ 28,  3,107,  5,108},{ 26,  3, 41, 13, 42},{ 30, 15, 24,  5, 25},{ 28, 15, 15, 10, 16}},
	{{ 28,  4,116,  4,117},{ 26, 17, 42,  0,  0},{ 28, 17, 22,  6, 23},{ 30, 19, 16,  6, 17}},	// Lv 21
	{{ 28,  2,111,  7,112},{ 28, 17, 46,  0,  0},{ 30,  7, 24, 16, 25},{ 24, 34, 13,  0,  0}},
	{{ 30,  4,121,  5,122},{ 28,  4, 47, 14, 48},{ 30, 11, 24, 14, 25},{ 30, 16, 15, 14, 16}},
	{{ 30,  6,117,  4,118},{ 28,  6, 45, 14, 46},{ 30, 11, 24, 16, 25},{ 30, 11, 24, 16, 25}},
	{{ 26,  8,106,  4,107},{ 28,  8, 47, 13, 48},{ 30,  7, 24, 22, 25},{ 30, 22, 15, 13, 16}},
	{{ 28, 10,114,  2,115},{ 28, 19, 46,  4, 47},{ 28, 28, 22,  6, 23},{ 30, 33, 16,  4, 17}},	// Lv 26
	{{ 30,  8,122,  4,123},{ 28, 22, 45,  3, 46},{ 30,  8, 23, 26, 24},{ 30, 12, 15, 28, 16}},
	{{ 30,  3,117, 10,118},{ 28,  3, 45, 23, 46},{ 30,  4, 24, 31, 25},{ 30, 11, 15, 31, 16}},
	{{ 30,  7,116,  7,117},{ 28, 21, 45,  7, 46},{ 30,  1, 23, 37, 24},{ 30, 19, 15, 26, 16}},
	{{ 30,  5,115, 10,116},{ 28, 19, 47, 10, 48},{ 30, 15, 24, 25, 25},{ 30, 23, 15, 25, 16}},
	{{ 30, 13,115,  3,116},{ 28,  2, 46, 29, 47},{ 30, 42, 24,  1, 25},{ 30, 23, 15, 28, 16}},	// Lv 31
	{{ 30, 17,115,  0,  0},{ 28, 10, 46, 23, 47},{ 30, 10, 24, 35, 25},{ 30, 19, 15, 35, 16}},
	{{ 30, 17,115,  1,116},{ 28, 14, 46, 21, 47},{ 30, 29, 24, 19, 25},{ 30, 11, 15, 46, 16}},
	{{ 30, 13,115,  6,116},{ 28, 14, 46, 23, 47},{ 30, 44, 24,  7, 25},{ 30, 59, 16,  1, 17}},
	{{ 30, 12,121,  7,122},{ 28, 12, 47, 26, 48},{ 30, 39, 24, 14, 25},{ 30, 22, 15, 41, 16}},
	{{ 30,  6,121, 14,122},{ 28,  6, 47, 34, 48},{ 30, 46, 24, 10, 25},{ 30,  2, 15, 64, 16}},	// Lv 36
	{{ 30, 17,122,  4,123},{ 28, 29, 46, 14, 47},{ 30, 49, 24, 10, 25},{ 30, 24, 15, 46, 16}},
	{{ 30,  4,122, 18,123},{ 28, 13, 46, 32, 47},{ 30, 48, 24, 14, 25},{ 30, 42, 15, 32, 16}},
	{{ 30, 20,117,  4,118},{ 28, 40, 47,  7, 48},{ 30, 43, 24, 22, 25},{ 30, 10, 15, 67, 16}},
	{{ 30, 19,118,  6,119},{ 28, 18, 47, 31, 48},{ 30, 34, 24, 34, 25},{ 30, 20, 15, 61, 16}}
};
const char VersionInformationBitStream[40][18] =
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	// Lv  1
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	// Lv  6
	{0,0,0,1,1,1,1,1,0,0,1,0,0,1,0,1,0,0},
	{0,0,1,0,0,0,0,1,0,1,1,0,1,1,1,1,0,0},
	{0,0,1,0,0,1,1,0,1,0,1,0,0,1,1,0,0,1},
	{0,0,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,1},
	{0,0,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,0},	// Lv 11
	{0,0,1,1,0,0,0,1,1,1,0,1,1,0,0,0,1,0},
	{0,0,1,1,0,1,1,0,0,0,0,1,0,0,0,1,1,1},
	{0,0,1,1,1,0,0,1,1,0,0,0,0,0,1,1,0,1},
	{0,0,1,1,1,1,1,0,0,1,0,0,1,0,1,0,0,0},
	{0,1,0,0,0,0,1,0,1,1,0,1,1,1,1,0,0,0},	// Lv 16
	{0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,0,1},
	{0,1,0,0,1,0,1,0,1,0,0,0,0,1,0,1,1,1},
	{0,1,0,0,1,1,0,1,0,1,0,0,1,1,0,0,1,0},
	{0,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,1,0},
	{0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,0,1,1},	// Lv 21
	{0,1,0,1,1,0,1,0,0,0,1,1,0,0,1,0,0,1},
	{0,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,0,0},
	{0,1,1,0,0,0,1,1,1,0,1,1,0,0,0,1,0,0},
	{0,1,1,0,0,1,0,0,0,1,1,1,1,0,0,0,0,1},
	{0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1},	// Lv 26
	{0,1,1,0,1,1,0,0,0,0,1,0,0,0,1,1,1,0},
	{0,1,1,1,0,0,1,1,0,0,0,0,0,1,1,0,1,0},
	{0,1,1,1,0,1,0,0,1,1,0,0,1,1,1,1,1,1},
	{0,1,1,1,1,0,1,1,0,1,0,1,1,1,0,1,0,1},
	{0,1,1,1,1,1,0,0,1,0,0,1,0,1,0,0,0,0},	// Lv 31
	{1,0,0,0,0,0,1,0,0,1,1,1,0,1,0,1,0,1},
	{1,0,0,0,0,1,0,1,1,0,1,1,1,1,0,0,0,0},
	{1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,0,1,0},
	{1,0,0,0,1,1,0,1,1,1,1,0,0,1,1,1,1,1},
	{1,0,0,1,0,0,1,0,1,1,0,0,0,0,1,0,1,1},	// Lv 36
	{1,0,0,1,0,1,0,1,0,0,0,0,1,0,1,1,1,0},
	{1,0,0,1,1,0,1,0,1,0,0,1,1,0,0,1,0,0},
	{1,0,0,1,1,1,0,1,0,1,0,1,0,0,0,0,0,1},
	{1,0,1,0,0,0,1,1,0,0,0,1,1,0,1,0,0,1},
};
const char formatInfoAfterMasking[4][8][15] =
{
	{
		{1,1,1,0,1,1,1,1,1,0,0,0,1,0,0},
		{1,1,1,0,0,1,0,1,1,1,1,0,0,1,1}, 
		{1,1,1,1,1,0,1,1,0,1,0,1,0,1,0},
		{1,1,1,1,0,0,0,1,0,0,1,1,1,0,1},
		{1,1,0,0,1,1,0,0,0,1,0,1,1,1,1},
		{1,1,0,0,0,1,1,0,0,0,1,1,0,0,0},
		{1,1,0,1,1,0,0,0,1,0,0,0,0,0,1},
		{1,1,0,1,0,0,1,0,1,1,1,0,1,1,0}
	},
	{
		{1,0,1,0,1,0,0,0,0,0,1,0,0,1,0},
		{1,0,1,0,0,0,0,1,0,0,1,0,0,1,0},
		{1,0,1,1,1,1,0,0,1,1,1,1,1,0,0},
		{1,0,1,1,0,1,1,0,1,0,0,1,0,1,1},
		{1,0,0,0,1,0,1,1,1,1,1,1,0,0,1},
		{1,0,0,0,0,0,0,1,1,0,0,0,1,1,0},
		{1,0,0,1,1,1,1,1,0,0,1,0,1,1,1},
		{1,0,0,1,0,1,0,1,0,1,0,0,0,0,0}
	},
	{
		{0,1,1,0,1,0,1,0,1,0,1,1,1,1,1},
		{0,1,1,0,0,0,0,0,1,1,0,1,0,0,0},
		{0,1,1,1,1,1,1,0,0,1,1,0,0,0,1},
		{0,1,1,1,0,1,0,0,0,0,0,0,1,1,0},
		{0,1,0,0,1,0,0,1,0,1,1,0,1,0,0},
		{0,1,0,0,0,0,0,1,1,0,0,0,0,1,1},
		{0,1,0,1,1,1,0,1,1,0,1,1,0,1,0},
		{0,1,0,1,0,1,1,1,1,1,0,1,1,0,1}
	},
	{
		{0,0,1,0,1,1,0,1,0,0,0,0,1,0,0},
		{0,0,1,0,0,1,1,1,0,1,1,1,1,1,0},
		{0,0,1,1,1,0,0,1,1,1,0,0,1,1,1},
		{0,0,1,1,0,0,1,1,1,0,1,0,0,0,0},
		{0,0,0,0,1,1,1,0,1,1,0,0,0,1,0},
		{0,0,0,0,0,1,0,0,1,0,1,0,1,0,1},
		{0,0,0,1,1,0,1,0,0,0,0,1,1,0,0},
		{0,0,0,1,0,0,0,0,0,1,1,1,0,1,1}
	}
};
char PaddingBytes[]={0xEC, 0x11, 0xEC, 0x11, 0xEC, 0x11, 0xEC, 0x11, 0xEC, 0x11, 0xEC, 0x11, 0xEC, 0x11, 0xEC, 0x11, 0xEC, 0x11, 0xEC,  0x11, 0xEC, 0x11, 0xEC, 0x11, 0xEC, 0x11, 0xEC, 0x11, 0xEC, 0x11};





/************************************************************/
/* 															*/
/*	Galileo Domain Computing Section						*/
/*	In ISO/IEC 18004 v8.9, the first byte char[0] is the coefficient of the highest-order term
/*	In calculation functions, char[0] is used as the lowest-order term to facilitate elimination from the highest-order term
/*	char[0] is the highest-order term only in the entry function; everywhere else in this file, char[0] is treated as the lowest-order term
/* 															*/
/************************************************************/

/*--------------- Fast Calculation Table --------------*/
const uint8_t GF256ForQrcode_LogList[256] =
{
	0x00,0x00,0x01,0x19,0x02,0x32,0x1A,0xC6,   0x03,0xDF,0x33,0xEE,0x1B,0x68,0xC7,0x4B,
	0x04,0x64,0xE0,0x0E,0x34,0x8D,0xEF,0x81,   0x1C,0xC1,0x69,0xF8,0xC8,0x08,0x4C,0x71,
	0x05,0x8A,0x65,0x2F,0xE1,0x24,0x0F,0x21,   0x35,0x93,0x8E,0xDA,0xF0,0x12,0x82,0x45,
	0x1D,0xB5,0xC2,0x7D,0x6A,0x27,0xF9,0xB9,   0xC9,0x9A,0x09,0x78,0x4D,0xE4,0x72,0xA6,
	0x06,0xBF,0x8B,0x62,0x66,0xDD,0x30,0xFD,   0xE2,0x98,0x25,0xB3,0x10,0x91,0x22,0x88,
	0x36,0xD0,0x94,0xCE,0x8F,0x96,0xDB,0xBD,   0xF1,0xD2,0x13,0x5C,0x83,0x38,0x46,0x40,
	0x1E,0x42,0xB6,0xA3,0xC3,0x48,0x7E,0x6E,   0x6B,0x3A,0x28,0x54,0xFA,0x85,0xBA,0x3D,
	0xCA,0x5E,0x9B,0x9F,0x0A,0x15,0x79,0x2B,   0x4E,0xD4,0xE5,0xAC,0x73,0xF3,0xA7,0x57,
	0x07,0x70,0xC0,0xF7,0x8C,0x80,0x63,0x0D,   0x67,0x4A,0xDE,0xED,0x31,0xC5,0xFE,0x18,
	0xE3,0xA5,0x99,0x77,0x26,0xB8,0xB4,0x7C,   0x11,0x44,0x92,0xD9,0x23,0x20,0x89,0x2E,
	0x37,0x3F,0xD1,0x5B,0x95,0xBC,0xCF,0xCD,   0x90,0x87,0x97,0xB2,0xDC,0xFC,0xBE,0x61,
	0xF2,0x56,0xD3,0xAB,0x14,0x2A,0x5D,0x9E,   0x84,0x3C,0x39,0x53,0x47,0x6D,0x41,0xA2,
	0x1F,0x2D,0x43,0xD8,0xB7,0x7B,0xA4,0x76,   0xC4,0x17,0x49,0xEC,0x7F,0x0C,0x6F,0xF6,
	0x6C,0xA1,0x3B,0x52,0x29,0x9D,0x55,0xAA,   0xFB,0x60,0x86,0xB1,0xBB,0xCC,0x3E,0x5A,
	0xCB,0x59,0x5F,0xB0,0x9C,0xA9,0xA0,0x51,   0x0B,0xF5,0x16,0xEB,0x7A,0x75,0x2C,0xD7,
	0x4F,0xAE,0xD5,0xE9,0xE6,0xE7,0xAD,0xE8,   0x74,0xD6,0xF4,0xEA,0xA8,0x50,0x58,0xAF,
};
const uint8_t GF256ForQrcode_AntiLogList[512] =
{
	0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,	0x1D,0x3A,0x74,0xE8,0xCD,0x87,0x13,0x26,
	0x4C,0x98,0x2D,0x5A,0xB4,0x75,0xEA,0xC9,	0x8F,0x03,0x06,0x0C,0x18,0x30,0x60,0xC0,
	0x9D,0x27,0x4E,0x9C,0x25,0x4A,0x94,0x35,	0x6A,0xD4,0xB5,0x77,0xEE,0xC1,0x9F,0x23,
	0x46,0x8C,0x05,0x0A,0x14,0x28,0x50,0xA0,	0x5D,0xBA,0x69,0xD2,0xB9,0x6F,0xDE,0xA1,
	0x5F,0xBE,0x61,0xC2,0x99,0x2F,0x5E,0xBC,	0x65,0xCA,0x89,0x0F,0x1E,0x3C,0x78,0xF0,
	0xFD,0xE7,0xD3,0xBB,0x6B,0xD6,0xB1,0x7F,	0xFE,0xE1,0xDF,0xA3,0x5B,0xB6,0x71,0xE2,
	0xD9,0xAF,0x43,0x86,0x11,0x22,0x44,0x88,	0x0D,0x1A,0x34,0x68,0xD0,0xBD,0x67,0xCE,
	0x81,0x1F,0x3E,0x7C,0xF8,0xED,0xC7,0x93,	0x3B,0x76,0xEC,0xC5,0x97,0x33,0x66,0xCC,
	0x85,0x17,0x2E,0x5C,0xB8,0x6D,0xDA,0xA9,	0x4F,0x9E,0x21,0x42,0x84,0x15,0x2A,0x54,
	0xA8,0x4D,0x9A,0x29,0x52,0xA4,0x55,0xAA,	0x49,0x92,0x39,0x72,0xE4,0xD5,0xB7,0x73,
	0xE6,0xD1,0xBF,0x63,0xC6,0x91,0x3F,0x7E,	0xFC,0xE5,0xD7,0xB3,0x7B,0xF6,0xF1,0xFF,
	0xE3,0xDB,0xAB,0x4B,0x96,0x31,0x62,0xC4,	0x95,0x37,0x6E,0xDC,0xA5,0x57,0xAE,0x41,
	0x82,0x19,0x32,0x64,0xC8,0x8D,0x07,0x0E,	0x1C,0x38,0x70,0xE0,0xDD,0xA7,0x53,0xA6,
	0x51,0xA2,0x59,0xB2,0x79,0xF2,0xF9,0xEF,	0xC3,0x9B,0x2B,0x56,0xAC,0x45,0x8A,0x09,
	0x12,0x24,0x48,0x90,0x3D,0x7A,0xF4,0xF5,	0xF7,0xF3,0xFB,0xEB,0xCB,0x8B,0x0B,0x16,
	0x2C,0x58,0xB0,0x7D,0xFA,0xE9,0xCF,0x83,	0x1B,0x36,0x6C,0xD8,0xAD,0x47,0x8E,

	0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,	0x1D,0x3A,0x74,0xE8,0xCD,0x87,0x13,0x26,
	0x4C,0x98,0x2D,0x5A,0xB4,0x75,0xEA,0xC9,	0x8F,0x03,0x06,0x0C,0x18,0x30,0x60,0xC0,
	0x9D,0x27,0x4E,0x9C,0x25,0x4A,0x94,0x35,	0x6A,0xD4,0xB5,0x77,0xEE,0xC1,0x9F,0x23,
	0x46,0x8C,0x05,0x0A,0x14,0x28,0x50,0xA0,	0x5D,0xBA,0x69,0xD2,0xB9,0x6F,0xDE,0xA1,
	0x5F,0xBE,0x61,0xC2,0x99,0x2F,0x5E,0xBC,	0x65,0xCA,0x89,0x0F,0x1E,0x3C,0x78,0xF0,
	0xFD,0xE7,0xD3,0xBB,0x6B,0xD6,0xB1,0x7F,	0xFE,0xE1,0xDF,0xA3,0x5B,0xB6,0x71,0xE2,
	0xD9,0xAF,0x43,0x86,0x11,0x22,0x44,0x88,	0x0D,0x1A,0x34,0x68,0xD0,0xBD,0x67,0xCE,
	0x81,0x1F,0x3E,0x7C,0xF8,0xED,0xC7,0x93,	0x3B,0x76,0xEC,0xC5,0x97,0x33,0x66,0xCC,
	0x85,0x17,0x2E,0x5C,0xB8,0x6D,0xDA,0xA9,	0x4F,0x9E,0x21,0x42,0x84,0x15,0x2A,0x54,
	0xA8,0x4D,0x9A,0x29,0x52,0xA4,0x55,0xAA,	0x49,0x92,0x39,0x72,0xE4,0xD5,0xB7,0x73,
	0xE6,0xD1,0xBF,0x63,0xC6,0x91,0x3F,0x7E,	0xFC,0xE5,0xD7,0xB3,0x7B,0xF6,0xF1,0xFF,
	0xE3,0xDB,0xAB,0x4B,0x96,0x31,0x62,0xC4,	0x95,0x37,0x6E,0xDC,0xA5,0x57,0xAE,0x41,
	0x82,0x19,0x32,0x64,0xC8,0x8D,0x07,0x0E,	0x1C,0x38,0x70,0xE0,0xDD,0xA7,0x53,0xA6,
	0x51,0xA2,0x59,0xB2,0x79,0xF2,0xF9,0xEF,	0xC3,0x9B,0x2B,0x56,0xAC,0x45,0x8A,0x09,
	0x12,0x24,0x48,0x90,0x3D,0x7A,0xF4,0xF5,	0xF7,0xF3,0xFB,0xEB,0xCB,0x8B,0x0B,0x16,
	0x2C,0x58,0xB0,0x7D,0xFA,0xE9,0xCF,0x83,	0x1B,0x36,0x6C,0xD8,0xAD,0x47,0x8E,

	0x01,0x02
};

/*--------------- Generating polynomial ---------------*/
uint8_t EC_02_codewords[] = { 0x02, 0x03, 0x01 };
uint8_t EC_07_codewords[] = { 0x75, 0x44, 0x0B, 0xA4, 0x9A, 0x7A, 0x7F, 0x01 };
uint8_t EC_10_codewords[] = { 0xC1, 0x9D, 0x71, 0x5F, 0x5E, 0xC7, 0x6F, 0x9F, 0xC2, 0xD8, 0x01 };
uint8_t EC_16_codewords[] = { 0x3B, 0x24, 0x32, 0x62, 0xE5, 0x29, 0x41, 0xA3, 0x08, 0x1E, 0xD1, 0x44, 0xBD, 0x68, 0x0D, 0x3B, 0x01 };
uint8_t EC_22_codewords[] = { 0xF5, 0x91, 0x1A, 0xE6, 0xDA, 0x56, 0xFD, 0x43, 0x7B, 0x1D, 0x89, 0x1C, 0x28, 0x45, 0xBD, 0x13, 0xF4, 0xB6, 0xB0, 0x83, 0xB3, 0x59, 0x01 };
uint8_t* pGeneratorPolynomial[] =
{
	nullptr, nullptr,
	EC_02_codewords,
	nullptr, nullptr, nullptr, nullptr,
	EC_07_codewords,
	nullptr, nullptr,
	EC_10_codewords,
	nullptr, nullptr, nullptr, nullptr, nullptr,
	EC_16_codewords,
	nullptr, nullptr, nullptr, nullptr, nullptr,
	EC_22_codewords
};


/*----------------- Basic operations ------------------*/
inline uint8_t GFforQR_Multiplicative(uint8_t A, uint8_t B)
{
	if (A == 0 || B == 0) return 0;
	return GF256ForQrcode_AntiLogList[GF256ForQrcode_LogList[A] + GF256ForQrcode_LogList[B]];
}
inline uint8_t GFforQR_Minus(uint8_t A, uint8_t B)
{
	return A ^ B;
}
inline uint8_t GFforQR_Pow(int A)
{
	return(GF256ForQrcode_AntiLogList[A % 255]);
}


/*-------------------- Long Division ------------------*/
uint8_t* GFforQR_Modulo(uint8_t* pDividend, int TotalItemsLen, int iECCLen)
{
	// 临时中转被除数 和 商项 以及 计算过程中的临时多项式
	uint8_t* pDividendBuffer = new uint8_t[TotalItemsLen];
	memcpy(pDividendBuffer, pDividend, TotalItemsLen);
	int GBufferLen = TotalItemsLen;
	uint8_t QuotientItem;
	int QuotientTermDegree;
	uint8_t* cTempPolynomial = new uint8_t[TotalItemsLen];

	// 循环消元 直到 中转被除数 等于 ECC长度 这就是ECCcode
	while (GBufferLen > iECCLen)
	{
		// 计算商项 生成多项式最高位固定为 0x01 商就是中转最高项
		QuotientItem = pDividendBuffer[GBufferLen - 1];
		QuotientTermDegree = (GBufferLen - 1) - iECCLen;

		// 生成多项式 * 商项
		memset(cTempPolynomial, 0, GBufferLen);
		for (int i = 0; i < iECCLen + 1; i++)
		{
			cTempPolynomial[i + QuotientTermDegree] = GFforQR_Multiplicative(pGeneratorPolynomial[iECCLen][i], QuotientItem);
		}

		// 原来的中转 减 上面的 得到 新的中转
		for (int i = 0; i < GBufferLen; i++)
		{
			pDividendBuffer[i] = GFforQR_Minus(pDividendBuffer[i], cTempPolynomial[i]);
		}

		// 每一次循环 最高次项一定被消掉
		while (GBufferLen > 0 && pDividendBuffer[GBufferLen - 1] == 0) GBufferLen--;
	}

	// 构造新输出实例 中转前面几个就是余数 (这个内存在外面释放)
	uint8_t* pOutput = new uint8_t[iECCLen];
	memcpy(pOutput, pDividendBuffer, iECCLen);

	// 清理
	delete[] pDividendBuffer;
	delete[] cTempPolynomial;

	// 返回
	return pOutput;
}


/*------------------ Generate ECC code ----------------*/
int _GenerateECC(char* pDataBlock, int iBlockLen, int iECCLen)
{
	// 制作传入函数的实例 需要反向
	int pDataBlockLen = iBlockLen + iECCLen;
	char* pDividend = new char[pDataBlockLen];
	for (int i = 0; i < pDataBlockLen; i++) pDividend[i] = pDataBlock[pDataBlockLen - i - 1];

	// 计算CEE
	char* pECC = (char*)GFforQR_Modulo((uint8_t*)pDividend, pDataBlockLen, iECCLen);
	delete[] pDividend;

	// 反向写回
	for (int i = 0; i < iECCLen; i++)pDataBlock[iBlockLen + i] = pECC[iECCLen - i - 1];
	delete[] pECC;


	return 1;
};





/************************************************************/
/* 															*/
/*	Creator section											*/
/*	According to ISO/IEC 18004 standards					*/
/* 															*/
/************************************************************/


/*---------------------- bit写入 ----------------------*/
void BitWrite(void* pTarget, void* pSource, int iBegin, int iLength)
{
	unsigned char* target = static_cast<uint8_t*>(pTarget);
	unsigned char* source = static_cast<uint8_t*>(pSource);
	int Counter = iLength;

	for (int i = 0; i < iLength; i++)
	{
		// 计算 source 中第 i 位
		int srcByte = i / 8;
		int srcBit = 7 - (i % 8);
		bool bit = (source[srcByte] >> srcBit) & 1;

		// 写入到 target 的 (iBegin + i)
		int dstIndex = iBegin + i;
		int dstByte = dstIndex / 8;
		int dstBit = 7 - (dstIndex % 8);

		if (bit)
			target[dstByte] |= (1 << dstBit);
		else
			target[dstByte] &= ~(1 << dstBit);
	}
}


/*------------------- 判断模式0123 --------------------*/
__forceinline int DetermineEncodingMode(char* pcText)
{
	// 不会
	return 2;
}


/*-------------------- 判断RQ版本号 -------------------*/
__forceinline int DetermineSize(char* pcText, int iEccLevel, int EncodingMode)
{
	int iTextLen = strlen(pcText);
	for(int i = 0 ; i< 40 ; i++)
	{
		if(QRcodeVersionCapacityData[i][iEccLevel] >= iTextLen)
		{
			return i;
		}	
	}
	return -1;
}


/*-------------- 编码文字 这里暂时不编码 --------------*/
__forceinline char* EncodeWord(char* pcText, int iEccLevel, int EncodingMode, int QRLevel)
{
	char* cpDataCodewords = new char[DataCodewordsLenList[QRLevel][iEccLevel]];
	memset(cpDataCodewords , 0x00 , DataCodewordsLenList[QRLevel][iEccLevel]);

	// 假设我按照版本编码了文字，但是现在只支持2模式字节模式
	char* pcTextBuffer = new char[strlen(pcText)+1];
	memcpy(pcTextBuffer, pcText, strlen(pcText)+1);
	unsigned int TextByteNumber = strlen(pcText);

	// 模式指示符
	unsigned char cMode = NULL;
	switch (EncodingMode)
	{	
		case 0: cMode = 0b00010000; break;
		case 1: cMode = 0b00100000; break;
		case 2: cMode = 0b01000000; break;
		case 3: cMode = 0b10000000; break;
		default: return nullptr;
	};
	BitWrite(cpDataCodewords, &cMode, 0, 4);


	// 长度指示符 // BitWrite: manual big-endian bit order, independent of host endianness
	unsigned int* ttttemp = &TextByteNumber;
	BitWrite(cpDataCodewords, &TextByteNumber, 4, CharacterCountIndicatorLengthList[QRLevel][EncodingMode]);

	// 写入实际数据
	int Counter = 4 + CharacterCountIndicatorLengthList[QRLevel][EncodingMode];
	BitWrite(cpDataCodewords, pcTextBuffer, Counter , TextByteNumber * 8);
	Counter += strlen(pcTextBuffer) * 8;
	delete[] pcTextBuffer;

	// 补充到字节对齐
	char cNull = {0};
	int iPadding = 8 - Counter % 8;
	BitWrite(cpDataCodewords, &cNull, Counter, iPadding );
	if(Counter % 8 != 0) Counter += iPadding;

	// 填充
	iPadding = DataCodewordsLenList[QRLevel][iEccLevel] - (Counter / 8);
	if (iPadding)
	{
		char* cpDataCodewordsTemp = cpDataCodewords +  Counter / 8;
		memcpy(cpDataCodewordsTemp, PaddingBytes , iPadding);
	}

	return cpDataCodewords;
}


/*------------------ 数据分析准备入口 -----------------*/
__forceinline int QR_AnalysisAndPreparation(char* pcText, int iEccLevel , char** pTextBuffer , int* pVersion)
{	
	int EncodingMode = DetermineEncodingMode(pcText);
	int Version = DetermineSize(pcText , iEccLevel , EncodingMode);
	*pTextBuffer = EncodeWord(pcText , iEccLevel , EncodingMode , Version);
	*pVersion = Version;

	return 0;

}


/*------------------ DataCodeword分割 -----------------*/
__forceinline char** DataCodewordSplitting(char* pcText, int iEccLevel, int QRLevel)
{
	
	// 分割后buffer 字符纯指针数组
	char** DataBlock = new char* [CodewordSplittingData[QRLevel][iEccLevel][1] + CodewordSplittingData[QRLevel][iEccLevel][3]];

	// 复制短块
	char* Counter = pcText;
	for (int i = 0; i < CodewordSplittingData[QRLevel][iEccLevel][1]; i++)
	{
		DataBlock[i] = new char[CodewordSplittingData[QRLevel][iEccLevel][2] + CodewordSplittingData[QRLevel][iEccLevel][0]];
		memset(DataBlock[i], 0x00 , CodewordSplittingData[QRLevel][iEccLevel][2] + CodewordSplittingData[QRLevel][iEccLevel][0]);
		memcpy(DataBlock[i], Counter, (size_t)CodewordSplittingData[QRLevel][iEccLevel][2]);
		Counter += CodewordSplittingData[QRLevel][iEccLevel][2];
	}

	// 如果没有长块就结束
	if (!CodewordSplittingData[QRLevel][iEccLevel][3]) return DataBlock;

	// 复制长块
	for (int i = CodewordSplittingData[QRLevel][iEccLevel][1]; i < CodewordSplittingData[QRLevel][iEccLevel][1] + CodewordSplittingData[QRLevel][iEccLevel][3]; i++)
	{
		DataBlock[i] = new char[CodewordSplittingData[QRLevel][iEccLevel][4] + CodewordSplittingData[QRLevel][iEccLevel][0]];
		memset(DataBlock[i], 0x00, CodewordSplittingData[QRLevel][iEccLevel][4] + CodewordSplittingData[QRLevel][iEccLevel][0]);
		memcpy(DataBlock[i], Counter, (size_t)CodewordSplittingData[QRLevel][iEccLevel][4]);
		Counter += CodewordSplittingData[QRLevel][iEccLevel][4];
	}

	// 完事把原来的预处理char释放掉
	delete[] pcText;

	return DataBlock;
}


/*----------------------- 计算ECC ---------------------*/
__forceinline int GenerateECC(char** CodewordBlocks, int iEccLevel, int QRLevel)
{
	// 计算短块
	for (int i = 0; i < CodewordSplittingData[QRLevel][iEccLevel][1]; i++)
	{
		_GenerateECC(CodewordBlocks[i], CodewordSplittingData[QRLevel][iEccLevel][2], CodewordSplittingData[QRLevel][iEccLevel][0]);
	}

	// 如果没有长块就结束
	if (!CodewordSplittingData[QRLevel][iEccLevel][3]) return 1;

	// 计算长块
	for (int i = CodewordSplittingData[QRLevel][iEccLevel][1]; i < CodewordSplittingData[QRLevel][iEccLevel][1] + CodewordSplittingData[QRLevel][iEccLevel][3]; i++)
	{
		_GenerateECC(CodewordBlocks[i], CodewordSplittingData[QRLevel][iEccLevel][4], CodewordSplittingData[QRLevel][iEccLevel][0]);
	}

	return 1;
}


/*------------- FinalMessageCodewords交织 -------------*/
__forceinline char* IntertwinedFinalMessageCodewords(char** CodewordBlocks, int iEccLevel, int QRLevel)
{
	// 新FinalMessage数组
	char* FinalMessage = new char[FinalMessageCodewordsLenList[QRLevel]];

	// 填入短块
	for (int i = 0; i < CodewordSplittingData[QRLevel][iEccLevel][1]; i++)
	{
		for (int j = 0; j < CodewordSplittingData[QRLevel][iEccLevel][2] + CodewordSplittingData[QRLevel][iEccLevel][0]; j++)
		{
			FinalMessage[j * (CodewordSplittingData[QRLevel][iEccLevel][1] + CodewordSplittingData[QRLevel][iEccLevel][3]) + i] = CodewordBlocks[i][j];
		}
	}

	// 如果没有长块就结束
	if (!CodewordSplittingData[QRLevel][iEccLevel][3]) return FinalMessage;

	// 填入长块
	for (int i = CodewordSplittingData[QRLevel][iEccLevel][1]; i < CodewordSplittingData[QRLevel][iEccLevel][1] + CodewordSplittingData[QRLevel][iEccLevel][3]; i++)
	{
		for (int j = 0; j < CodewordSplittingData[QRLevel][iEccLevel][2] + CodewordSplittingData[QRLevel][iEccLevel][0]; j++)
		{
			FinalMessage[j * (CodewordSplittingData[QRLevel][iEccLevel][1] + CodewordSplittingData[QRLevel][iEccLevel][3]) + i] = CodewordBlocks[i][j];
		}
		int ShortBlockArea = (CodewordSplittingData[QRLevel][iEccLevel][2] + CodewordSplittingData[QRLevel][iEccLevel][0]) * (CodewordSplittingData[QRLevel][iEccLevel][1] + CodewordSplittingData[QRLevel][iEccLevel][3]);
		for (int j = CodewordSplittingData[QRLevel][iEccLevel][2] + CodewordSplittingData[QRLevel][iEccLevel][0]; j < CodewordSplittingData[QRLevel][iEccLevel][4] + CodewordSplittingData[QRLevel][iEccLevel][0]; j++)
		{
			FinalMessage[ShortBlockArea + (j - CodewordSplittingData[QRLevel][iEccLevel][2] - CodewordSplittingData[QRLevel][iEccLevel][0]) * CodewordSplittingData[QRLevel][iEccLevel][3] + (i - CodewordSplittingData[QRLevel][iEccLevel][1])] = CodewordBlocks[i][j];
		}
	}

	// 完事把原来的预处理char释放掉
	for (int i = 0; i < CodewordSplittingData[QRLevel][iEccLevel][1] + CodewordSplittingData[QRLevel][iEccLevel][3]; i++)
	{
		delete[] CodewordBlocks[i];
	}
	delete[] CodewordBlocks;

	return FinalMessage;
}


/*----------------------- ECC入口 ---------------------*/
__forceinline int QR_ECCAndFusion(char** pcText, int iEccLevel, int QRLevel)
{
	char** DataBlock;
	char* FinalMessageCodewords;

	DataBlock = DataCodewordSplitting(*pcText, iEccLevel, QRLevel);
	GenerateECC(DataBlock, iEccLevel, QRLevel);
	delete[] *pcText;
	*pcText = IntertwinedFinalMessageCodewords(DataBlock, iEccLevel, QRLevel);

	for (int i = 0; i < CodewordSplittingData[QRLevel][iEccLevel][1] + CodewordSplittingData[QRLevel][iEccLevel][3]; i++) delete[] DataBlock[i];
	delete[] DataBlock;

	return 0;
}


/*----------------- 识别方框FinderBox -----------------*/
__forceinline void DrawFinderBox(int x, int y, char* QRCodeDot, int Version)
{
	for (int i = 0; i <= 5; i++)
	{
		QRCodeDot[(y - 3 + i) * SideOfVersion[Version] + x - 3] = 0x01;
		QRCodeDot[(y - 3) * SideOfVersion[Version] + (x - i + 3)] = 0x01;
		QRCodeDot[(y + 3 - i) * SideOfVersion[Version] + (x + 3)] = 0x01;
		QRCodeDot[(y + 3) * SideOfVersion[Version] + (x - 3 + i)] = 0x01;
	}

	for (int i = 0; i <= 4; i++)
	{
		QRCodeDot[(y - 2 + i) * SideOfVersion[Version] + x - 2] = 0x02;
		QRCodeDot[(y - 2) * SideOfVersion[Version] + (x - i + 2)] = 0x02;
		QRCodeDot[(y + 2 - i) * SideOfVersion[Version] + (x + 2)] = 0x02;
		QRCodeDot[(y + 2) * SideOfVersion[Version] + (x - 2 + i)] = 0x02;
	}

	if(x == 3 && y == 3)
	{
		for (int i = 0; i < 8; i++)
		{
			QRCodeDot[(y + 4 - i) * SideOfVersion[Version] + x + 4] = 0x02;
			QRCodeDot[(y + 4) * SideOfVersion[Version] + x - i + 4] = 0x02;
		}
	}
	else if(x == 3 && y == SideOfVersion[Version] - 4)
	{
		for (int i = 0; i < 8; i++)
		{
			QRCodeDot[(y - 4 + i) * SideOfVersion[Version] + x + 4] = 0x02;
			QRCodeDot[(y - 4) * SideOfVersion[Version] + x - i + 4] = 0x02;
		}
	}
	else if (x == SideOfVersion[Version] - 4 && y == 3)
	{
		for (int i = 0; i < 8; i++)
		{
			QRCodeDot[(y + 4 - i) * SideOfVersion[Version] + x - 4] = 0x02;
			QRCodeDot[(y + 4) * SideOfVersion[Version] + x + i - 4] = 0x02;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			QRCodeDot[(y - 1 + i) * SideOfVersion[Version] + (x - 1 + j)] = 0x01;
		}
	}
}
__forceinline void DrawAlignmentBox(int x, int y, char* QRCodeDot, int Version)
{
	//矫正图案
	for (int i = 0; i <= 3; i++) 
	{
		QRCodeDot[(y - 2 + i) * SideOfVersion[Version] + x - 2] = 0x03;
		QRCodeDot[(y - 2) * SideOfVersion[Version] + (x - i  +2)] = 0x03;
		QRCodeDot[(y + 2 - i) * SideOfVersion[Version] + (x + 2 )] = 0x03;
		QRCodeDot[(y + 2) * SideOfVersion[Version] + (x - 2 + i)] = 0x03;
	}

	for (int i = 0; i <= 2; i++) 
	{
		QRCodeDot[(y - 1 + i) * SideOfVersion[Version] + x - 1] = 0x04;
		QRCodeDot[(y - 1) * SideOfVersion[Version] + (x - i + 1)] = 0x04;
		QRCodeDot[(y + 1 - i) * SideOfVersion[Version] + (x + 1)] = 0x04;
		QRCodeDot[(y + 1) * SideOfVersion[Version] + (x - 1 + i)] = 0x04;
	}

	QRCodeDot[(y)*SideOfVersion[Version] + x] = 0x03;

}
__forceinline void SetupFinderPattern(char* QRCodeDot, int Version)
{
	//三个角的识别图
	DrawFinderBox(3, 3, QRCodeDot, Version);
	DrawFinderBox(3, SideOfVersion[Version] - 4, QRCodeDot, Version);
	DrawFinderBox(SideOfVersion[Version] - 4, 3, QRCodeDot, Version);

	//矫正图案
	for (int x = 1; x <= AlignmentPatternPositionsList[Version][0]; x++)
	{
		for (int y = 1; y <= AlignmentPatternPositionsList[Version][0]; y++)
		{
			int temp0 = QRCodeDot[AlignmentPatternPositionsList[Version][y] * SideOfVersion[Version] + AlignmentPatternPositionsList[Version][x]];
			if (QRCodeDot[AlignmentPatternPositionsList[Version][y] * SideOfVersion[Version] + AlignmentPatternPositionsList[Version][x]] == 0)
			{
				DrawAlignmentBox(AlignmentPatternPositionsList[Version][x], AlignmentPatternPositionsList[Version][y], QRCodeDot, Version);
			}
		}
	}
}


/*------------------ TimingPattern线 ------------------*/
__forceinline void SetupTimingPattern(char* QRCodeDot, int Version)
{
	for (int r = 8; r < SideOfVersion[Version] - 8; r += 2)
	{
		QRCodeDot[r * SideOfVersion[Version] + 6] = 0x01;
		QRCodeDot[6 * SideOfVersion[Version] + r] = 0x01;
	}
	for (int r = 7; r < SideOfVersion[Version] - 7; r += 2)
	{
		QRCodeDot[r * SideOfVersion[Version] + 6] = 0x02;
		QRCodeDot[6 * SideOfVersion[Version] + r] = 0x02;
	}
}


/*----------------- 写入两个识信息占位 ----------------*/
__forceinline void SetupFormatInfo(char* QRCodeDot, int Version)
{
	for (int i = 0; i < 15; i++)
	{
		//竖着
		if (i < 6)
			QRCodeDot[i * SideOfVersion[Version] + 8] = 0x06;
		else if (i < 8)
			QRCodeDot[(i + 1) * SideOfVersion[Version] + 8] = 0x06;
		else
			QRCodeDot[(SideOfVersion[Version] - 15 + i) * SideOfVersion[Version] + 8] = 0x06;

		//横的
		if (i < 8)
			QRCodeDot[8 * SideOfVersion[Version] + (SideOfVersion[Version] - i - 1)] = 0x06;
		else if (i < 9)
			QRCodeDot[8 * SideOfVersion[Version] + (15 - i)] = 0x06;
		else
			QRCodeDot[8 * SideOfVersion[Version] + (15 - i - 1)] = 0x06;
	}
	QRCodeDot[(SideOfVersion[Version] - 8) * SideOfVersion[Version] + 8] = 0x05;

}


/*---------------- 如果版本大于7直接写入 --------------*/
__forceinline void SetupVersionInformation(char* QRCodeDot, int Version)
{
	if(Version > 5)
	{
		for (int i = 0; i < 6; i++)
		{
			QRCodeDot[(SideOfVersion[Version] - 10) * SideOfVersion[Version] + i] = VersionInformationBitStream[Version][i * 3];
			QRCodeDot[(SideOfVersion[Version] - 9 ) * SideOfVersion[Version] + i] = VersionInformationBitStream[Version][i * 4];
			QRCodeDot[(SideOfVersion[Version] - 8 ) * SideOfVersion[Version] + i] = VersionInformationBitStream[Version][i * 5];

			QRCodeDot[i *SideOfVersion[Version] + SideOfVersion[Version] - 10] = VersionInformationBitStream[Version][i * 3];
			QRCodeDot[i *SideOfVersion[Version] + SideOfVersion[Version] - 9 ] = VersionInformationBitStream[Version][i * 4];
			QRCodeDot[i *SideOfVersion[Version] + SideOfVersion[Version] - 8 ] = VersionInformationBitStream[Version][i * 5];
		}
	}
}


/*--------------------- z字填入文字 -------------------*/
__forceinline int SetupMainText(char* QRCodeDot, int Version, char* FinalMessage)
{
	int bitIndex = 0;
	int x = SideOfVersion[Version] - 1;
	int y = SideOfVersion[Version] - 1;
	int direction = -1; // -1 = 向上, +1 = 向下

	while (x > 0) {
		if (x == 6) x--; // 跳过 timing line

		while(1)
		{
			// 右往左写两个
			for (int dx = 0; dx < 2; dx++) 
			{
				int xx = x - dx;
				if (xx < 0) continue;

				if (QRCodeDot[y * SideOfVersion[Version] + xx] == 0) 
				{ // 可写
					if (bitIndex < FinalMessageCodewordsLenList[Version]*8) 
					{
						QRCodeDot[y * SideOfVersion[Version] + xx] = ((FinalMessage[bitIndex >> 3] >> (7 - (bitIndex & 7))) & 1) ? 0x07 : 0x08;
						bitIndex++;
					}
					else {
						QRCodeDot[y * SideOfVersion[Version] + xx] = 0xFF; // 填完后余白可设为0
					}
				}
			}

			y += direction;
			if (y < 0 || y >= SideOfVersion[Version]) 
			{
				y -= direction; // 回退到有效行
				direction = -direction; // 换方向
				break; // 下一两列
			}
		}

		x -= 2; // 左移两列
	}

	return 0;
}


/*------------------ 模板结构绘制入口 -----------------*/
__forceinline void QR_TemplateStructure(char** QRCodeDot, int Version , char* FinalMessage)
{
	*QRCodeDot = new char[SizeOfVersion[Version]];
	memset(*QRCodeDot, 0 , SizeOfVersion[Version]*(sizeof(char)));
	
	SetupFinderPattern(*QRCodeDot, Version);
	SetupTimingPattern(*QRCodeDot, Version); 
	SetupFormatInfo(*QRCodeDot, Version);
	SetupVersionInformation(*QRCodeDot, Version);
	SetupMainText(*QRCodeDot, Version, FinalMessage);
}


/*---------------------- 掩码生成 ---------------------*/
__forceinline void BitReverse(char* Bit)
{
	if(Bit[0] == 0x07)
	{
		Bit[0] = 0x08;
	}
	else if (Bit[0] == 0x08)
	{
		Bit[0] = 0x07;
	}
	//else if (Bit[0] == 0x00)
	//{
	//	Bit[0] = 0x07;
	//}
}
__forceinline void SetupMask(char*** QRCodeDotGroup, char* QRCodeDot, int Version)
{
	// 新内存
	*QRCodeDotGroup = new char*[8];
	(*QRCodeDotGroup)[7] = QRCodeDot;
	for(int i = 0 ; i < 7 ; i ++)
	{
		(*QRCodeDotGroup)[i] = new char[SizeOfVersion[Version]];
		memcpy((*QRCodeDotGroup)[i] , QRCodeDot , SizeOfVersion[Version]);
	}

	// 掩码
	for (int i = 0; i < SideOfVersion[Version]; i++)
	{
		for (int j = 0; j < SideOfVersion[Version]; j++)
		{
			// (000
			if((i + j) % 2 == 0)
			{
				BitReverse(&(*QRCodeDotGroup)[0][i * SideOfVersion[Version] + j]);
			}

			// (001
			if (i % 2 == 0)
			{
				BitReverse(&(*QRCodeDotGroup)[1][i * SideOfVersion[Version] + j]);
			}

			// (010
			if (j % 3 == 0)
			{
				BitReverse(&(*QRCodeDotGroup)[2][i * SideOfVersion[Version] + j]);
			}

			// (011
			if ((i + j) % 3 == 0)
			{
				BitReverse(&(*QRCodeDotGroup)[3][i * SideOfVersion[Version] + j]);
			}

			// (100
			if ((i / 2 + j / 3) % 2 == 0)
			{
				BitReverse(&(*QRCodeDotGroup)[4][i * SideOfVersion[Version] + j]);
			}

			// (101
			if ((i * j) % 2 + (i * j) % 3 == 0)
			{
				BitReverse(&(*QRCodeDotGroup)[5][i * SideOfVersion[Version] + j]);
			}

			// (110
			if (((i * j) % 2 + (i * j) % 3) % 2 == 0)
			{
				BitReverse(&(*QRCodeDotGroup)[6][i * SideOfVersion[Version] + j]);
			}

			// (111
			if (((i + j) % 2 + (i * j) % 3) % 2 == 0)
			{
				BitReverse(&(*QRCodeDotGroup)[7][i * SideOfVersion[Version] + j]);
			}
		}
	}
}


/*------------------ Mask Evaluation ------------------*/
__forceinline int AssessmentMask(char** QRCodeDotGroup, char** QRCodeDot, int Version)
{
	int Best = 0;
	unsigned int BestRating = 0xFFFFFFFF;

	for(int i = 0 ; i < 7 ; i++)
	{
		int iRating = 0;
		
		// Big chunk rating Penalty Rule 1
		int penalty = 0;

		for (int y = 0; y < SideOfVersion[Version] - 1; y++)
		{
			for (int x = 0; x < SideOfVersion[Version] - 1; x++)
			{
				unsigned char v = QRCodeDotGroup[i][y * SideOfVersion[Version] + x];
				
				// Only process unscored black or white tiles
				if (v != 0x07 && v != 0x08) continue;

				// Quick check if it is a 2x2 start
				if (QRCodeDotGroup[i][y * SideOfVersion[Version] + x + 1] == v && QRCodeDotGroup[i][(y + 1) * SideOfVersion[Version] + x] == v && QRCodeDotGroup[i][(y + 1)* SideOfVersion[Version] + x + 1] == v)
				{
					// Try to expand the rectangle
					int maxW = 2;
					int maxH = 2;
					bool expanded = true;

					// x and y expand alternately — check the entire new edge each time
					while (true)
					{
						bool grew = false;

						// Try to expand to the right: check the whole new column [y .. y+maxH-1] at x+maxW
						if (x + maxW < SideOfVersion[Version])
						{
							bool colUniform = true;
							for (int dy = 0; dy < maxH; dy++)
							{
								if (QRCodeDotGroup[i][(y + dy) * SideOfVersion[Version] + (x + maxW)] != v)
								{
									colUniform = false;
									break;
								}
							}
							if (colUniform)
							{
								maxW++;
								grew = true;
							}
						}

						// Try to expand downward: check the whole new row [x .. x+maxW-1] at y+maxH
						if (y + maxH < SideOfVersion[Version])
						{
							bool rowUniform = true;
							for (int dx = 0; dx < maxW; dx++)
							{
								if (QRCodeDotGroup[i][(y + maxH) * SideOfVersion[Version] + (x + dx)] != v)
								{
									rowUniform = false;
									break;
								}
							}
							if (rowUniform)
							{
								maxH++;
								grew = true;
							}
						}

						if (!grew) break;
					}


					// Mark this block as graded
					char marked = (v == 0x07) ? 0x0B : 0x0C;
					for (int dy = 0; dy < maxH ; dy++)
					{
						for (int dx = 0; dx < maxW ; dx++)
						{
							QRCodeDotGroup[i][(y + dy) * SideOfVersion[Version] + x + dx] = marked;
						}
					}

					iRating += 3;
				}
			}
		}

		// Proportional scoring Penalty Rule 4
		int Balance = 0;
		for(int j = 0 ; j < SizeOfVersion[Version] ; j ++)
		{
			if(QRCodeDotGroup[i][j] == 1)
			{
				Balance++;
			}
			else
			{
				Balance--;
			}
		}
		Balance = Balance < 0 ? -Balance : Balance;
		int iIncrement = (int)((float)Balance / (float)SizeOfVersion[Version] * 200);
		if (iIncrement > 19)iRating += iIncrement;

		// If it is smaller, replace the reference value
		if(iRating < BestRating)
		{
			BestRating = iRating;
			Best = i;
		}
	}

	*QRCodeDot = QRCodeDotGroup[Best];
	for(int i =0 ; i < 8 ; i++)
	{
		if(i != Best)delete[] QRCodeDotGroup[i];
	}
	delete[] QRCodeDotGroup;
	return Best;
}


/*-------------------- 填入格式信息 -------------------*/
__forceinline void SetupFinalFormatInfo(char* QRCodeDot, int Version ,int  iEccLevel , int MaskID)
{
	for (int i = 0; i < 15; i++ )
	{
		//竖着
		if (i < 6)
			QRCodeDot[i * SideOfVersion[Version] + 8] = formatInfoAfterMasking[iEccLevel][MaskID][14 - i];
		else if (i < 8)
			QRCodeDot[(i + 1) * SideOfVersion[Version] + 8] = formatInfoAfterMasking[iEccLevel][MaskID][14 - i];
		else
			QRCodeDot[(SideOfVersion[Version] - 15 + i) * SideOfVersion[Version] + 8] = formatInfoAfterMasking[iEccLevel][MaskID][14 - i];

		//横的
		if (i < 8)
			QRCodeDot[8 * SideOfVersion[Version] + (SideOfVersion[Version] - i - 1)] = formatInfoAfterMasking[iEccLevel][MaskID][14 - i];
		else if (i < 9)
			QRCodeDot[8 * SideOfVersion[Version] + (15 - i)] = formatInfoAfterMasking[iEccLevel][MaskID][14 - i];
		else
			QRCodeDot[8 * SideOfVersion[Version] + (15 - i - 1)] = formatInfoAfterMasking[iEccLevel][MaskID][14 - i];
	}

}


/*------------------ 掩码整理输出入口 -----------------*/
__forceinline void QR_MaskAndOutput(char** QRCodeDot, int Version , int  iEccLevel)
{
	char** QRCodeDotGroup = nullptr;
	int MaskID ;
	SetupMask(&QRCodeDotGroup, *QRCodeDot, Version);
	MaskID = AssessmentMask(QRCodeDotGroup , QRCodeDot , Version);
	SetupFinalFormatInfo(*QRCodeDot , Version , iEccLevel , MaskID);
}


/*------------------ Creator Entrance -----------------*/
int CreateQRCode(char** QRCodeDot, char* pcText ,int iEccLevel)
{
	char* QRCodeDot_ = nullptr;
	int Version ;
	char* pTextBuffer;

	// 生成部分 
	QR_AnalysisAndPreparation(pcText ,iEccLevel ,&pTextBuffer ,&Version);
	QR_ECCAndFusion(&pTextBuffer , iEccLevel, Version);
	QR_TemplateStructure(&QRCodeDot_ ,Version , pTextBuffer);
	QR_MaskAndOutput(&QRCodeDot_ , Version , iEccLevel);

	// 输出
	*QRCodeDot = QRCodeDot_;
	delete[] pTextBuffer;

	return Version;
}
