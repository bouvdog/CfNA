#include "Csv.h"
#include <string>
#include <regex>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;
using namespace csv;

auto csv::trim(string& s) -> string&
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c); }));
	return s;
}

	vector<string> csv::split(const string str, const regex regex)
	{
		vector<string> result;

		const sregex_token_iterator end;

		for (sregex_token_iterator it(str.begin(), str.end(), regex, -1); it != end; ++it)
		{
			result.emplace_back(it->str());
		}

		return result;
	}

	vector<vector<string>> csv::readCsv(string fileName)
	{
		ifstream table(fileName);

		string line;
		vector<vector<string>> rows;
		while (getline(table, line))
		{
			// It is possible for the CSV files to have 'empty' lines (just \n)
			if (line.find(',') != string::npos)
			{
				rows.emplace_back(split(line, COMMA));
			}
		}
		return rows;
	}