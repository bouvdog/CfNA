#include <string>
#include <regex>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

namespace csv
{
	vector<string> split(const string str, const regex regex)
	{
		vector<string> result;

		const sregex_token_iterator end;

		for (sregex_token_iterator it(str.begin(), str.end(), regex, -1); it != end; it++)
		{
			result.emplace_back(it->str());
		}

		return result;
	}

	vector<vector<string>> readCsv(string fileName) 
	{
		ifstream table(fileName);

		string line;
		regex comma("[,]+");
		vector<vector<string>> rows;
		while (getline(table, line))
		{
			rows.emplace_back(split(line, comma));
		}
		return rows;
	}

}