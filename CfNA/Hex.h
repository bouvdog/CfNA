#pragma once

#include "TerrainEffectsChart.h"

#include <string>


enum HexSides {
	NW,
	NE,
	E,
	SE,
	SW,
	W
};


class Hex
{
public:
	Hex();
	~Hex();

	int hexNumber;
	TerrainEffectsChart::TerrainTypes terrainInHex;


};


