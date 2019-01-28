#include "Theater.h"
#include "MapSection.h"
#include "TerrainEffectsChart.h"

#include <map>
#include <string>

using namespace std;
using namespace mapsection;
using namespace TerrainEffectsChart;

Theater::Theater()
{
}


Theater::~Theater()
{
}

void Theater::buildTheater()
{
	mapsection::MapSection ms;
	const Chart c;
	ms.buildAMapSection(std::string("B"), c);
	sections.insert(pair<string, MapSection>(string("B"), ms));
}
