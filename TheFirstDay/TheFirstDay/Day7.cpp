#include <iostream>


using namespace std;

void Day7() {

	char myName[] = { 'H','O','O','M','A','N',' ','M','A','L','E','K','Z','A','D','E','H' };
	char* first = new char[6];
	char* last = new char[10];
	bool flag= false;
	int j = 0;
	for (int i = 0; i < 17; i++)
	{
		//cout << myName[i] << " ";
		if (myName[i] == ' ') {
			flag = true;
			continue;
		
		}else
		if (!flag)
			first[i] = myName[i];
		else {
			last[j] = myName[i];
			j++;
		}

	
	}

	for(int i =0 ; i< 6;i++)
	cout << first[i];

	cout << " ";
	for (int i = 0; i < 10; i++)
		cout << last[i];

	

cout << endl;


	const int length = 10;
	int** array = new int*[length];


	for (int i = 0; i < length; i++) {

		array[i] = new int[length];
		for (int j = 0; j < length; j++) {
		
			array[i][j] = j;

		
		}
	
	
	}


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

		 cout <<	array[i][j] << "\t";

		}
		cout << endl;

	}

	delete array;






}
void battleship() {
	bool** map = new bool* [5];
	for (int i = 0; i < 5; i++)
	{
		map[i] = new bool[5];
	}
	map[0][0] = true;
	map[2][2] = true;
	map[3][1] = true;
	map[4][0] = true;
	map[1][4] = true;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (map[i][j] == 1) {

				continue;

			}
			else map[i][j] = false;
		}
	}

	for (int i = 0; i < 5; i++) {
		int x;
		int y;
		cout << "Your row value:";
		cin >> x;
		cout << "Your column value:";
		cin >> y;
		if (x > 4 || y > 4 || x < 0 || y < 0) {
			i--;
			cout << "Out of bounds! Try again!" << endl;
			continue;
		}

		if (map[x][y]) {
			cout << "Good Shot" << endl;

		}
		else cout << "You Missed"<<endl;

	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << map[i][j] << " ";


		}
		cout << endl;
	}





}