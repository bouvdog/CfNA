#include "CppUnitTest.h"
#include "../CfNA/TerrainEffectsChart.h"

#include <string>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace TerrainEffectsChart;
using namespace std;

namespace test
{		
	TEST_CLASS(test_terraineffectschart)
	{
	public:
		
		TEST_METHOD(CPA)
		{
			Chart tec;
			tec.loadTerrainEffectsChartCsv();

			// Given a terrain type and a 'column' return the value
			auto value = tec.readChart(CLEAR, MOTORIZED);
			Assert::AreEqual(value, string("2"));
		}

	};
}