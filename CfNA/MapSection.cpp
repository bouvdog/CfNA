#include "Csv.h"
#include "MapSection.h"
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
using namespace mapsection;

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


}


MapSection::~MapSection()
{
}

void MapSection::buildTerrainInHex()
{
	auto rows = readCsv("D:\\CfNA\\ChartsAndTables\\MapBTerrainInhex.csv");

	for (vector<string> v : rows)
	{
		string hexNumber = v[0];
		if (mapsection::isMultiHexPresent(hexNumber))
		{
			// split on '-' and create iterator using values on either side of the '-'
			regex dash("[-]");
			vector<string> startAndEnd = split(v[0], dash);
			int start = stoi(startAndEnd[0]);
			int end = stoi(startAndEnd[1]);
			for (int i = start; i <= end; i++)
			{

			}


		}
		else
		{

		}
	}


}
