#include "Csv.h"
#include "Hex.h"
#include <cassert>
#include <string>

using namespace csv;
using namespace std;
using namespace hex;


map<string, HexSide> buildHexSideStringToEnum()
{
	std::map<std::string, HexSide> sides;
	for (int i = 0; i < 6; i++)
	{
		sides.insert(
			pair<string, HexSide>(hexSideStrings[i], static_cast<HexSide>(i)));
	}
	return sides;
}

map<string, HexSide> Hex::hexSideStringToEnumTable = buildHexSideStringToEnum();


HexSide Hex::hexSideStringToEnum(string terrainString)
{
	return hexSideStringToEnumTable[trim(terrainString)];
}

int hex::Hex::getQ()
{
	return q;
}

int hex::Hex::getR()
{
	return r;
}

int hex::Hex::getS()
{
	return s;
}

Hex::Hex(int q_, int r_, int s_, int h_) : q(q_), r(r_), s(s_), hexNumber(h_) {
	assert(q + r + s == 0);
}

Hex::Hex() : q(0),r(0),s(0), hexNumber(0){}

Hex::~Hex()
{
}

int Hex::moveInto(const int hexNumber, const HexSide crossingSide) {
	// Lookup the crossingSide terrain by hexNumber in the hex side terrain map
	return 0;
}

int Hex::moveOutOf(const int hexNumber, const HexSide) {
	return 0;
}

Hex Hex::add(Hex a, Hex b) {
	return Hex(a.q + b.q, a.r + b.r, a.s + b.s, 0);
}


