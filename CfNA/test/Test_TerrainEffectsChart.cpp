#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\TerrainEffectsChart.h"

#include <string>
#include <iostream>
#include <regex>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace TerrainEffectsChart;
using namespace std;


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
			vector<string> results = tec.split(sample, space);
			Assert::AreEqual(results.at(0), string("quick"));
		}
		
		TEST_METHOD(givenRowAndColumn_returnValue)
		{
			Chart tec;
			string value = tec.readChart(CLEAR, MOTORIZED);
			cout << value << endl;
			Assert::AreEqual(value, string("2"));
		}

		TEST_METHOD(givenValueWithNote_returnPair)
		{
			Chart tec;
			vector<string> oneHeader;
			oneHeader.emplace_back("stacking limit^1");
			vector<pair<string, string>> results;
			results = tec.buildHeaders(oneHeader);
			Assert::AreEqual(results.front().first, STACKING_LIMIT);
			Assert::AreEqual(results.front().second, string("1"));

			oneHeader.clear();
			oneHeader.emplace_back(BARRAGE);
			results = tec.buildHeaders(oneHeader);
			Assert::AreEqual(results.front().first, BARRAGE);
			Assert::IsTrue(results.front().second.empty());
		}

	};
}