// Hooman Malekzadeh b9055911 01/10/2019
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
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


void print(vector<float>& v) {
	for (const auto& e : v)
	{
		cout << e << "\t";

	}
	cout << endl;



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
	float a = 1;
	//cin >> a;
	cout << "Your Second Number:";
	float b = 1;
	//cin >> b;
	cout << "Please Select Your Operand:";
	char c = '+';
	//cin >> c;
	int temp = 0;
	

	int evenNumbers =0;
	vector<float> v(10, 0);
	generate(v.begin(), v.end(), [&]() mutable { int n = a + b; a = b; b = n; if (n % 2 == 0)evenNumbers++; return n; });
	
	print(v);


	cout << "The evenNumbers: " << evenNumbers << endl;
	auto x = [=] ()mutable{ return a + b; }();
	auto y = [](auto a, auto b) { return a - b; }(a,b);
	auto z = [](auto a, auto b) { return a / b; }(a,b);
	auto w = [](auto a, auto b) { return a * b; }(a,b);
	float answer;
	switch (c)
	{
	case '+': answer = x;  break;
	case '-':  answer = y; break;
	case '/': answer = z;  break;
	case '*': answer = w; break;
	default:  answer = 0;
		break;
	}

	cout << answer;
	



}



