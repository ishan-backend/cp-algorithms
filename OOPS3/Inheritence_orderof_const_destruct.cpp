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


// PART 2:



#include<bits/stdc++.h>
using namespace std;

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

	//Car default constructor
	Car(int x):Vehicle(x)	// this constructor calls vehicle class constructor
	{
		// x is passed to vehicle class constructor e.g. Car(): Vehicle(50){}, but in main only, Car c;
		cout<<"Cars deafault constructor calling vehicle constructor, thus initialising vehicles properties before inheriting it";
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
	Car c(50);	// constructor of car class called
}

/* OUTPUT:

Vehicle par Constructor
Cars deafault constructor calling vehicle constructor, thus initialising vehicles properties before inheriting it
Car's destructor
Vehicle's destructor


*/

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

class HondaCity : public Car{
public:
	HondaCity(int x, int y):Car(x, y)
	{
		cout<<"Honda city constructor"<<endl;
	}

	~HondaCity()
	{
		cout<<"Honda City destructor"<<endl;
	}
};

int main()
{
	HondaCity h(4, 5);
}

/* OUTPUT:

Vehicle par Constructor
Cars constructor calling vehicle constructor, thus initialising vehicles properties before inheriting it
Honda city constructor
Honda City destructor
Car's destructor
Vehicle's destructor


*/


