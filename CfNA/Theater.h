#pragma once
#include "MapSection.h"

class Theater
{
public:
	Theater();
	~Theater();

	std::map<std::string, mapsection::MapSection> sections;

	void buildTheater();
};

