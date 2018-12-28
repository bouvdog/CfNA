#pragma once

#include "Hex.h"
#include "TerrainEffectsChart.h"

#include <vector>
#include <string>
#include <map>

namespace mapsection {

	const int map_height = 10;
	const int map_width = 10;
	const int startHex = 5700;

	bool isMultiHexPresent(const std::string s);

	class MapSection
	{
	public:
		std::map<int, TerrainEffectsChart::TerrainTypes> terrainInHex;
		std::map<int, std::vector<std::map<hex::HexSide, TerrainEffectsChart::TerrainTypes>>> terrainOnSides;

		std::map<int, hex::Hex> mapSection;

		MapSection();
		~MapSection();

		TerrainEffectsChart::TerrainTypes getTerrainInHex(const int hexNumber);
		TerrainEffectsChart::TerrainTypes getTerrainOnSide(const int hexNumber, hex::HexSide hs);

	private:
		TerrainEffectsChart::Chart tec;
		void buildTerrainInHex();
		void buildHexSideTerrain();
	};
}

