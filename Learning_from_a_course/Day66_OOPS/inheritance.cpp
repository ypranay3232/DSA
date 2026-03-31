// 2. Inheritance : Acquiring all the properties of an parent class by child class. Mode of inheritance can be Public,private,protected.
// when you try to access private members of parent class you cant access them via child class. The point here is : child class gets inherit the private members but they are marked as private in the child class

// Types of inheritance : single, multi level, multiple, hierarchical, hybrid

#include <iostream>
#include <string>
using namespace std;

class Details
{
private: 
    int age;

public:
    void Speaking_Lang()
    {
        cout << "English" << endl;
    }

};

// child class :
class info : public Details
{
public:
    // Adding another function in child class to access Upcasting (runtime polymorphism)
    void Speaking_Lang()
    {
        cout << "Hindi" << endl;
    }
};

int main()
{
    // Inheritance :
    info i;
    i.Speaking_Lang(); // Accessing parent class details via child class
    // cout<<i.age<<endl;//we cannot access private members of parent class

    return 0;
}
