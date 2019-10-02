#include <iostream>


using namespace std;

 
int main() {
	auto y = [](auto x, auto b) {

		return x + b;


	};


	cout << y(10,10) << endl;

	cout << y(2.2, 2);
	return 0;

}