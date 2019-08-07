// try avoiding shallow copy

#include<iostream>
using namespace std;



class Student
{
    int age;
    //char name[100];  //statically create name array.

    char *name; // Dynamically, we dont want to waste memory, so just create a char pointer, which asperour req. will then point to some name.

public:

    // Parametrized Constructor: so default constructor isn't visible.
    Student(int age, char* name)
    {
        // this pointer refers to object of class
        // this->data_member = parameter_of_constructor
        this->age = age;
        this->name = name;  //SHALLOW COPY

    }

    void display()
    {
        cout<<name<<" "<<age<<endl;
    }

};

int main()
{
    // creating objects : note that default constructor isn't visible.
    char name[] = "abcd";
    Student s1(20, name);
    s1.display();

    name[3] = 'e';
    Student s2(24, name);
    s2.display();

    s1.display();   //note that name changes, beacuse both s1 and s2 name pointer points to same char array.
    
    // this is example of SHALLOW COPY( NAME POINTER STORES ADDRESS OF FIRST ELEMNT OF SAME CHAR ARRAY)
    
    // INSTEAD OF COPYING COMPLETE CHAR ARRAY FOR BOTH OBJECTS, 
    // WE just made them point to same location / copying of only same pointer.
    return 0;
}
