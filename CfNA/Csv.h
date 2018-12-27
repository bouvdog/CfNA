#pragma once
#include <string>
#include <regex>
#include <vector>

namespace csv
{
	const std::regex COMMA("[,]+");
	const std::regex DASH("[-]");

	std::vector<std::string> split(const std::string str, const std::regex regex);
	std::vector<std::vector<std::string>> readCsv(std::string fileName);
}
