#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\CfNA\TerrainEffectsChart.h"

#include <string>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace TerrainEffectsChart;
using namespace std;

namespace test
{		
	TEST_CLASS(Test_TerrainEffectsChart)
	{
	public:
		
		TEST_METHOD(CPA)
		{
			Chart tec;
			
			// Given a row name and a column name, return the value
			string value = tec.readChart(CLEAR, MOTORIZED);
			Assert::AreEqual(value, string("2"));
		}

	};
}