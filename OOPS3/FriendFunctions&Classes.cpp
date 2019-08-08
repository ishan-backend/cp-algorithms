
// Problem:
/*
class Truck
{
	private:
		x
	protected:
		y
	public:
		z
}

class Bus{
	print()
	{
	cout<<x;
	}
}

*/
// we want to access private propeety of one class to be used in other class
// use FRIEND FUNC. , this function can then access private property of friend class
#include<bits/stdc++.h>
using nsmaespace std;


// NOTE WE NEEDTO DECLARE BUS ABOVE TRUCK CLASS
class Bus{
public:
	void print();
	
};

//friend function test() declaration
void test();

class Truck{
private:
	int x;
protected:
	int y;
public:
	int z;

	friend void Bus:: print();	// accessing private and protected properties of Truck in  Bus class using friend func.


	friend void test(); //this func, isnt part of any class



	// if Bus has print1(), print2(), .. which want to access private of Truck
	// then make complete Bus class as friend of Truck
	friend class Bus;
	//this friendship is one-way
	// Bus can access all property of Truck, vice-versa not true

};

void Bus::print()
{
	Truck t;
	t.x = 10; // private property of truck
	t.y = 20;
	cout<<t.x<<" "<<t.y<<endl;

}

void test()// test definition
{
	// access truck private
	Truck t;
	t.x = 10; // private property of truck
	t.y = 20;
	cout<<t.x<<" "<<t.y<<endl;

}

int main()
{
	Bus b;
	b.print();


	test();

}


//NOTE : friend functions dont have access to this pointer, as they are not part of that class
/* so below is wrong, if display() is friend func
void display()
{
	cout<<this->x<<endl;
}



