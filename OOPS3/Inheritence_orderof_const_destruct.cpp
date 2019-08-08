// PART 1:

#include<bits/stdc++.h>
using namespace std;

// NOTE: before creating object of Car class, we need to create an object of Vehicle class
// and initialise its properties which are inherited by car class


class Vehicle{
private:	
	int maxSpeed;

protected:	
	int  numTyres;

public:		
	string color;

	Vehicle()
	{
		cout<<"Vehicle's default constructor"<<endl;
	}

	~Vehicle()
	{
		cout<<"Vehicle's destructor"<<endl;
	}

};

class Car : public Vehicle{
public:
	int numGears;

	Car()
	{
		cout<<"Car's default constructor"<<endl;
	}

	~Car()
	{
		cout<<"Car's destructor"<<endl;
	}

	void print()
	{
		cout<<"numTyres" << numTyres<<endl;
		cout<<"Color:" << color<<endl;
		
	}
};

int main()
{
	Vehicle v;	// constructor of Vehicle class called
	v.color = "Blue";


	Car c;	// constructor of car class called
	c.color = "Black";	
	c.numGears = 5;
}

/* OUTPUT:

Vehicle's default constructor	-- for v is created
Vehicle's default constructor	-- for c is created (parent)
Car's default constructor		-- same (child)
Car's destructor				-- for c is destroyed(child)
Vehicle's destructor			-- same (parent)
Vehicle's destructor			-- for v is destroyed

*/
