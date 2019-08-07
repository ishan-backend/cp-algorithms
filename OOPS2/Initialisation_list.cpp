
// in case of const , at time of creation we need to initialise
// int a=5, int const b = a;

// in case of refernce, at time of creation we need to initialise
// int i = 5; int &j = i;

PART -1 // WHY INITIALISATION LIST IS NECESSARY?
class Student{

public:
	int age;
	const int rollNumber; // once given a value, its value will never change

}

int main()
{
	Student s1; //default constructor called: initialises class all properties for s1 object
	//above line initialises s1's properties with garbage values.

	//changing s1 values
	s1.age = 20;
	s1.rollNumber = 101; // NOT ALLOWED:gives error on line above in class - const int rollNumber 
}






//PART 2

class Student{

public:
	int age;
	const int rollNumber; 

	// making our constructor so that we can initialise it with our values
	Student(int r)
	{
		// when we're entering this constructor, rollNumber has been created and garbage is placed
		// so we need to initialise rollNumber at its time of creation

		rollNumber = r;//NOT ALLOWED
	}

}


// PART 3.


// INITIALISATION LIST: HELPS INITIALISATION OF CONST VARIABLES/DATA MEMBERS and REFERENCE VARIABLES
// IT HELPS INITIALISE OUR CONST DATA MEMBER BEFORE IT GOES INTO CONSTRUCTOR


class Student{

public:
	int age;
	const int rollNumber; //const variables
	int &x;	//refrence variable
	
	Student(int r): rollNumber(r) // basically meaning int rollNumber = r at time of creation of object when constructor is called
	{
	
	}

	//e.g multiple data members using initialisation list and for refernce variables
	Student(int r, int age): rollNumber(r), age(age), x(this->age)
	{

	}

}

int main()
{
	Student s1(101, 20);
	s1.age = 20;
	return 0;
} 
