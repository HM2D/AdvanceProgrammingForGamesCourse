#include <iostream>

using namespace std;


struct node {
public:
	int value;
	struct node* left;
	struct node* right;
	struct node* parent;
};
struct node* root = NULL;
void insert_integer(struct node*& tree, int value);
void terminate_tree(struct node*& tree);
void print_tree(node* tree);


void findInTree(node*& tree, int value);

void setMyPointerValue(node*& p, int v);

void Day5Part2() {


	node* tree = root;
	insert_integer(tree, 5);
	insert_integer(tree, 2);
	insert_integer(tree, 3);
	insert_integer(tree, 4);
	insert_integer(tree, 1);
	insert_integer(tree, -2);
	insert_integer(tree, 10);
	insert_integer(tree, 8);
	insert_integer(tree, -4);
	//print_tree(tree);
	findInTree(tree, 10);
	//terminate_tree(tree);
	//tree = root;
	print_tree(tree);
	terminate_tree(tree);




}

void Day5Part3() {
	int size = 10;
	int* p = new int[10];


	for (int i = 0; i < size; i++) {
	
		*(p + i) = rand()%100;
	
	
	}
	//int x;
	for (int i = 0; i < size; i++) {

		cout << *(p + i) << "\t";
		//int x = *(p + 2);

	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	delete[] p;
	
	//cout << x;
	

	node* myNodePointer = new node;
	myNodePointer->value = 10;
	node* myPointerToNodePointer = myNodePointer;
	
	auto lambda = [=]() { myPointerToNodePointer->value = 2; return; };
	//lambda();
//	cout << myPointerToNodePointer->value;

	cout << myNodePointer->value;

}


void setMyPointerValue(node* &p, int v) {
	p = new node;
	p ->value = v;
	return;

}


void findInTree(node* &tree,int value) {
	if (tree == NULL) {
		cout << "Not Found!" << endl;
		return;
	}
	else if (tree->value == value) {
		cout << "found it!" << endl;
		return;
	
	}if (tree->value < value) {
		cout << "Went Right" << endl;
		findInTree(tree->right, value);

	
	}
	else if (tree->value > value) {
	
		cout << "Went Left" << endl;
		findInTree(tree->left, value);
	
	}
}

void print_tree(node* tree) {



	if (tree == NULL)
		return;
	print_tree(tree->left);

	cout << tree->value << endl;

	print_tree(tree->right);



}

void insert_integer(node*& tree, int value) {
	if (tree == NULL) {

		tree = new node;
		tree->value = value;
		tree->left = NULL;
		tree->right = NULL;
		tree->parent = NULL;

	}
	else if (value > tree->value) {
		insert_integer(tree->right, value);

	}
	else if (value < tree->value) {
		insert_integer(tree->left, value);

	}




}


void terminate_tree(struct node*& tree) {


	if (tree == NULL)
	{
		// tree = root;
		return;
	}
	if (tree->left != NULL) {
		terminate_tree(tree->left);
		delete tree->left;



	}
	if (tree->right != NULL) {

		terminate_tree(tree->right);
		delete tree->right;


	}






}








