// STATIC means property belongs to class and not to objects.


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

#include<bits/stdc++.h>
using namespace std;

//UPDATING STATIC MEMBER OF CLASS WHEN AN OBJECT OF CLASS IS CREATED

class Student{
public:
	// non-static:
	int rollNumber;
	int age;

	static int totalStudents; //static property: jo generally us object ka koi kaam na ho, group of objects ke lie significance ho

	Student()
	{
		// this constructor increases value of totalstudents by 1, whenevr a new object is created
		totalstudents++;
	}
};

int Student::totalStudents = 0;

int main()
{
	Student s1;
	Student s2;
	Student s3, s4, s5;

	cout<<Student::totalstudents<<endl; // outputs 5	

	return 0;
}


// PART 3:
// when static member is made private and we need to get its value, we make a public function and use to call it outside class using scope reolution op.

#include<bits/stdc++.h>
using namespace std;

//UPDATING STATIC MEMBER OF CLASS WHEN AN OBJECT OF CLASS IS CREATED

class Student{

	static int totalstudents;	// static, made private, now it can be accessed outside the class by public function
								// but this function doesnt require object

public:
	// non-static:
	int rollNumber;
	int age;

	Student()
	{
		totalstudents++;
	}

	int getRollNumber()
	{
		return rollNumber;
	}

	static int getTotalStudent()	//static because to call this function, object isn't required
	{
		return totalstudents;
	}
};

int Student::totalStudents = 0;

int main()
{
	Student s1;
	Student s2;
	Student s3, s4, s5;

	// class::function/property
	cout<< 	Student::getTotalStudent() <<<endl;

	return 0;
}
