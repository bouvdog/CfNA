#include "gtest\gtest.h"
#include "..\CfNA\TerrainEffectsChart.h"
#include "..\CfNA\Hex.h"

#include <string>

using namespace hex;
using namespace TerrainEffectsChart;
using namespace std;

TEST(TerrainEffectsChart, givenTerrainAndType_returnValue) 
{
	Chart tec;
	tec.loadTerrainEffectsChartCsv();
	string value = tec.readChart(CLEAR, MOTORIZED);
	ASSERT_EQ(value, string("2"));
}