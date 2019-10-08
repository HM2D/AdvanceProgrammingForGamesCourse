#include <iostream>

using namespace std;

class Car {

public:
	Car(int colorNumber);
	//~Car();
	void ChangeColor(int colorNumber);
	string MyColor();
private:
	string colors[5] = { "Red", "Blue", "Black","Yellow","Orange" };
	int colorNumber = 0;



};

Car::Car(int colorNumber):
colorNumber(colorNumber){
	}
string Car::MyColor() {
	return this->colors[this->colorNumber];
}
void Car::ChangeColor(int colorNumber) {
	this->colorNumber = colorNumber;
}
//Car::~Car() { delete Car; }



void Day7Part2() {

	Car myCar(0);
	cout << myCar.MyColor().c_str() << endl;
	myCar.ChangeColor(2);
	cout << myCar.MyColor().c_str() << endl;



}