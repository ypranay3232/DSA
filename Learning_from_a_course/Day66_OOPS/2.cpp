// The 4 pillar of OOPs (encapsulation, inheritance, polymorphism, Abstraction)

// 1) encapsulation : Hides data members and member functions inside a class. When we marked all members as private its called perfect encapsulation.

// 2. Inheritance : Acquiring all the properties of an parent class by child class. Mode of inheritance can be Public,private,protected. 
// when you try to access private members of parent class you cant access them via child class. The point here is : child class gets inherit the private members but they are marked as private in the child class

// Types of inheritance : single, multi level, multiple, hierarchical, hybrid

#include <iostream>
#include <string> 
using namespace std;

class Details
{
private: // Data members are hidden (Encapsulation)
    int age;
    int ID;
    string Name;

    // to access the private members we use getters and setters
public:
    int Getid()
    {
        return this->ID;
    }

    // Setter: Must take a parameter to update the value
    void Setid(int newID)
    {
        this->ID = newID;
    }

    void Speaking_Lang()
    {
        cout << "English" << endl;
    }

    // Polymorphism (Runtime - using virtual function)
    virtual void Role()
    {
        cout << "Generic Person" << endl;
    }
};

// child class : 
class info:public Details{
public:
    // Overriding parent function (Runtime Polymorphism)
    void Role() override
    {
        cout << "Software Engineer" << endl;
    }
};

// Abstraction using abstract class
class AbstractEmployee
{
public:
    // Pure virtual function (makes this class abstract)
    virtual void Work() = 0;
};

// Another class implementing abstraction
class Employee : public AbstractEmployee
{
public:
    void Work()
    {
        cout << "Employee is working on project" << endl;
    }
};

int main()
{
    Details person;
    person.Setid(101); // Accessing via public interface
    cout << "ID is: " << person.Getid() << endl;

    // Inheritance : 
    info i;
    i.Speaking_Lang();//Accessing parent class details via child class 
    // cout<<i.age<<endl;//we cannot access private members of parent class

    // Polymorphism
    Details* ptr;
    ptr = &i; // base class pointer pointing to child object
    ptr->Role(); // Calls child class function (Runtime polymorphism)

    // Abstraction
    Employee emp;
    emp.Work();

    return 0;
}