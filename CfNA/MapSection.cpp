#include "Csv.h"
#include "MapSection.h"
#include "Hex.h"
#include "TerrainEffectsChart.h"

#include <string>
#include <regex>
#include <vector>
#include <map>

using namespace std;
using namespace csv;
using namespace mapsection;
using namespace TerrainEffectsChart;
using namespace hex;

// TODO: refactor with 'isNotePresent'
bool mapsection::isMultiHexPresent(const string s)
{
	auto present = true;
	if (s.find('-') == string::npos)
	{
		present = false;
	}
	return present;
}

MapSection::MapSection()
{
	
}

void MapSection::buildMapSection()
{
	auto hexNumber = startHex;
	auto column = 1;

	for (auto s = 0; s < map_height; s++) {
		int s_offset = floor(s / 2); // or r>>1
		for (int q = -s_offset; q < map_width - s_offset; q++) {

			mapSection.insert(pair<int, Hex>(hexNumber + column, Hex(q, -q - s, s)));
			column++;
		}
		column = 1;
		hexNumber = hexNumber + 100;
	}

	buildTerrainInHex();
	buildHexSideTerrain();
}


MapSection::~MapSection() = default;


// Assumption: there is only one terrain type in a hex. Fortifications and other 'additions' that apply to the
// hex will be in another table. 
void MapSection::buildTerrainInHex()
{
	auto rows = readCsv(R"(D:/CfNA/ChartsAndTables/MapBTerrainInhex.csv)");

	for (auto v : rows)
	{
		auto hexNumber = v[0];
		// a 'multihex' terrain is a way to reduce typing in the data files. Since so much of the terrain is repeated
		// on contiguous hexes, the terrain can be represented by a range of hex numbers separated by a dash. For instance,
		// 5009-5010. This is followed by a comma (CSV format file) and the terrain 'name' or description. For instance, 
		// 5009-5010,gravel. 
		if (mapsection::isMultiHexPresent(hexNumber))
		{
			auto startAndEnd = split(hexNumber, DASH);
			auto start = stoi(startAndEnd[0]);
			auto end = stoi(startAndEnd[1]);
			auto terrain = v[1];
			for (auto i = start; i <= end; i++)
			{
				terrainInHex.insert(pair<int, TerrainTypes>(i, Chart::terrainStringToEnum(terrain)));
			}
		}
		else
		{
			terrainInHex.insert(pair <int, TerrainTypes>(stoi(v[0]), Chart::terrainStringToEnum(v[1])));
		}
	}


}

map<HexSide, TerrainTypes> MapSection::buildSideTerrain(vector<string> sides)
{
	map<HexSide, TerrainTypes> sideTerrain;
	for (size_t i=1; i < sides.size(); i++)
	{
		// SW-up escarpment
		vector<string> sideAndTerrain = split(sides[i], DASH);
		auto direction = Hex::hexSideStringToEnum(sideAndTerrain[0]);
		auto terrain = Chart::terrainStringToEnum(sideAndTerrain[1]);
		sideTerrain.insert(pair<HexSide, TerrainTypes>(direction, terrain));
	}
	return sideTerrain;
}

void mapsection::MapSection::buildHexSideTerrain()
{
	// std::map<int, std::vector<std::map<hex::HexSide, TerrainEffectsChart::TerrainTypes>>> terrainOnSides;
	auto rows = readCsv(R"(D:/CfNA/ChartsAndTables/MapBHexSideTerrain.csv)");

	// 5604, SW-up escarpment, SE-up escarpment, E-up slope
	for (auto v : rows)
	{
		auto hexNumber = stoi(v[0]);
		terrainOnSides[hexNumber] = buildSideTerrain(v);
	}

}

TerrainEffectsChart::TerrainTypes MapSection::getTerrainInHex(const int hexNumber)
{
	return terrainInHex[hexNumber];
}

TerrainEffectsChart::TerrainTypes MapSection::getTerrainOnSide(const int hexNumber, const hex::HexSide hs)
{
	return terrainOnSides[hexNumber][hs];
}

