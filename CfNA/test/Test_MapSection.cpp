#include "stdafx.h"
#include "CppUnitTest.h"
#include "Csv.h"
#include "MapSection.h"
#include "Hex.h"
#include "TerrainEffectsChart.h"

#include <string>
#include <iostream>
#include <regex>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace csv;
using namespace std;
using namespace mapsection;
using namespace TerrainEffectsChart;
using namespace hex;

namespace test
{
	TEST_CLASS(MAPSECTION)
	{
	public:

		TEST_METHOD(givenCsvFileName_thenReturnTableOfStrings)
		{
			string mapB = "D:\\CfNA\\ChartsAndTables\\MapBTerrainInHex.csv";
			auto results = readCsv(mapB);
			auto row = results[80];
			Assert::AreEqual(row[0], string("4706-4710"));
		}

		TEST_METHOD(givenMapSectionConstructor_verifyConstruction)
		{
			MapSection m;
			auto h = m.mapSection[5704];
			Assert::AreEqual(h.q, 3);
			Assert::AreEqual(h.r, -3);
			Assert::AreEqual(h.s, 0);
			auto h1 = m.mapSection[5804];
			Assert::AreEqual(h1.q, 3);
			Assert::AreEqual(h1.r, -4);
			Assert::AreEqual(h1.s, 1);
		}

		TEST_METHOD(givenHexNumber_returnTerrainInHex)
		{
			MapSection m;
			TerrainTypes t = m.getTerrainInHex(5703);
			Assert::AreEqual(static_cast<int>(t), static_cast<int>(HEAVY_VEGETATION));
		}

		TEST_METHOD(givenHexNumberAndSide_returnTerrain)
		{
			MapSection m;
		}

	};
}
