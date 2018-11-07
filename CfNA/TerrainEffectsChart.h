#pragma once
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
		void LoadTerrainEffectsChartCsv();
	
	};

}