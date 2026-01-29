// Til now i learnt about pointers ! a quick recap : 
// to create a pointer to int we do as : int* a = &b, now if i want to point a pointer to int* a we do as : int** a = &b; and it goes on this is called double pointer 

#include<iostream>
using namespace std;

void access_ptr(int *y){
    y = y + 1;//prints the same value
    
    // To update the value we have to pass *y not y itself (y stores address of x) but *y points the value of x so any changes made are pointed to the address 
    *y = *y + 1;//prints 11 
    
}

void doubleptr(int** ptr){
    // ptr = ptr + 1;//this returns the same o value. in order to change we have to use 
    **ptr = **ptr + 1;//this points to the m memory and make changes to it, if we do *ptr it points to n pointer that changes wont affect because it holds address not value !   
}

int main(){
    int a = 5; //this creates a value block in memory with an address, (in symbol table the a is assigned the memory address)
    int* p = &a;//this creates a block that holds the address of a.
    int** q = &p;//this holds the address of p.
    // lets check these
    cout<<"The address of a is "<<&a<<endl;
    cout<<"Accessing the address of a from P "<<p<<endl;
    cout<<"The address of p which is held by Q is : "<<&p<<endl;
    cout<<"Accessing P from Q "<<q<<endl;

    cout<<a<<endl;//5
    cout<<&a<<endl;//address of a
    cout<<p<<endl;//address of a 
    cout<<&p<<endl;//address of p
    cout<<*p<<endl;//value in p (points to address of a) returns a value 
    cout<<q<<endl;//q holds the address of p
    cout<<&q<<endl;//address of q
    cout<<*q<<endl;//holds the address of p, so goes to p (p holds the address of a) and return it.
    cout<<**q<<endl;//refers to get the p then again go to the address p holding (a) returns a value(5)


    // so in simple terms the more pointers you have the more ampersand operators you have to add in order to access the starting pointer value !

    // Task : create a function that prints the pointer
    int x = 10;
    int *y = &x;
    access_ptr(y);
    cout<<x<<endl; //the value of y is same : because we pass by value so when we pass the *y ptr in a function that is passed as a copy. not as value but as a copy so any changes made a copy wont affect actual values.


    // lets try with double pointers 
    int m = 10;
    int* n = &m;
    int** o = &n;
    doubleptr(o);
    cout<<m<<endl;//checking if operation changes m value ? 

    return 0; 
}