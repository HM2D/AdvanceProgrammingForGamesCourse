#include <iostream>


using namespace std;



template <typename T>
class Matrix {
public:
	Matrix(int xSize, int ySize);
	~Matrix();
	int getXSize() { return xSize; }
	int getYSize() { return ySize; }
	T getElement(int x, int y) { return cells[x][y]; }
	void setElement(int x, int y, T value) { cells[x][y] = value; }
	template <typename M>
	friend ostream& operator <<(ostream& ostr,const Matrix<M>& mtx);
	void printElements();
protected:
	T** cells;
	int xSize;
	int ySize;
};

template <typename T>
Matrix<T>::Matrix(int x, int y) {
	xSize = x;
	ySize = y;
	cells = new T*[x];
	for (int i = 0; i < x; i++)
		cells[i] = new T[y];

}
template <typename T>
Matrix<T>::~Matrix() {
	for (int i = 0; i < getXSize(); i++)
			delete cells[i];
	delete cells;
	cells = NULL;
	cout << "Matrix Destructed";
}

template <typename T>
void Matrix<T>::printElements(){
	for (int i = 0; i < getXSize(); i++)
	{
		for (int j = 0; j < getYSize(); j++)
			cout << cells[i][j] << "\t";
		cout << endl;
	}

}

template <typename T>
ostream& operator<<(ostream& ostr, const Matrix<T>& mtr) {
	for (int i = 0; i < mtr.xSize; i++) {
		for (int j = 0; j < mtr.ySize; j++)
			ostr << mtr.cells[i][j] << "\t";
		ostr << endl;
	}
	return ostr;
}


template <typename T>
class Node {
public:
	Node(T value);
	~Node() {};
	template <typename M>
	friend ostream& operator <<(ostream& ostr,Node<M>* node);
	Node* getLeft() { return left; }
	Node* getRight() {	return right;}
	T getValue() { return value; }
protected: 
	T value;
	Node* left = nullptr;
	Node* right = nullptr;




};

template <typename T>
ostream& operator<<(ostream& ostr, Node<T>* node) {
	if (node == NULL) {
		return ostr;
	
	}
	else {
	
		ostr<<(node->getLeft());

		ostr << node->getValue();

		ostr<<(node->getRight());
	
	
	}



}

template <typename T>
Node<T>::Node(T n) :value(n) {
	
};


template <typename T>
void insertNode(Node<T>* &node, T val) {
	if (node == NULL) {
		node = new Node<T>(val);
		
	
	}
	else if (node->getValue() > val) {
	
		insertNode(node->getLeft(), val);
	
	}
	else if (node->getValue() < val) {

		insertNode(node->getRight(), val);

	}
}





void Day9() {
	Matrix<char>* M = new Matrix<char>(3, 3);
			M->setElement(0, 0, 'a');
			M->setElement(0, 1, 'b');
			M->setElement(0, 2, 'c');
			M->setElement(1, 0, 'd');
			M->setElement(1, 1, 'e');
			M->setElement(1, 2, 'f');
			M->setElement(2, 0, 'g');
			M->setElement(2, 1, 'h');
			M->setElement(2, 2, 'i');

	M->printElements();
	Matrix<int>* M2 = new Matrix<int>(5, 5);
	for (int i = 0; i < M2->getXSize(); i++)
		for (int j = 0; j < M2->getYSize(); j++)
			M2->setElement(i, j, i);
	M2->printElements();
	cout << *M2;
	delete M;
	delete M2;
	/////////////////////////////////////
	cout << endl;
	Node<float>* rootNode = new Node<float>(5.5);
	insertNode(rootNode, (float)2.3);
	insertNode(rootNode, (float)2.3);
	insertNode(rootNode, (float)2.5);
	insertNode(rootNode, (float)6.7);
	insertNode(rootNode, (float)9.1);
	
	cout << rootNode;






}