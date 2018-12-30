#pragma once

#include "TerrainEffectsChart.h"

#include <string>

namespace hex {
	enum HexSide {
		NW,
		NE,
		E,
		SE,
		SW,
		W
	};

	const char* const hexSideStrings[6] = {
		"NW",
		"NE",
		"E",
		"SE",
		"SW",
		"W"
	};

	
	

	class Hex
	{
	public:

		Hex(int q_, int r_, int s_);
		Hex();
		~Hex();

		static HexSide hexSideStringToEnum(const std::string);

		// TODO: get rid of these at some point; only exist for testing at this point
		int getQ();
		int getR();
		int getS();

		Hex add(Hex a, Hex b);
		int moveInto(const int hexNumber, const HexSide);
		int moveOutOf(const int hexNumber, const HexSide);

	private:
		const int q, r, s;

		int hexNumber;

		static std::map<std::string, HexSide> hexSideStringToEnumTable;

	};
}


