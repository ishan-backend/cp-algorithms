// polymorphism : many forms
// our code behaves differently in different situations
// two types:
// 1. compile time: acheived using function and operator overloading.
// 2. run time: 


#include<bits/stdc++.h>
using namespace std;

// remember using return type, we cant differentiate functions
// we differentiate using function name, no of parameters , types of param

int test(int a, int b)
{

}

int test(int a)
{

}

int test()
{

}

int main()
{

}

// OTHER WAY TO ACHEIVE COMPILE TIME POLYMORPHISM IS:
// METHOD / FUNCTION OVERRIDING
// suppose A is base class and has print(), and B is derived class and also has print()
// then B overrides A's print()

int main()
{
	Vehicle v;
	Car c;


	// COMPILE TIME POLY: amongst many options for a function, we are choosing at compile time, which function to call , by its object


	v.print();	// calls print of vehicle class

	// when c has already been created and c.print() is called, it goes to car class and print() is found
	c.print(); //--> calls print of car class // FUNCTION OVERRIDING




	// creating pointers to vehicle class
	Vehicle* v1 = new Vehicle;	// v1 points to fresh object of vehicle class

	Vehicle* v2;

	//v2 = &v; or
	v2 = &c; 
	//THUS BASE CLASS POINTER CAN POINT TO DERIVED CLASS BUT NOT VICE-VERSA
	// v2 points to car class object created above


	v1->print(); // calls print() of vehicle class

	v2->print();	
	// now v2 points  car class
	// but when print() is called , v2 calls print() of vehicle class
	// example of compile time polymorphism

	return 0;
}
