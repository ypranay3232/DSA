// 3) Polymorphism : existence of many forms, Used to create function with same name but with different parameters. 1) compile time polymorphism 2) Run time polymorphism (overriding function)
// polymorphism based on two things : 1) function overloading 2) operator overloading

#include <iostream>
#include <string>
using namespace std;

class Details
{
public:
    int ID;

    void Speaking_Lang()
    {
        cout << "English" << endl;
    }

    // Polymorphism compile time : function overloading
    int sum(int a, int b)
    {
        return a + b;
    }
    // ANd right after we can create another function but with different parameters or datatypes
    float sum(int a, float b)
    {
        return a + b;
    }

    // operator overloading : Using operators for other purposes
    Details operator+(Details const &obj)
    {
        Details res;
        res.ID = this->ID + obj.ID;
        return res;
    }

    // Polymorphism (Runtime) : here we use a keyword override to change the function behavior accordingly
    virtual void Role()
    {
        cout << "Generic Person" << endl;
    }
};

// child class :
class info : public Details
{
public:
    // Overriding parent function (Runtime Polymorphism)
    void Role() override
    {
        cout << "Software Engineer" << endl;
    }
    // Adding another function in child class to access Upcasting (runtime polymorphism)
    void Speaking_Lang()
    {
        cout << "Hindi" << endl;
    }
};

int main()
{
    Details person;
    info i;

    // Polymorphism
    Details *ptr = &person; // Dynamic obj creation
    
    // UpCasting : pointing parent ptr to child class
    Details *a = new info();
    a->Speaking_Lang(); // this returns english not hindi so to print child class at runtime we add a keyword called "Virtual" to parent.then prints hindi. This is called run time polymorphism

    // Downcasting : Pointing child ptr to parent 
    info* b = (info*)new Details();
    b->Speaking_Lang();//THis return hindi 

    // whenever you do upcasting or downcasting always the pointer class method will be called if using no virtual keyword. if using virtual keyword the new method() func will be called

    cout << ptr->sum(10, 20) << endl; // calls first function
    ptr = &i;                         // base class pointer pointing to child object
    ptr->Role();                      // Calls child class function (Runtime polymorphism)

    return 0;
}
