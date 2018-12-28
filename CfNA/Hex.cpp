#include "Csv.h"
#include "Hex.h"
#include "assert.h"
#include <string>

using namespace csv;
using namespace std;
using namespace hex;

const std::map<std::string, HexSide> Hex::terrainStringToEnumTable = {
  { "NW", NW },
  { "NE", NE },
};

Hex::Hex(int q_, int r_, int s_) : q(q_), r(r_), s(s_) {
	assert(q + r + s == 0);
}


Hex::Hex() : q(0),r(0),s(0){}

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
	return Hex(a.q + b.q, a.r + b.r, a.s + b.s);
}


