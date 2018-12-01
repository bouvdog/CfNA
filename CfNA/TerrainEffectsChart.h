#pragma once
#include <map>
#include <vector>
#include <string>
#include <regex>
#include <map>


namespace TerrainEffectsChart
{
	// For enums that are not sparse(ie, there are no gaps in the numerical sequence, 
	// and they start with 0 or 1), I create an array of const char strings that maps the enums to strings,

	const char* const terrainTypes[27] = {
		"clear",
		"gravel",
		"salt marsh",
		"heavy vegetation",
		"rough",
		"mountain",
		"delta",
		"desert",
		"major city",
		"swamp",
		"village/bir/oasis",
		"railroad",
		"road",
		"track",
		"ridge",
		"up slope",
		"down slope",
		"up escarpment",
		"down escarpment",
		"wadi",
		"major river",
		"minor river",
		"fort level one",
		"fort level two",
		"fort level three",
		"friendly minefield",
		"enemy minefield"
	};

	const int CLEAR = 0;
	const int GRAVEL = 1;
	const int SALT_MARSH = 2;
	const int HEAVY_VEGETATION = 3;
	const int ROUGH = 4;
	const int MOUNTAIN = 5;
	const int DELTA = 6;
	const int DESERT = 7;
	const int MAJOR_CITY = 8;
	const int SWAMP = 9;
	const int VILLAGE_BIR_OASIS = 10;
	const int RAILROAD = 11;
	const int ROAD = 12;
	const int TRACK = 13;
	const int RIDGE = 14;
	const int UP_SLOPE = 15;
	const int DOWN_SLOPE = 16;
	const int UP_ESCARPMENT = 17;
	const int DOWN_ESCARPMENT = 18;
	const int WADI = 19;
	const int MAJOR_RIVER = 20;
	const int MINOR_RIVER = 21;
	const int FORT_LEVEL_ONE = 22;
	const int FORT_LEVEL_TWO = 23;
	const int FORT_LEVEL_THREE = 24;
	const int FRIENDLY_MINEFIELD = 25;
	const int ENEMY_MINEFIELD = 26;

	const char* const movementOrCombat[7] = {
		"non-motorized",
		"motorized",
		"breakdown",
		"barrage",
		"anti armor",
		"close assault",
		"stacking limit"
	};

	const int NON_MOTORIZED = 0;
	const int MOTORIZED = 1;
	const int BREAKDOWN = 2;
	const int BARRAGE = 3;
	const int ANTI_ARMOR = 4;
	const int CLOSE_ASSUALT = 5;
	const int STACKING_LIMIT = 6;


	// Ideally, we only want one of these but putting in a singleton is over-kill. This decision
	// we will be reflected in all the 'chart objects'
	// TODO: consider putting 'using namespace std' here 
	class Chart
	{
	public:
		Chart();
		~Chart();
		std::string readChart(int terrain, int action);
		std::vector<std::pair<std::string, std::string>> buildTableRow(const std::vector<std::string> headerLine);
		std::vector<std::string> split(const std::string, const std::regex);

	private:
		std::vector < std::vector < std::pair<std::string, std::string>>> chartTable;
		std::vector<std::string> terrainEffectsNotes;
		void LoadTerrainEffectsChartCsv();

	};

}