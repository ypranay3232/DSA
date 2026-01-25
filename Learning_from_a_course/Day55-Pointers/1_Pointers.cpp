/*
Pointers : a pointer is a variable that holds the address of another variable

When we do (int a = 10;)in memory it will be stored and assigned with a memory address and that address is unique to each stored value either a function, variable etc.

in c++ we have a crucial data structure used internally by c++ compiler called Symbol table which stores and manages information about all variables,functions inside a program.

symbol table takes a identifier (a) then maps it with its address so when ever in program we do cout
cout<<a; the a will be check with symbol table then goes to the address of that variable


*/

#include <iostream>
using namespace std;

int main()
{
    // to check the address of a variable we use & ampersand operator
    int a = 10;
    cout << "The address of a is " << &a << endl;
    // The hexadecimal value represents the memory location of the variable. The memory management is Done by os, we cant particularly insert a variable at a particular memory location.

    // creating and accessing pointers, we use a derefernce operator (*) there are two types of operators with pointers (1 address of & operator --> returns address of variable) and (2 derefernce operator * -->used to directly access the value of a variable rather than address we access value)

    // so any changes made using derefernce operator directly affect the original variable

    int b = 5;
    int *ptr = &b;
    cout << "The value of b is : " << b << endl;
    cout << "The address of b is " << ptr << endl;

    // making changes using * operator
    *ptr = 20;
    cout << "updated value of b is : " << b << endl;

    // NOTE : we have three different addresses here 1) address of a. 2)address of ptr both are different but ptr holds the address of a, but their both address is not same

    // size of pointer is system dependent for 32Bit ==> 4bit and for 64 bit ==> 8 bit etc

    int a1 = 5;
    int *p = &a1;

    char ch = 'd';
    char *q = &ch;

    double dbl = 5.02312381294;
    double *d = &dbl;
    // the size of all pointers is same even though they all pointing to different datatypes became pointer only stores address irrespective of the datatype.
    cout << "The size of p is : " << sizeof(p) << endl;
    cout << "The size of p is : " << sizeof(q) << endl;
    cout << "The size of p is : " << sizeof(d) << endl;
    return 0;
}
