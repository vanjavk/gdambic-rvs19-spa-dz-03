#pragma once
#include <array>
#include <iostream>
using namespace std;
class Path
{
public:
	Path(unsigned Ax, unsigned Ay, unsigned Bx, unsigned By) : Ax{Ax-1}, Ay{Ay-1}, Bx{Bx-1}, By{By-1}, Xx{Ax-1}, Xy{Ay-1} {}
	bool step();
	void print();
private:
	unsigned Ax, Ay, Bx, By, Xx, Xy;
	const unsigned kHeight = 20;
	const unsigned kWidth = 40;
};

