#include "stdafx.h"
#include "CppUnitTest.h"
#include "Csv.h"
#include "MapSection.h"
#include "Hex.h"

#include <string>
#include <iostream>
#include <regex>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace csv;
using namespace std;

namespace test
{
	TEST_CLASS(MAPSECTION)
	{
	public:

		TEST_METHOD(givenCsvFileName_thenReturnTableOfStrings)
		{
			string mapB = "D:\\CfNA\\ChartsAndTables\\MapBTerrainInHex.csv";
			vector<vector<string>> results = readCsv(mapB);
			vector<string> row;
			row = results[80];
			Assert::AreEqual(row[0], string("4706-4710"));
		}

		TEST_METHOD(givenMapSectionConstructor_verifyConstruction)
		{
			MapSection m;
			Hex& h = m.mapSection[5704];
			Assert::AreEqual(h.q, 3);
			Assert::AreEqual(h.r, -3);
			Assert::AreEqual(h.s, 0);
			Hex& h1 = m.mapSection[5804];
			Assert::AreEqual(h1.q, 3);
			Assert::AreEqual(h1.r, -4);
			Assert::AreEqual(h1.s, 1);
		}
	};
}
