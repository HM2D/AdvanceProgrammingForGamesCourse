#include <iostream>


using namespace std;



bool ex1(int x) {

	if (x >= 0)
		return true;
	else return false;

}


void ex2() {

	while (true) {

		int x;
		cin >> x;

		if (ex1(x))
			continue;
		else break;
	}





}

int answer = 1;
int factorialRecursive(int x) {
	
	if (x == 0)
		return answer;
	answer *= x;
	factorialRecursive(x - 1);




}


void Exercise4() {
	

	//ex2();
	factorialRecursive(4);
	cout << answer;



}