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
void insert_integer(struct node* &tree, int value);

void terminate_tree(struct node* &tree);

void print_tree(node* tree);

void Day5() {


	node* tree= root;
	insert_integer(tree, 5);
	insert_integer(tree, 2);
	insert_integer(tree, 3);
	insert_integer(tree, 4);
	//print_tree(tree);
	
	terminate_tree(tree);
	tree = root;
	print_tree(tree);

}


void print_tree(node* tree) {



	if (tree == NULL)
		return;
	
	print_tree(tree->left);
	cout << tree->value << endl;
	
	print_tree(tree->right);



}

void insert_integer(node* &tree, int value) {
	if (tree == NULL) {
	
		tree = new node;
		tree->value = value;
		tree->left = NULL;
		tree->right= NULL;
		tree->parent = NULL;

	}
	else if (value > tree->value) {
		insert_integer(tree->right, value);

	}
	else if (value <  tree->value) {
		insert_integer(tree->left, value);

	}




}


void terminate_tree(struct node* &tree) {


	if (tree == NULL)
	{
		// tree = root;
		return;
	}
	 if (tree->left != NULL) {
		terminate_tree(tree->left);
		delete tree->left;



	}
	if (tree -> right != NULL) {

		terminate_tree(tree->right);
		delete tree->right;


	}






}








