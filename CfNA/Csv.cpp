#include "Csv.h"
#include <string>
#include <regex>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
using namespace csv;

	vector<string> csv::split(const string str, const regex regex)
	{
		vector<string> result;

		const sregex_token_iterator end;

		for (sregex_token_iterator it(str.begin(), str.end(), regex, -1); it != end; it++)
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
			rows.emplace_back(split(line, COMMA));
		}
		return rows;
	}