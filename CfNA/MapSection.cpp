#include "MapSection.h"
#include "Csv.h"
#include "Hex.h"
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

MapSection::MapSection()
{
	string mapB = "D:\\CfNA\\ChartsAndTables\\MapBTerrainInHex.csv";
	terrainInHex = readCsv(mapB);

	int map_height = 10;
	int map_width = 10;
	int startHex = 5700;
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


}


MapSection::~MapSection()
{
}
