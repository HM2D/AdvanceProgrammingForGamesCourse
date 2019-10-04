#include <iostream>
#include <sstream>
using namespace std;



void swap(int* a, int* b) {
	int  c;
	c = *a;
	*a = *b;
	*b = c;
	
}


void ex4lecture5(int *x) {
	for (int i = 0; i < 5; i++)
	{
		x++;
		cout << *x << ",";
		x++;
		
	}
	cout << endl;

}

void practice() {

	std::string otherString{ "HelloThere!" };
	
	char myChar = 'a';
	char* myPointerToChar = &myChar;
	string** myPointerToPointer = new string*[3];
	for (int i = 0; i < 3; i++) {
		myPointerToPointer[i] = new string[3];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			stringstream res;
			res << "This is RowNumber:" << i << " " << "This is columnNumber:" << j;
			myPointerToPointer[i][j] = res.str();

		}


		



	}


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << myPointerToPointer[i][j] << ",\t";
		}
		cout << endl;
	}



	cout << endl;
	string** myThirdPointer = myPointerToPointer;
	string* myforthPointer = *myThirdPointer;
	for (int i = 0; i < 3; i++) {

		for (int j	 = 0; j < 3; j++) {
			cout << **myThirdPointer << "\t";
			
			++* myThirdPointer;
		
		}
		cout << endl;
		++myThirdPointer;

	}
	cout << endl;



	int x = 10;
	int y = 20;
	int* a = &x;
	int* b = &y;
	cout << "Before Swap X:" << x << " Y:" << y << endl;
	swap(a, b);
	cout << "After Swap X:" << x << " Y:" << y << endl;


	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	ex4lecture5(arr);










	

}