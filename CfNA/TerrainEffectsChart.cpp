#include "pch.h"
#include "TerrainEffectsChart.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

namespace TerrainEffectsChart
{
	const string NON_MOTORIZED = "non-motorized";
	const string MOTORIZED = "motorized";
	const string BREAKDOWN = "breakdown";
	const string BARRAGE = "barrage";
	const string ANTI_ARMOR = "anti armor";
	const string CLOSE_ASSUALT = "close assualt";
	const string STACKING_LIMIT = "stacking limit";

	const string CLEAR = "clear";
	const string GRAVEL = "gravel";
	const string SALT_MARSH = "salt marsh";
	const string HEAVY_VEGETATION = "heavy vegetation";
	const string ROUGH = "rough";
	const string MOUNTAIN = "mountain";
	const string DELTA = "delta";
	const string DESERT = "desert";
	const string MAJOR_CITY = "major city";
	const string VILLAGE_BIR_OASIS = "village/bir/oasis";
	const string RAILROAD = "railroad";
	const string ROAD = "road";
	const string TRACK = "track";
	const string RIDGE = "ridge";
	const string UP_SLOPE = "up slope";
	const string DOWN_SLOPE = "down slope";
	const string UP_ESCARPMENT = "up escarpment";
	const string DOWN_ESCARPMENT = "down escarpment";
	const string WADI = "wadi";
	const string MAJOR_RIVER = "major river";
	const string MINOR_RIVER = "minor river";
	const string FORT_LEVEL_ONE = "fort level one";
	const string FORT_LEVEL_TWO = "fort level two";
	const string FORT_LEVEL_THREE = "fort level three";
	const string FRIENDLY_MINEFIELD = "friendly minefield";
	const string ENEMY_MINEFIELD = "enemy minefield";
		
Chart::Chart()
{
	LoadTerrainEffectsChartCsv();
}


Chart::~Chart()
{
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

// While the terrain effects chart enum names are very close to the string
// values in the actual table, they are not identical. Thus, I rely on ordering
// to match the enum to the string. 
// Not too sure what you’re getting at with the below.  If I had a matrix addressed by string values for row and column, I’d do one of the following:
// 
//1)      Create a map of maps to look up first the row using a string key, then the column using a string key; i.e., “map<string, std:map<string, int>>”.
//2)      Concat the two string with a separator and use a hashmap for a one - step lookup; unordered_map< string, int >
//
//In either case, given you text, I’d lowercase the strings before lookup to insure case insensitivity.
void Chart::LoadTerrainEffectsChartCsv()
{
	ifstream table("D:\\CfNA\\ChartsAndTables\\8.37-TerrianEffectsChart.csv");
	string line;

	regex comma("[,]+");
	
	// Remember that the first row is the column headers
	// and the first value of each row after the first, is the name of the row
	getline(table, line);
	vector<string> headers = split(line, comma);
	vector<vector<string>> rows;

	while (getline(table, line))
	{
		rows.emplace_back(split(line, comma));
	}

	for (vector<string> v: rows)
	{
		string rowName = v.at(0);

		// TODO: change to regular iterator/for loop to have index
		int columnIndex = 0;
		for (string value : v)
		{
			++columnIndex;
			// I skip row name because I didn't strip the row names out of data frame/table before
			// building the map of maps
			if (rowName.compare(value) != 0)
			{
				




}
