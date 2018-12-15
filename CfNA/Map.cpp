#include "Map.h"
#include "Csv.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>

using namespace std;
using namespace csv;

Map::Map()
{
	ifstream table("D:\\CfNA\\ChartsAndTables\\MapBTerrainInhex.csv");

	// The first row of the table is the column headers
	// and the value of the first column of each row is the row name
	string line;
	regex comma("[,]+");
	vector<vector<string>> rows;
	while (getline(table, line))
	{
		rows.emplace_back(split(line, comma));
	}
	
}


Map::~Map()
{
}
