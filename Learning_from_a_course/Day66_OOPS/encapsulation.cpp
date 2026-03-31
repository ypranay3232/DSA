// The 4 pillar of OOPs (encapsulation, inheritance, polymorphism, Abstraction)

// 1) encapsulation : Hides data members and member functions inside a class. When we marked all members as private its called perfect encapsulation.

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
};

int main()
{
    Details person;
    person.Setid(101); // Accessing via public interface
    cout << "ID is: " << person.Getid() << endl;

    return 0;
}
