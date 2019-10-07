#include <iostream>


using namespace std;


namespace mySpace {
	int some_function() {
	
		int x = 10;
		return x;
	}



}

int some_other_function() {
	int x = 11;
	
	return x;
}
void Day6() {


	int x = 0;
	int& y = x;
//	y = 99;
	cout << y << endl;
	//[=]() mutable { x = 10; }();
	{
		int x = 1;
		for (int x = 0; x < 10; x++) {
			//
		}
		cout << x << endl;
		
	
	}
	cout << x << endl;

	
	cout << mySpace::some_function() << endl;
	cout << some_other_function() << endl;




}