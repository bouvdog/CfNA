#pragma once

#include "Hex.h"
#include "TerrainEffectsChart.h"

#include <vector>
#include <string>
#include <map>

// There are five of these
namespace mapsection
{
	const int map_height = 10;
	const int map_width = 10;
	const int startHex = 5700;

	bool isMultiHexPresent(std::string s);

	class MapSection
	{
	public:
		MapSection();


		TerrainEffectsChart::TerrainTypes getTerrainInHex(int hexNumber);
		TerrainEffectsChart::TerrainTypes getTerrainOnSide(int hexNumber, hex::HexSide hs);
		TerrainEffectsChart::TerrainTypes getRoad(int hexNumber, hex::HexSide hs);
		std::map<hex::HexSide, TerrainEffectsChart::TerrainTypes> getRoads(int hexNumber);

		int defensiveBenefit(int hexNumber, hex::HexSide direction,
			TerrainEffectsChart::MovementOrCombat type);

		hex::Hex getHex(int hexNumber);

		void buildAMapSection(const std::string& section, const TerrainEffectsChart::Chart& tec);

	private:
		std::map<int, hex::Hex> mapSection;
		std::map<int, std::map<hex::HexSide, TerrainEffectsChart::TerrainTypes>> roadNetwork;
		std::map<int, TerrainEffectsChart::TerrainTypes> terrainInHex;
		std::map<int, std::map<hex::HexSide, TerrainEffectsChart::TerrainTypes>> terrainOnSides;
		TerrainEffectsChart::Chart terrain_effects_chart_;

		void buildTerrainInHex(const std::string& section);
		std::map<hex::HexSide, TerrainEffectsChart::TerrainTypes> buildSideTerrain(
			std::vector<std::string> sides);
		void buildHexSideTerrain(const std::string& section);
		void buildRoadNetwork(const std::string& section);
	};
}
