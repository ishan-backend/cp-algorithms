#include<iostream>
#include<cstring> // strlen, strcpy
using namespace std;



class Student
{
    int age;    

public:

    // making name public so that it is visible by s2
    char *name;
    

    //Inbuilt copy constructor : it always does shallow copy.
    Student(int age, char* name)
    {
        this->age = age;
        
        // * DEEP COPY *
        this->name = new char[strlen(name) + 1]; // s2 is pointing to same array as s1
        strcpy(this->name, name); 

    }

    // COPY CONSTRUCTOR: does deep copy
    // dont use pass by value(copy created) : Student s (itself calls a copy constructor)
    // use pass by reference to prevent infinite loop calling ...

    // make s as const reference, by this we wont allow any changes to passed s object
    // only read values of s is allowed, no changes allowed
    Student(Student const &s) // points to s refered by main func.
    {
        this->age = s.age;

        // deep copy
        this->name = new char[strlen(s.name) + 1];  // s2 points to seperate array in which s1 name is copied
        strcpy(this->name, s.name); 
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

    // creating other object which is copy of s1 object
    Student s2(s1);

    s2.name[0] = 'x';

    s1.display();
    s2.display(); 

    /* OUTPUT: (inbuilt copy constructor)
    abcd 20
    xbcd 20
    xbcd 20
    */

    /* OUTPUT: 
    abcd 20
    abcd 20
    xbcd 20
    */


    
    return 0;
}
