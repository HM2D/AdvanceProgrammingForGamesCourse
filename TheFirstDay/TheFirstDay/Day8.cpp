#include <iostream>


using namespace std;


class Enemy {
public:
	Enemy(int hps);
	virtual ~Enemy() { delete score; };
	virtual int get_hit_points() =0;
	virtual int get_score() { return *score; };

protected:
	int hit_points;
	int* score;

};

Enemy::Enemy(int hps): 
	hit_points(hps) {
	score = new int(0);

}
class ArmedEnemy : public Enemy {

public:
	ArmedEnemy(int hps, int ammo);
	virtual ~ArmedEnemy();
	virtual void set_score(const int new_score);
	virtual int get_Ammo();
	virtual void shoot();
	virtual int get_hit_points() { return hit_points; };
protected:
	int ammo_level;
};

ArmedEnemy::ArmedEnemy(int hps, int ammo):
	Enemy(hps), ammo_level(ammo) {


	};

ArmedEnemy::~ArmedEnemy() {

};
int ArmedEnemy::get_Ammo() {
	return ammo_level;

}
void ArmedEnemy::set_score(const int new_score) {
	*score = new_score;
};

void ArmedEnemy::shoot() {
	if (ammo_level > 0) {
		ammo_level--;
		cout << "Shot!";

	}
	else cout << "No Ammo";

};

class Boss : public ArmedEnemy {
public:
	Boss(int hps, int ammo, int armor);
	virtual ~Boss() {};
	virtual void set_armor(int armor);
	virtual int get_armor();
	virtual int get_hit_points() { return hit_points; };
protected:
	int armor;



};

Boss::Boss(int hps, int ammo, int armor) :
	ArmedEnemy(hps,ammo), armor(armor) {};
void Boss::set_armor(int a) {
	armor = a;


}
int Boss::get_armor() {
	return armor;

}

/*
class Base {
public:
	Base();
	virtual ~Base() {};
	virtual int getInt()=0;
	virtual void setInt(int theInt) {};
protected:
	int myInt;
};

Base::Base() {}

class Derived : public Base {
public:
	Derived(int theInt);
	virtual ~Derived() {};
	virtual int getInt();
	virtual void setInt(int theInt, int value);
protected:
	int myInt;
	int value;
};

Derived::Derived(int theInt):
myInt(theInt){


}

int Derived::getInt() {


	return myInt;
}
void Derived::setInt(int theInt,int value) {
	
	myInt = theInt;

}

*/


int getHitPoints(Enemy* enemy) {
	return enemy->get_hit_points();


}

class Comparable {
public:
	Comparable(int n):value(n) {};
	~Comparable() {};
	virtual int get_Value() { return value; };
	virtual int compare_to(const Comparable& rhs) = 0;
	virtual void SetRight(Comparable* right) { this->right = right; }
	virtual void SetLeft(Comparable* left) { this->left = left; }

	virtual Comparable* GetRight() { return right; }
	virtual Comparable* GetLeft() { return left; }
	int value;

	Comparable* right;
	Comparable* left;
	//Comparable* parent;
};

class Derived : public Comparable {

public:
	Derived(int n):Comparable(n) {};
	~Derived(){};
	virtual int compare_to(const Comparable& rhs);


};


void InsertValue(Comparable* &P,Derived* New) {
	if (P == NULL) {
		
		P = New;
		P->SetLeft(NULL);
		P->SetRight(NULL);
	}
	else if (!P->compare_to(*New)) {
		InsertValue(P->left, New);

	}
	else if (P->compare_to(*New)) {
		InsertValue(P->right, New);

	}
}

void PrintMe(Comparable* C) {



	if (C == NULL)
		return;
	PrintMe(C->GetLeft());

	cout << C->get_Value() << endl;

	PrintMe(C->GetRight());



}

void TerminateDerives(Comparable* C) {


	if (C == NULL)
	{
		// tree = root;
		return;
	}
	if (C->GetLeft() != NULL) {
		TerminateDerives(C->GetLeft());
		delete C->GetLeft();



	}
	if (C->GetRight() != NULL) {
		TerminateDerives(C->GetRight());
		delete C->GetRight();



	}

}


int Derived::compare_to(const Comparable& rhs) {
	
	if (this->get_Value() > rhs.value) {
		return 1;
	}
	else if (this->get_Value() == rhs.value) {

		return 0;
	}
	else {

		return -1;
	}


};

void Day8() {
ArmedEnemy** ArmedEnemies = new ArmedEnemy* [11];
	for (int i = 0; i < 10; i++)
	{
		ArmedEnemies[i] = new ArmedEnemy(100, i);

	}
	ArmedEnemies[10] = new Boss(100, 10, 100);
	for (int i = 0; i < 11;i++) {
		cout << getHitPoints(ArmedEnemies[i]) << endl;
	
	}
	delete[] ArmedEnemies;
	ArmedEnemies = NULL;



/////////////////////////////////////////////////////////////////////
	cout << "Start of BST:" << endl;
	Comparable* Root = NULL;
	Derived** Node = new Derived*[10];
	
	for (int i = 0; i < 10; i++) {
		Node[i] = new Derived(i);
		InsertValue(Root, Node[i]);
	}
	//PrintMe(Root);
	//cout << D->compare_to(*B);


}