#pragma once
#include <map>
#include <vector>
#include <string>
#include <regex>


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

	// Ideally, we only want one of these but putting in a singleton is over-kill. This decision
	// we will be reflected in all the 'chart objects'
	class Chart
	{
	public:
		Chart();
		~Chart();
		std::string readChart(std::string row, std::string column);
		std::vector<std::pair<std::string, std::string>> buildHeaders(const std::vector<std::string> headerLine);
		std::vector<std::string> split(const std::string, const std::regex);

	private:
		std::map<std::string, std::map<std::string, std::string>> chartTable;
		std::vector<std::string> terrainEffectsNotes;
		void LoadTerrainEffectsChartCsv();

	};

}