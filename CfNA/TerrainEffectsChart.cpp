#include "pch.h"
#include "TerrainEffectsChart.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

namespace TerrainEffectsChart
{
	const std::string NON_MOTORIZED = "non-motorized";
	const std::string MOTORIZED = "motorized";
	const std::string BREAKDOWN = "breakdown";
	const std::string BARRAGE = "barrage";
	const std::string ANTI_ARMOR = "anti armor";
	const std::string CLOSE_ASSUALT = "close assualt";
	const std::string STACKING_LIMIT = "stacking limit";

	const std::string CLEAR = "clear";
	const std::string GRAVEL = "gravel";
	const std::string SALT_MARSH = "salt marsh";
	const std::string HEAVY_VEGETATION = "heavy vegetation";
	const std::string ROUGH = "rough";
	const std::string MOUNTAIN = "mountain";
	const std::string DELTA = "delta";
	const std::string DESERT = "desert";
	const std::string MAJOR_CITY = "major city";
	const std::string VILLAGE_BIR_OASIS = "village/bir/oasis";
	const std::string RAILROAD = "railroad";
	const std::string ROAD = "road";
	const std::string TRACK = "track";
	const std::string RIDGE = "ridge";
	const std::string UP_SLOPE = "up slope";
	const std::string DOWN_SLOPE = "down slope";
	const std::string UP_ESCARPMENT = "up escarpment";
	const std::string DOWN_ESCARPMENT = "down escarpment";
	const std::string WADI = "wadi";
	const std::string MAJOR_RIVER = "major river";
	const std::string MINOR_RIVER = "minor river";
	const std::string FORT_LEVEL_ONE = "fort level one";
	const std::string FORT_LEVEL_TWO = "fort level two";
	const std::string FORT_LEVEL_THREE = "fort level three";
	const std::string FRIENDLY_MINEFIELD = "friendly minefield";
	const std::string ENEMY_MINEFIELD = "enemy minefield";
		
Chart::Chart()
{
	LoadTerrainEffectsChartCsv();
}


Chart::~Chart()
{
}

// While the terrain effects chart enum names are very close to the string
// values in the actual table, they are not identical. Thus, I rely on ordering
// to match the enum to the string. 
// Not too sure what you’re getting at with the below.  If I had a matrix addressed by string values for row and column, I’d do one of the following:
// 
//1)      Create a map of maps to look up first the row using a string key, then the column using a string key; i.e., “std::map<std::string, std:map<std::string, int>>”.
//2)      Concat the two string with a separator and use a hashmap for a one - step lookup; std::unordered_map< std::string, int >
//
//In either case, given you text, I’d lowercase the strings before lookup to insure case insensitivity.
void Chart::LoadTerrainEffectsChartCsv()
{
	std::ifstream table("D:\\CfNA\\ChartsAndTables\\8.37-TerrianEffectsChart.csv");
	std::string line;

	while (std::getline(table, line))
	{
		std::cout << line << std::endl;
	}
}

}
