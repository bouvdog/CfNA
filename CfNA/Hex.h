#pragma once

#include "TerrainEffectsChart.h"

#include <string>

namespace hex {
	const enum HexSide {
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
		static const std::map<std::string, HexSide> terrainStringToEnumTable;

		Hex(int q_, int r_, int s_);
		Hex();
		~Hex();

		int hexNumber;
		Hex add(Hex a, Hex b);
		int moveInto(const int hexNumber, const HexSide);
		int moveOutOf(const int hexNumber, const HexSide);
	};
}


