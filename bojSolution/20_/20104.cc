#include "timecard.h"

static int N;

void init(int n) {
	N = n;
}

std::string convert(std::string s) {
	std::string r = "";
	for (char c : s) {
		if (c <= 'Z') r += char(c + 32);
		else r += c;
	}
	return r;
}