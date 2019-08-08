
// 5. HYBRID INHERITENCE: (A, B)->C->D->(E, F)

// diamond problem:

// VEHICLE->(CAR, TRUCK)->BUS

// if vehicle,  car and truck ,all have print() function
// then how to decide which print() toexecute

#include<iostream>
using namespace std;
#include"Vehicle.cpp"
#include"Car.cpp"
#include"Truck.cpp"
#include"Bus.cpp"

int main()
{
	Bus b;

	b.print(); // bus has no print()

	//object.base_class name:: functionname;
	b.Car:: print();

	//calls truck class print func
	b.Truck:: print();


}

//PART 2:

//Note: since, car and truck classes inherit from vehicle class
// both contain a copy of vehicle class
// to prevent this wastage of space

class Truck: virtual public Vehicle{
public:

	Truck()
	{
		cout<<"Truck's constructor"<<endl;
	}
};

// thus by using virtual in truck and car, we ensured that bus receives only single/same copy of vehicle class

int main()
{
	Bus b;
	// since, vehicle is virtual base class of truck and car
	// no: const bus -> (const car->const vehicle, const truck-> const vehicle)
	// yes: const bus->const vehicle

	// if default constructor of vehicle doesnt exist, then error
	// to resolve this problem, create param. const. of vehicle,
	//then call explicitly const of vehicle in both car and truck class
	// e.g 
	/*
	class Bus: public Car, public Truck{
	public:
		Bus():Vehicle(5)
		{
	cout<<"Bus's construct"<<endl;
		}
	};
	*/
}
