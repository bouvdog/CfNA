#pragma once
#include <string>
#include <map>
#include "TerrainEffectsChart.h"

namespace forts
{
	class Forts
	{
		// format of string is [A-E](\d{4}). Example: "B3520"
		std::map<std::string, TerrainEffectsChart::TerrainTypes> locationAndLevel;

		void addFortMajorCity(const std::string& hexNumber, const std::string& mapSection);

	public:
		Forts();
		~Forts() = default;

		TerrainEffectsChart::TerrainTypes getLevelOfFort(const std::string& section,
			const std::string& hexNumber);

	};
}

