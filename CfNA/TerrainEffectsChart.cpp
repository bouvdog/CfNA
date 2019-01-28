#include "Csv.h"
#include "TerrainEffectsChart.h"

#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>

using namespace std;
using namespace TerrainEffectsChart;
using namespace csv;

map<string, TerrainTypes> buildTerrainStringToEnum()
{
	map<string, TerrainTypes> type;

	for (auto i = 0; i < NumberOfTerrainTypes; i++)
	{
		type.insert(
			pair<string, TerrainTypes>(terrainTypesStrings[i], static_cast<TerrainTypes>(i)));
	}
	return type;
}

map<string, TerrainTypes> Chart::terrainStringToEnumTable = buildTerrainStringToEnum();

int TerrainEffectsChart::covertShiftsToNumber(const std::string& shifts)
{
	int value = 0;
	if (shifts.find('L') == 0)
	{
		char char_array[3];
		strcpy_s(char_array, shifts.c_str());
		value = char_array[1] - '0';
	}
	return value;
}

Chart::Chart()
{
	loadTerrainEffectsChartCsv();
}


Chart::~Chart()
{
}

// TODO: more complicated; hex number input, then this object looks up the set of terrain in that hex
// and computes all the modifiers
// TODO: initialize the chartTable attribute;
string Chart::readChart(const int terrain, const int action)
{
	// increment the terrain by one to skip the header row
	// increment the action by one to skip row name column
	int skipHeader = terrain;
	int skipRowName = action;
	pair<string, string> value = chartTable.at(++skipHeader).at(++skipRowName);
	return value.first;
}


vector<string> Chart::buildTerrainEffectsNotes()
{
	vector<string> notes;
	ifstream tecNotes(R"(D:/CfNA/ChartsAndTables/TEC_Notes.txt)");
	string line, paragraph;
	while (getline(tecNotes, line))
	{
		if (line.empty())
		{
			notes.emplace_back(paragraph);
			paragraph.clear();
		}
		else
		{
			paragraph += line;
		}
	}
	return notes;
}

bool Chart::isNotePresent(const string& s)
{
	bool present = true;
	if (s.find('^') == string::npos)
	{
		present = false;
	}
	return present;
}

// Assumptions. There will be only one '^' to mark a note. 
vector<pair<string, string>> Chart::buildTableRow(const vector<string> row)
{
	vector<pair<string, string>> headers;
	for (auto& h : row)
	{
		if (isNotePresent(h))
		{
			regex note("[\\^]");
			vector<string> splitHeader = split(h, note);
			pair<string, string> header;
			header.first = splitHeader.front();
			header.second = splitHeader.back();
			headers.emplace_back(header);
		}
		else
		{
			pair<string, string> header;
			header.first = h;
			header.second = "";
			headers.emplace_back(header);
		}
	}
	return headers;
}

void Chart::loadTerrainEffectsChartCsv()
{
	ifstream table(R"(D:/CfNA/ChartsAndTables/8.37-TerrainEffectsChart.csv)");

	// The first row of the table is the column headers
	// and the value of the first column of each row is the row name
	string line;
	regex comma("[,]+");
	vector<vector<string>> rows;
	while (getline(table, line))
	{
		rows.emplace_back(split(line, comma));
	}

	for (auto& v : rows)
	{
		chartTable.emplace_back(buildTableRow(v));
	}

	buildTerrainEffectsNotes();
}


TerrainTypes Chart::terrainStringToEnum(string& terrainString)
{
	return terrainStringToEnumTable[trim(terrainString)];
}
