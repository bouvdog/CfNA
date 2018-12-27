#include "Csv.h"
#include "MapSection.h"
#include "Hex.h"
#include "TerrainEffectsChart.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;
using namespace csv;
using namespace mapsection;
using namespace TerrainEffectsChart;

// TODO: refactor with 'isNotePresent'
bool mapsection::isMultiHexPresent(const string s)
{
	bool present = true;
	if (s.find("-") == string::npos)
	{
		present = false;
	}
	return present;
}

MapSection::MapSection()
{
	int hexNumber = startHex;
	int column = 1;

	for (int s = 0; s < map_height; s++) {
		int s_offset = floor(s / 2); // or r>>1
		for (int q = -s_offset; q < map_width - s_offset; q++) {
			
			mapSection.insert(pair<int, Hex>(hexNumber+column, Hex(q, -q-s, s)));
			column++;
		}
		column = 1;
		hexNumber = hexNumber + 100;
	}

	buildTerrainInHex();
}


MapSection::~MapSection()
{
}

// Assumption: there is only one terrain type in a hex. Fortifications and other 'additions' that apply to the
// hex will be in another table. 
void MapSection::buildTerrainInHex()
{
	auto rows = readCsv("D:\\CfNA\\ChartsAndTables\\MapBTerrainInhex.csv");

	for (vector<string> v : rows)
	{
		string hexNumber = v[0];
		// a 'multihex' terrain is a way to reduce typing in the data files. Since so much of the terrain is repeated
		// on contiguous hexes, the terrain can be represented by a range of hex numbers separated by a dash. For instance,
		// 5009-5010. This is followed by a comma (CSV format file) and the terrain 'name' or description. For instance, 
		// 5009-5010,gravel. Left to right was used arbitarily. 
		if (mapsection::isMultiHexPresent(hexNumber))
		{
			vector<string> startAndEnd = split(hexNumber, DASH);
			int start = stoi(startAndEnd[0]);
			int end = stoi(startAndEnd[1]);
			string terrain = v[1];
			for (int i = start; i <= end; i++)
			{
				terrainInHex.insert(pair<int, TerrainTypes>(i, tec.stringToEnum(terrain)));
			}
		}
		else
		{
			terrainInHex.insert(pair <int, TerrainTypes>(stoi(v[0]), tec.stringToEnum(v[1])));
		}
	}


}

void mapsection::MapSection::buildHexSideTerrain()
{
		auto rows = readCsv("D:\\CfNA\\ChartsAndTables\\MapBTerrainInhex.csv");

		for (vector<string> v : rows)
		{
			string hexNumber = v[0];
			// a 'multihex' terrain is a way to reduce typing in the data files. Since so much of the terrain is repeated
			// on contiguous hexes, the terrain can be represented by a range of hex numbers separated by a dash. For instance,
			// 5009-5010. This is followed by a comma (CSV format file) and the terrain 'name' or description. For instance, 
			// 5009-5010,gravel. Left to right was used arbitarily. 
			if (mapsection::isMultiHexPresent(hexNumber))
			{
				vector<string> startAndEnd = split(hexNumber, DASH);
				int start = stoi(startAndEnd[0]);
				int end = stoi(startAndEnd[1]);
				string terrain = v[1];
				for (int i = start; i <= end; i++)
				{
					terrainInHex.insert(pair<int, TerrainTypes>(i, tec.stringToEnum(terrain)));
				}
			}
			else
			{
				terrainInHex.insert(pair <int, TerrainTypes>(stoi(v[0]), tec.stringToEnum(v[1])));
			}
		}

}

TerrainEffectsChart::TerrainTypes mapsection::MapSection::getTerrainInHex(const int hexNumber)
{
	return terrainInHex[hexNumber];
}

TerrainEffectsChart::TerrainTypes mapsection::MapSection::getTerrainOnSide(const int hexNumber, const HexSide side)
{
	
}
