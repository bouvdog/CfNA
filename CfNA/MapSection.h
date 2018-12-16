#pragma once

#include "Hex.h"

#include <vector>
#include <string>
#include <map>

class MapSection
{
public:

	std::vector<std::vector<std::string>> terrainInHex;
	std::map<int, Hex> mapSection;

	MapSection();
	~MapSection();
};

