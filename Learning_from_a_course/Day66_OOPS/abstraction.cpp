// Abstraction using abstract class

#include <iostream>
#include <string>
using namespace std;

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
    // Abstraction
    Employee emp;
    emp.Work();

    return 0;
}
