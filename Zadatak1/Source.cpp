#include <iostream>
#include "Path.h"
#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

int main() {
	unsigned Ax, Ay, Bx, By;

	cout << "A redak: ";
	cin >> Ay;
	cout << "A stupac: ";
	cin >> Ax;

	cout << "B redak: ";
	cin >> By;
	cout << "B stupac: ";
	cin >> Bx;

	Path path{ Ax, Ay, Bx, By };

	while (!path.step()) {
		if (system("CLS")) system("clear");
		path.print();
		sleep_for(milliseconds(100));
	}





	return 0;
}