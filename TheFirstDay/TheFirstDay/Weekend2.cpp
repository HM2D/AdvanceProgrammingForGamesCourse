#include <iostream>



using namespace std;

struct node {
public:
	int value;
	struct node* next;

};
struct node* root = NULL;
node** multiDataStructure = new node*[2];
//node* myDataStructure;

node* perviousNode;


void AddInt(node*& structure, int value);
void PrintStructure(node*& structure);
int ValueAtIndex(node*& structure, int index);
void EditIndex(node*& structure, int index, int value);
void InsertAtIndex(node*& structure, int index, int value);
void RemoveAtIndex(node*& structure, int index);
void TerminateDataStructure(node*& structure);
void InitilizeStructure(node*& structure, int value, int length);
int StructureLength(node*& structure);
void PrependToStructure(node*& structure, int value);


//node* oneToDelete;
void Weekend2() {

	multiDataStructure[0] = new node;
	multiDataStructure[1] = new node;
	InitilizeStructure(multiDataStructure[0], 0, 5);
	InitilizeStructure(multiDataStructure[1], 1, 5);
	PrependToStructure(multiDataStructure[0], 99);
	RemoveAtIndex(multiDataStructure[0], 1);
	PrintStructure(multiDataStructure[0]);
	cout << endl;
	PrintStructure(multiDataStructure[1]);
	
	delete multiDataStructure;


}


void PrependToStructure(node*& structure, int value) {

	node* newNode = new node;
	newNode->value = structure->next->value;
	newNode->next = structure->next;
	structure->value = value;
	structure->next = newNode;

	return;


}

void InitilizeStructure(node*& structure, int value, int length) {

	structure = root;
	for (int i = 0; i < length; i++)
		AddInt(structure, value);



}
static int step = 0;
int StructureLength(node*& structure) {

	if (structure == NULL)
	{
		int temp = step;
		step = 0;
		return temp;

	}
	else {
		step++;
		StructureLength(structure->next);
	}


}

void AddInt(node*& structure, int value) {

	if (structure == NULL) {
		structure = new node;
		structure->value = value;
		structure->next = NULL;
		return;


	}
	else {
		AddInt(structure->next, value);
	}




}

void InsertAtIndex(node*& structure, int index, int value) {

	if (structure == NULL) {
		cout << "Not Found" << endl;
		return;



	}
	else  if (index == 0) {
		node* newNode = new node;
		newNode->next = structure;
		perviousNode->next = newNode;
		newNode->value = value;


		return;

	}

	else {
		perviousNode = structure;
		//cout << "Value of the pervious Node:" << (*perviousNode)->value << endl;

		InsertAtIndex(structure->next, (index - 1), value);

	}


}


void EditIndex(node*& structure, int index, int value) {

	if (structure == NULL) {

		cout << "Not Found" << endl;

	}
	else  if (index == 0) {
		structure->value = value;
		//return structure->value;


	}

	else { EditIndex(structure->next, index - 1, value); }








}
void RemoveAtIndex(node*& structure, int index) {



	if (structure == NULL) {
		cout << "Not Found" << endl;
		return;



	}
	else  if (index == 0) {

		perviousNode->next = structure->next;
		//why?
		//delete perviousNode;
		//delete structure;
		return;

	}

	else {
		perviousNode = structure;
		//cout << "Value of the pervious Node:" << (*perviousNode)->value << endl;

		RemoveAtIndex(structure->next, index - 1);

	}



}

int ValueAtIndex(node*& structure, int index) {
	if (structure == NULL) {

		cout << "Not Found" << endl;
		return -1;

	}
	else  if (index == 0) {
		return structure->value;


	}

	else { ValueAtIndex(structure->next, index - 1); }




}

void PrintStructure(node*& structure) {


	if (structure == NULL) {
		return;



	}
	else {
		if (structure->next != NULL)
			cout << structure->value << " -->\t";
		else cout << structure->value;
		PrintStructure(structure->next);


	}




}
void TerminateDataStructure(node*& structure) {

	if (structure == NULL) {

		return;
	}
	else {
		TerminateDataStructure(structure->next);
		delete structure;


	}





}