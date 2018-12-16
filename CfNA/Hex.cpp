#include "Hex.h"
#include "assert.h"


Hex::Hex(int q_, int r_, int s_) : q(q_), r(r_), s(s_) {
	assert(q + r + s == 0);
}


Hex::Hex() : q(0),r(0),s(0){}

Hex::~Hex()
{
}

Hex Hex::add(Hex a, Hex b) {
	return Hex(a.q + b.q, a.r + b.r, a.s + b.s);
}

