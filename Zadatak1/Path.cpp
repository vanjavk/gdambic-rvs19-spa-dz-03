#include "Path.h"

void Path::print()
{
	for (unsigned i = 0; i < kHeight; ++i) {
		for (unsigned j = 0; j < kWidth; ++j) {
			if (j == Xx && i == Xy) {
				cout << 'x';
			} else if (j == Ax && i == Ay) {
				cout << 'A';
			}
			else if(j == Bx && i == By) {
				cout << 'B';
			}
			else {
				cout << '-';
			}
		}
		cout << endl;
	}
}

bool Path::step()
{
	if (Xx > Bx) {
		--Xx;
		return false;
	}
	else if (Xx < Bx) {
		++Xx;
		return false;
	}
	else if (Xy > By) {
		--Xy;
		return false;
	}
	else if (Xy < By) {
		++Xy;
		return false;
	}
	return true;
}
