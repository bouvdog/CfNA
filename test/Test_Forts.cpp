#include "CppUnitTest.h"
#include "../CfNA/Csv.h"
#include "../CfNA/MapSection.h"
#include "../CfNA/Hex.h"
#include "../CfNA/TerrainEffectsChart.h"
#include "../CfNA/Forts.h"

#include <string>
#include <regex>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace csv;
using namespace std;
using namespace mapsection;
using namespace TerrainEffectsChart;
using namespace hex;
using namespace forts;

namespace test
{
	TEST_CLASS(fortifications)
	{
	public:

		TEST_METHOD(givenACreatedFortTable_returnTheLevelOfAFort)
		{
			Forts f;
			string section("A");
			string hexNumber("4827");
			auto level = f.getLevelOfFort(section,hexNumber);
			Assert::AreEqual(static_cast<int>(level), static_cast<int>(FORT_LEVEL_TWO));
		}


	};
}