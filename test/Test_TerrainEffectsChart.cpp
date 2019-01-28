#include "CppUnitTest.h"
#include "../CfNA/TerrainEffectsChart.h"

#include <string>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace TerrainEffectsChart;
using namespace std;


// TODO: refactor given-when-then syntax for test names
namespace test
{		
	TEST_CLASS(chart)
	{
	public:
		
		TEST_METHOD(givenTEC_readValuesFromChart)
		{
			Chart tec;

			// Given a terrain type and a 'column' return the value
			auto value = tec.readChart(CLEAR, MOTORIZED);
			Assert::AreEqual(value, string("2"));
		}

		TEST_METHOD(givenAShiftsString_thenConvertToNumber)
		{
			int numShifts = covertShiftsToNumber(string("L1"));
			Assert::AreEqual(numShifts, 1);

			numShifts = covertShiftsToNumber("foobar");
			Assert::AreEqual(numShifts, 0);
		}

	};
}