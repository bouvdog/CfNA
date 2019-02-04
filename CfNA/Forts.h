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

		void addFortMajorCity(std::string& hexNumber, std::string& mapSection);

		static bool isFortDegradable(const TerrainEffectsChart::TerrainTypes& tt);
		bool isCairoOrAlexandria(const std::string& cs);

	public:
		void addFortCairoAlexandra(std::vector<std::string>& cityRow);
		
		Forts();
		~Forts() = default;

		TerrainEffectsChart::TerrainTypes getLevelOfFort(const std::string& section,
			const std::string& hexNumber);

		void degradeFort(const std::string& sectionAndNumber);

	};
}

