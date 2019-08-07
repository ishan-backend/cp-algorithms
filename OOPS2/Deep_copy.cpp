// use deep copy

#include<iostream>
#include<cstring> // strlen, strcpy
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
        
        /** DEEP COPY **/
        this->name = new char[strlen(name) + 1]; // + 1 for null character to be added later
        strcpy(this->name, name); // copy parameter name to this->name/data member

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

    s1.display();   //note that name remains same for both objects.
    
    // this is example of DEEP COPY( NAME POINTER STORES ADDRESS OF FIRST ELEMNT OF their seperate copies of char array)
    
    
    return 0;
}
