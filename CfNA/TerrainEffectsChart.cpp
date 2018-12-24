#include "Csv.h"
#include "TerrainEffectsChart.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>

using namespace std;
using namespace TerrainEffectsChart;
using namespace csv;

	Chart::Chart()
	{
		buildTerrainStringToEnum();
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
		ifstream tecNotes("D:\\CfNA\\ChartsAndTables\\TEC_Notes.txt");
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

	bool Chart::isNotePresent(const string s)
	{
		bool present = true;
		if (s.find("^") == string::npos)
		{
			present = false;
		}
		return present;
	}

	// Assumptions. There will be only one '^' to mark a note. 
	vector<pair<string, string>> Chart::buildTableRow(const vector<string> row)
	{
		vector<pair<string, string>> headers;
		for (string h : row)
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
		ifstream table("D:\\CfNA\\ChartsAndTables\\8.37-TerrianEffectsChart.csv");

		// The first row of the table is the column headers
		// and the value of the first column of each row is the row name
		string line;
		regex comma("[,]+");
		vector<vector<string>> rows;
		while (getline(table, line))
		{
			rows.emplace_back(split(line, comma));
		}

		vector<vector<pair<string, string>>> rowWithNotes;
		for (vector<string> v : rows)
		{
			chartTable.emplace_back(buildTableRow(v));
		}

		buildTerrainEffectsNotes();
	}

	void Chart::buildTerrainStringToEnum()
	{
		for (int i = 0; i < NumberOfTerrainTypes; i++)
		{
			terrainStringToEnum.insert(
				pair<string, TerrainTypes>(terrainTypesStrings[i], static_cast<TerrainTypes>(i)));
		}
	}

