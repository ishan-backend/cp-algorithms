// Virtual Functions: present in base class and overriden in derived class



// Pure Virtual Functions: a function that has dont have any definition
//Syntax:
// virtual void print() = 0; 

// Any class that uses pure virtual functions becomes an abstract class.
// Abstract means incomplete. as, print() hasn't any defintion
// we cant create object of vehicle class
class Vehicle()
{
public:
	string color;

	// normal virtual function
	// virtual void print()
	// {
	// 	cout<<"print"<<endl;
	// }

	//pure virtual function
	virtual void print() = 0;


};


// When a class inherits abstract class, it has two options:
// 1. implement all the pure virtual functions (add their definition) of base class in derived class
// 2. if doesn't implement, then derived class also becomes abstract class.


class Car: public Vehicle{

public:
	string color;

	// choice 1: thus now car is a normal class
	void print()
	{
		cout<<"Car"<<endl;
	}

	//choice 2: dont define print(), then car is an abstract class
	

}

int main()
{
	Vehicle v; //error Vehicle is an abstract class

	Car c;

}


// use case
// employee->(hr, manager, engineers, others)
// employee has calculateSalary() function
// so since salary function will have different definitions for diff positions
// so it should be pure virtual function 
