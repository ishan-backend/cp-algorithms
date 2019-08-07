
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
