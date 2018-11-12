#pragma once
#include <map>

namespace TerrainEffectsChart
{


	// Ideally, we only want one of these but putting in a singleton is over-kill. This decision
	// we will be reflected in all the 'chart objects'
	class Chart
	{
	public:
		Chart();
		~Chart();

	private:
		const map<string, map<string, string>> chartTable;
		void LoadTerrainEffectsChartCsv();
	
	};

}