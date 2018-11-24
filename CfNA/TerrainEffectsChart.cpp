#include "TerrainEffectsChart.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>

using namespace std;

namespace TerrainEffectsChart
{




	Chart::Chart()
	{
		Chart::LoadTerrainEffectsChartCsv();
	}


	Chart::~Chart()
	{
	}


	string Chart::readChart(string row, string column)
	{
		string value = chartTable[row][column];
		return value;
	}

	// free function
	// TODO: make static
	vector<string> split(const string str, const regex regex)
	{
		vector<string> result;

		const sregex_token_iterator end;

		for (sregex_token_iterator it(str.begin(), str.end(), regex, -1); it != end; it++)
		{
			result.emplace_back(it->str());
		}

		return result;
	}

	vector<string> buildTerrainEffectsNotes()
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

	bool isNotePresent(string s)
	{
		bool present = false;
		if (s.find("^"))
		{
			present = true;
		}
		return present;
	}

	// Assumptions. There will be only one '^' to mark a note. 
	vector<pair<string, string>> Chart::buildHeaders(const vector<string> headerLine)
	{
		vector<pair<string, string>> headers;
		for (string h : headerLine)
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
	

	// Not too sure what you’re getting at with the below.  If I had a matrix addressed by string values for row and column, I’d do one of the following:
	// 
	//1)      Create a map of maps to look up first the row using a string key, then the column using a string key; i.e., “map<string, std:map<string, int>>”.
	//2)      Concat the two string with a separator and use a hashmap for a one - step lookup; unordered_map< string, int >
	void Chart::LoadTerrainEffectsChartCsv()
	{
		ifstream table("D:\\CfNA\\ChartsAndTables\\8.37-TerrianEffectsChart.csv");

		// The first row of the table is the column headers
		// and the value of the first column of each row is the row name
		string line;
		getline(table, line);

		regex comma("[,]+");
		vector<string> headerLine = split(line, comma);


		vector<vector<string>> rows;
		while (getline(table, line))
		{
			rows.emplace_back(split(line, comma));
		}

		map<string, string> columnValues;

		for (vector<string> v : rows)
		{

			// I skip row name column value because I didn't strip the row names out of 
			// the data frame/table before building this map of maps
			for (size_t i=1; i < v.size(); i++)
			{
				//columnValues.emplace(headers.at(i), v.at(i));
			}
			chartTable.emplace(v.at(0), columnValues);
			columnValues.clear();
		}

		buildTerrainEffectsNotes();
	}
}

