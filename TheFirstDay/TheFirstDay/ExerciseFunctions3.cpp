// Hooman Malekzadeh b9055911 01/10/2019
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

double Quotient(double x, int y)
{

	return x / y;

}
void MyFunction(int x, int y)
{
	int b = x*y;
	cout << b;

}

float Add(float x, float y) {

	return x + y;

}

float Sub(float x, float y) {

	return x - y;

}

float Product(float x, float y) {

	return x * y;

}

float Devide(float x, float y)
{
	return x / y;

}
void Exercise3()
{

	//Exercise 1
	MyFunction(2, 3);
	cout << "\n";
	//Exercise2 
	cout << Quotient(5, 3) << "\n";
	//Exercise3
	cout << "Your First Number:";
	float a;
	cin >> a;
	cout << "Your Second Number:";
	float b;
	cin >> b;
	cout << "Please Select Your Operand:";
	char c;
	cin >> c;
	float answer;
	switch (c)
	{
	case '+': answer = Add(a, b); break;

	case '-': answer = Sub(a, b); break;
	case '/': answer = Devide(a, b); break;
	case '*': answer = Product(a, b); break;
	default:
		break;
	}

	cout << "The Answer is:" << answer << "\n";


}



