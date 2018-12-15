#include "stdafx.h"
#include "CppUnitTest.h"
#include "Csv.h"

#include <string>
#include <iostream>
#include <regex>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace csv;
using namespace std;

namespace test
{
	TEST_CLASS(MAP)
	{
	public:

		TEST_METHOD(givenCsvFileName_thenReturnTableOfStrings)
		{
			string mapB = "D:\\CfNA\\ChartsAndTables\\MapBTerrainInHex.csv";
			vector<vector<string>> results = readCsv(mapB);
			vector<string> row;
			row = results[80];
			Assert::AreEqual(row[0], string("4706-4710"));
		}
	};
}
