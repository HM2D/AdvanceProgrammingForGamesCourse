#include <iostream>

using namespace std;

int recF(int y) {

	if (y < 20) {
		cout << "recF (1) = " << y << endl;
		return (recF(y + 1));
	}
	cout << "recF (2) = " << y << endl;
	return y;
}

int recA(int y) {

	if (y < 20) {
		cout << "recA (1) = " << y << endl;
		return (recF(recF(y + 1)));
	}
	cout << "recA (2) = " << y << endl;
	return y;
}


int recB(int y) {

	if (y < 20)
		recB(y + 1);
	cout << "recB = " << y << endl;
	return y;
}

int recD(int y) {

	if (y < 20) {
		return (recB(recB(y + 1)));
	}
	cout << "recD = " << y << endl;
	return y;
}


void Day5() {
	int x = 10;
	recF(x);
	cout << "-----" << endl;

	int y = 10;
	recB(y);
	cout << "-----" << endl;

	int z = 10;
	recA(z);
	cout << "-----" << endl;

	int q = 10;
	recD(q);
}