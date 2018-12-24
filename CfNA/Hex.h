#pragma once

#include "TerrainEffectsChart.h"

#include <string>


enum HexSide {
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
	const int q, r, s;

	Hex(int q_, int r_, int s_);
	Hex();
	~Hex();

	int hexNumber;
	TerrainEffectsChart::TerrainTypes terrainInHex;

	Hex add(Hex a, Hex b);
	int moveInto(const int hexNumber, const HexSide);
	int moveOutOf(const int hexNumber, const HexSide);
};


