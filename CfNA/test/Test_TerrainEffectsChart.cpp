#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\TerrainEffectsChart.h"

#include <string>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace TerrainEffectsChart;
using namespace std;


namespace test
{		
	TEST_CLASS(TEC)
	{
	public:
		
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
			Logger::WriteMessage(results.front().second.c_str());
			//Assert::AreEqual(results.front().second, string(""));
		}

	};
}