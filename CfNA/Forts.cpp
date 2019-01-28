#include <fstream>
#include <regex>
#include <map>
#include <string>
#include "Forts.h"
#include "Csv.h"
#include "TerrainEffectsChart.h"
#include "CitiesVillages.h"


using namespace std;
using namespace TerrainEffectsChart;
using namespace citiesvillages;
using namespace forts;

Forts::Forts()
{
	// read the CitiesVillages data and set the appropriate fort level for each 
	// major city
	ifstream table(R"(D:/CfNA/ChartsAndTables/CitiesVillages.csv)");

	string line;
	regex comma("[,]+");
	vector<vector<string>> rows;
	while (getline(table, line))
	{
		rows.emplace_back(csv::split(line, comma));
	}

	for (auto& v : rows)
	{
		TerrainTypes tt = Chart::terrainStringToEnum(v[TERRAIN_TYPE]);
		if (tt == MAJOR_CITY)
		{
			addFortMajorCity(v[HEX_NUMBER], v[MAP_SECTION]);
		}
	}
}

TerrainTypes Forts::getLevelOfFort(const string& section, const string& hexNumber)
{
	return locationAndLevel[section + hexNumber];
}

void Forts::addFortMajorCity(const string& hexNumber, const string& mapSection)
{
	locationAndLevel.emplace(pair<string, TerrainTypes>(hexNumber + mapSection, FORT_LEVEL_TWO));
}
