// 1. Single Inheritence: A->B
// 2. Multilevel Inheritence: A->B->C->.....
// 3. Hierarchical Inheritence:  A->(B, C, D)
// 4. Multiple Inheritence: (A, B, C)->D


#include<bits/stdc++.h>
using namespace std;

// MULTILEVEL INHERITENCE:
class Vehicle{
private:	
	int maxSpeed;

protected:	
	int  numTyres;

public:		
	string color;

	// Vehicle class parametrized constructor
	Vehicle(int z)
	{
		cout<<"Vehicle par Constructor"<<endl;
		maxSpeed = z;
	}

	~Vehicle()
	{
		cout<<"Vehicle's destructor"<<endl;
	}

};

class Car : public Vehicle{
public:
	int numGears;
	
	
	// NOTE: a class can only call constructor of its immediate parent
	Car(int x, int y):Vehicle(x)
	{	
		cout<<"Cars constructor calling vehicle constructor, thus initialising vehicles properties before inheriting it"<<endl;
		numGears = y;
	}

	~Car()
	{
		cout<<"Car's destructor"<<endl;
	}

	void print()
	{
		cout<<"numTyres" << numTyres<<endl;
		cout<<"Color:" << color<<endl;
		cout<<"numGears:"<< numGears<<endl;
	}
};

class Truck: public Vehicle{

}

//MULTIPLE INHERITENCE:
class Teacher{
public:
	string name;
	string age;
	void print()
	{
		cout<<"Teacher"<<endl;
	}
};

class Student{
public:
	void print()
	{
		cout<<"Student"<<endl;
	}
};

class TA: public Teacher, public: Student{	// access_modifier first class, access_modifier second class

// on creating TA 's object, firstly Teacher class constructor is called, then Student class constructor is called
// then TA class constructor is called
};

int main()
{
	TA a;

	a.print();
	// konsa wala print function call hoga? 
	// since print occurs in multiple base classes
	// => need to specify using class name ans scope resolution
	a.Student :: print();
}


// Other case: when TA also has print function
class TA: public Teacher, public: Student{	

	void print()
	{
		cout<<"TA"<<endl;
	}
};

int main()
{
	TA a;

	a.print();
	// now firstly print() is checked in TA class , so no error is reported.
	// object doesnt search for print() in base classes as it finds it first in TA class
}


