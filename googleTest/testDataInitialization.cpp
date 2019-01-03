#include "gtest\gtest.h"
#include "..\CfNA\TerrainEffectsChart.h"
#include "..\CfNA\Hex.h"
#include "..\CfNA\MapSection.h"

#include <string>

using namespace hex;
using namespace TerrainEffectsChart;
using namespace mapsection;
using namespace std;


TEST(Terrain_Effects_Chart, givenTerrainAndType_returnValue) 
{
	Chart tec;
	tec.loadTerrainEffectsChartCsv();
	string value = tec.readChart(CLEAR, MOTORIZED);
	ASSERT_EQ(value, string("2"));

	value = tec.readChart(ENEMY_MINEFIELD, BREAKDOWN);
	ASSERT_EQ(value, string("2"));
}

TEST(Map_Section, givenHexNumber_returnTerrainInHex)
{
	MapSection ms;
	ms.buildMapSection();
	TerrainTypes tt = ms.getTerrainInHex(4901);
	ASSERT_EQ(tt, MOUNTAIN);

	//4701 - 4705, rough
	tt = ms.getTerrainInHex(4704);
	ASSERT_EQ(tt, ROUGH);
}

TEST(Map_Section, givenhexNumberAndSide_returnHexSideTerrain)
{
	MapSection ms;
	ms.buildMapSection();
	// 4909, SW-wadi, W-wadi
	TerrainTypes tt = ms.getTerrainOnSide(4909, SW);
	ASSERT_EQ(tt, WADI);
}



