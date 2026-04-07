// Virtual keyword in c++ is used to achieve run time polymorphism.
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show()
    {
        cout << "base class" << endl;
    }
};

class Derived : public Base
{
public:
    void show()
    {
        cout << "Derived class" << endl;
    }
};



// Virtual Table :
// A virtual table is a hidden table created by the compiler for classes which have virtual functions.
// this stores address of virtual functions. IT works as : compiler created tables for both base and derived, each of the object gets a hidden virtualptr

// Virtual Destructor :
class Base1
{
public:
    ~Base1()
    {
        cout << "base destructor" << endl;
    }
};

class derived1 : public Base1
{
public:
    ~derived1()
    {
        cout<<"Derived destructor"<<endl;
    }
};


int main()
{
    Base *ptr = new Derived();
    ptr->show(); // this show() calls Derived show() because of virtual if we dont have a virtual function this calls Base show().

    // Virtual dtor

    Base1* ptr1 = new derived1();//to call derived dtor just use virtual 
    delete ptr1;
}

/*
memory layout of a program ? When a program runs os organizes memory into segments
stack
heap
BSS (uninitialized)
Data ()
text/code



1) Text/code segment : this stores the functions and read only instructions 
2) Data Segment (Initialized) : stores static and global variables (initialized vars only)
3) BSS segment(uninitialized) : undefined value variables 
4) Heap segment (Dynamic memory) : Dynamic memory allocation is done here ex : int* ptr = new int(10);
5) stack segment : stores local vars, function calls, parameters etc.

*/ 
