#pragma once
#include <map>
#include <vector>
#include <string>
#include <map>


namespace TerrainEffectsChart
{
	const int NumberOfTerrainTypes = 28;

	// For enums that are not sparse(ie, there are no gaps in the numerical sequence, 
	// and they start with 0 or 1), I create an array of const char strings that maps the enums to strings,

	const char* const terrainTypesStrings[NumberOfTerrainTypes] = {
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
		"enemy minefield",
		"ocean"
	};

	enum TerrainTypes {
		CLEAR,
		GRAVEL,
		SALT_MARSH,
		HEAVY_VEGETATION,
		ROUGH,
		MOUNTAIN,
		DELTA,
		DESERT,
		MAJOR_CITY,
		SWAMP,
		VILLAGE_BIR_OASIS,
		RAILROAD,
		ROAD,
		TRACK,
		RIDGE,
		UP_SLOPE,
		DOWN_SLOPE,
		UP_ESCARPMENT,
		DOWN_ESCARPMENT,
		WADI,
		MAJOR_RIVER,
		MINOR_RIVER,
		FORT_LEVEL_ONE,
		FORT_LEVEL_TWO,
		FORT_LEVEL_THREE,
		FRIENDLY_MINEFIELD,
		ENEMY_MINEFIELD,
		OCEAN
	};

	const char* const movementOrCombatStrings[7] = {
		"non-motorized",
		"motorized",
		"breakdown",
		"barrage",
		"anti armor",
		"close assault",
		"stacking limit"
	};

	enum MovementOrCombat {
		NON_MOTORIZED,
		MOTORIZED,
		BREAKDOWN,
		BARRAGE,
		ANTI_ARMOR,
		CLOSE_ASSUALT,
		STACKING_LIMIT
	};


	// Ideally, we only want one of these but putting in a singleton is over-kill. This decision
	// we will be reflected in all the 'chart objects'
	// TODO: consider putting 'using namespace std' here 
	class Chart
	{
	public:
		Chart();
		~Chart();
		std::string readChart(int terrain, int action);
		static TerrainTypes terrainStringToEnum(std::string&);
		void loadTerrainEffectsChartCsv();

	private:
		std::vector < std::vector < std::pair<std::string, std::string>>> chartTable;
		std::vector<std::string> terrainEffectsNotes;

		static std::map<std::string, TerrainTypes> terrainStringToEnumTable;

		static bool isNotePresent(const std::string&);
		static std::vector<std::pair<std::string, std::string>> buildTableRow(const std::vector<std::string> row);

		std::vector<std::string> buildTerrainEffectsNotes();
		
	};

}