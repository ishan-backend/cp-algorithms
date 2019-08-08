// Inheritence : to avoid writing common properties in different classes.
// add other properties to classes that are specific to those.

// Access Modifiers: private, public, protected.
// in a class:
// public: accessible by anyone
// private: used only by this class
// protected: used by this class and,are accessible outside this class but only by using its child classes.

#include<bits/stdc++.h>
using namespace std;


class Vehicle{
private:	// are not inherited by its child class
	int maxSpeed;

protected:	// are inherited by child class only under protected access modifier
	int  numTyres;

public:		// are availiable to child class
	string color;



};

//new class name :: access_specifier class_to_be_inherited
class Car : public Vehicle{
public:
	int numGears;
// Car has three properties: protected and public of Vehicle class.

	void print()
	{
		cout<<"numTyres" << numTyres<<endl;
		cout<<"Color:" << color<<endl;
		//cout<<"Max Speed"<< maxSpeed<<endl;	//	not accessible, as its not inherited
	}
};

int main()
{
	Vehicle v;

	v.color = "Blue";
	//v.maxSpeed = 100; // gives error, class ke bahar private properties aren't accessible
	//v.numTyres = 4;	// gives error, because protected members are accessible outside the class but only through derived classes


	Car c;
	c.color = "Black";	//accessible
	//c.numTyres = 4;	// error, protected property can be used only in derived classes , not outside it.
	c.numGears = 5;
}

// NOTE: if we inherited Vehicle class in Car class using protected ACCESS MODIFIER,
// then in Car class, Vehicle ke public and protected are inherited in protected of car class

// if we inherit Vehicle class in Car class using private ACCESS MODIFIER
// then protected and public members of Vehicle become private members of Car class.


// if we dont mention access specifier during inheritence, by default it is private.
