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
using namespace csv;

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
		string name = v[NAME];
		if (tt == MAJOR_CITY)
		{
			if (isCairoOrAlexandria(name)){
				addFortCairoAlexandra(v);
			}
			else {
				addFortMajorCity(v[HEX_NUMBER], v[MAP_SECTION]);
			}
		}
	}
}

bool Forts::isCairoOrAlexandria(const std::string& name)
{
	string lowerCased;

	lowerCased.resize(name.size());

	std::transform(name.begin(),
		name.end(),
		lowerCased.begin(),
		::tolower);

	bool isBigCity = false;
	if (lowerCased == CAIRO || lowerCased == ALEXANDRIA)
	{
		isBigCity = true;
	}
	return isBigCity;
}

TerrainTypes Forts::getLevelOfFort(const string& section, const string& hexNumber)
{
	return locationAndLevel[section + hexNumber];
}

void Forts::addFortMajorCity(string& hexNumber, string& mapSection)
{
	locationAndLevel.emplace(pair<string, TerrainTypes>(trim(mapSection) + trim(hexNumber), FORT_LEVEL_TWO));
}

void Forts::addFortCairoAlexandra(vector<string>& v)
{
	locationAndLevel.emplace(pair<string, TerrainTypes>(trim(v[MAP_SECTION]) + trim(v[HEX_NUMBER]),
		FORT_LEVEL_THREE));
}

void Forts::degradeFort(const std::string& sectionAndNumber)
{
	const TerrainTypes tt = locationAndLevel[sectionAndNumber];

	if (isFortDegradable(tt))
	{
		int fortLevel = static_cast<int>(tt);
		locationAndLevel.emplace(pair<string, TerrainTypes>(sectionAndNumber,
			static_cast<TerrainTypes>(--fortLevel)));
	}
}

// TODO: this couples this code to the order of the terrain effects chart.
bool Forts::isFortDegradable(const TerrainTypes& tt)
{
	bool degradable = false;
	if (tt >= FORT_LEVEL_ONE && tt < ENEMY_MINEFIELD)
	{
		degradable = true;
	}
	return degradable;
}


