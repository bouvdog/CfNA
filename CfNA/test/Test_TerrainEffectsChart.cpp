#include "stdafx.h"
#include "CppUnitTest.h"
#include "TerrainEffectsChart.h"
#include "Csv.h"


#include <string>
#include <iostream>
#include <regex>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace TerrainEffectsChart;
using namespace std;
using namespace csv;


namespace test
{		
	TEST_CLASS(TEC)
	{
	public:

		TEST_METHOD(givenString_thenReturnVectorOfSubstrings)
		{
			Chart tec;
			string sample = "quick fox";
			regex space("\\s");
			vector<string> results = split(sample, space);
			Assert::AreEqual(results.at(0), string("quick"));
		}
		
		TEST_METHOD(givenRowAndColumn_returnValue)
		{
			Chart tec;
			tec.loadTerrainEffectsChartCsv();
			string value = tec.readChart(CLEAR, MOTORIZED);
			Assert::AreEqual(value, string("2"));
		}

		TEST_METHOD(givenValueWithNote_returnPair)
		{
			Chart tec;
			vector<string> oneHeader;
			oneHeader.emplace_back("stacking limit^1");
			vector<pair<string, string>> results;
			results = tec.buildTableRow(oneHeader);
			Assert::AreEqual(results.front().first, string(movementOrCombatStrings[STACKING_LIMIT]));
			Assert::AreEqual(results.front().second, string("1"));

			oneHeader.clear();
			oneHeader.emplace_back(movementOrCombatStrings[BARRAGE]);
			results = tec.buildTableRow(oneHeader);
			Assert::AreEqual(results.front().first, string(movementOrCombatStrings[BARRAGE]));
			Assert::IsTrue(results.front().second.empty());
		}

		// TODO: resolve on a 'standard' for plural versus singular names for a collection (array,vector, etc). 
		TEST_METHOD(givenString_returnEnum)
		{
			Chart tec;
			string s(terrainTypesStrings[19]);
			TerrainTypes t = tec.terrainStringToEnum(s);
			Assert::AreEqual(static_cast<int>(t), static_cast<int>(WADI));
		}

	};
}