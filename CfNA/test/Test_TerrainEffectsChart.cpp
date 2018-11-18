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
			string value = tec.readChart(string("foobar"), MOTORIZED);
			cout << value << endl;
			Assert::AreEqual(value, string("2"));
		}

	};
}