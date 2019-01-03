#include "CppUnitTest.h"
#include "../CfNA/Csv.h"
#include "../CfNA/MapSection.h"
#include "../CfNA/Hex.h"
#include "../CfNA/TerrainEffectsChart.h"

#include <string>
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
	TEST_CLASS(mapsection)
	{
	public:

		TEST_METHOD(givenCsvFileName_thenReturnTableOfStrings)
		{
			string mapB = R"(D:\CfNA\ChartsAndTables\MapBTerrainInHex.csv)";
			auto results = readCsv(mapB);
			auto row = results[80];
			Assert::AreEqual(row[0], string("4706-4710"));
		}

		TEST_METHOD(givenHexSideString_thenReturnHexSideEnum)
		{
			HexSide hs = Hex::hexSideStringToEnum("E");
			Assert::AreEqual(static_cast<int>(hs), static_cast<int>(E));
		}

		TEST_METHOD(givenMapSectionConstructor_verifyConstruction)
		{
			MapSection m;
			m.buildMapSection();
			auto h = m.mapSection[5704];
			Assert::AreEqual(h.getQ(), 3);
			Assert::AreEqual(h.getR(), -3);
			Assert::AreEqual(h.getS(), 0);
			auto h1 = m.mapSection[5804];
			Assert::AreEqual(h1.getQ(), 3);
			Assert::AreEqual(h1.getR(), -4);
			Assert::AreEqual(h1.getS(), 1);
		}

		TEST_METHOD(givenHexNumber_returnTerrainInHex)
		{
			MapSection m;
			m.buildMapSection();
			auto t = m.getTerrainInHex(5703);
			Assert::AreEqual(static_cast<int>(t), static_cast<int>(HEAVY_VEGETATION));
		}

		TEST_METHOD(givenHexNumberAndSide_returnTerrain)
		{
			MapSection m;
			m.buildMapSection();

			// 5604, SW-up escarpment, SE-up escarpment, E-up slope
			auto t = m.getTerrainOnSide(5604, E);
			Assert::AreEqual(static_cast<int>(t), static_cast<int>(UP_SLOPE));
		}

	};
}
