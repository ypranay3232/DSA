// Reference variable : we try o create a reference variable majority cases, a reference variable is a variable which contains more than one name and denoted by ampersand symbol (&). why do we need to use the reference variables, 1)we cant set them to null 2) improves readability.

// since reference variable cant be null we an say that it always represent a valid var,function etc

#include <iostream>
using namespace std;
// void passby_value(int value)
void passby_value(int& value)//but it all changes if we add an & 
{
    value++;
}

int main()
{
    int a = 10;
    int &b = a; // syntax to create a reference variable, and b is now pointing to same memory
    cout << "the address of a is : " << &a << endl;
    cout << "the address of b is : " << &b << endl; // this only creates a symbol table and assign b with a variable address that's it no memory created . now if we update it then the value will be changed
    a++;
    cout << "The value of a is : " << a << endl;
    cout << "The value of b is : " << b << endl;
    b++; // this updates a value
    cout << "The value of a is : " << a << endl;
    cout << "The value of b is : " << b << endl;

    // Pass by value : if we create a function that that takes a value rather than reference it wont get updated ex:
    int x = 1;
    passby_value(x);//this prints 1 because we are passing a value (copy) for function 
    cout << x << endl;
}