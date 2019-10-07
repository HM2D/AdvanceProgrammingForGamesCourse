#include <iostream>


using namespace std;


namespace mySpace {
	int some_function() {
	
		int x = 10;
		return x;
	}



}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;


}

int nums[10] = { 7,3,5,2,1,4,6,9,10,8 };

int some_other_function() {
	int x = 11;
	
	return x;
}

void sort(int* array, int length) {

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
		
			if (array[i] < array[j]) {
				swap(array[i], array[j]);


			}

		}
		


	}




}
void Day6() {
	int a = 10;
	int b = 20;

	swap(a, b);

	cout << " A:" << a << " B: " << b << endl;

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
	
	sort(nums,10);

	for (int i = 0; i < 10; i++) {

		cout << nums[i] << "-";

	}
	

}