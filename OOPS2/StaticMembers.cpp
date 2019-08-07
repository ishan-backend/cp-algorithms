// PART 1:

#include<bits/stdc++.h>
using namespace std;


// STATIC MEMBERS: 
// whenever we create an object of class, copy of static members isn't created.
// here totalStudents is held by class
// when an object is created, it'll have rollNumber and age as its data members.


class Student{
public:
	// non-static:
	int rollNumber;
	int age;

	static int totalStudents; //static property: jo generally us object ka koi kaam na ho, group of objects ke lie significance ho
};


// As static member is class property and not object's property
// cout<<class_name :: name_of_property; 
// :: scope resolution operator

// Static properties are initialised outside the class
// data_type class_name :: name_of_property = value;
int Student::totalStudents = 0;

int main()
{
	Student s1;
	cout<<s1.rollNumber<<" "<<s1.age<<endl;

	cout<<Student::totalStudents<<endl;


	//compiler allows calling like this, but this is wrong
	cout<<s1.totalStudents<<endl;


	s1.totalStudents = 20;	// updates static property of class, either with class name or any object
	Student s2;

	cout<<s2.totalStudents<<endl;
	cout<<Student::totalStudents<<endl;



	return 0;
}


// PART 2:

