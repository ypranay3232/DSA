// const is a keyword which is is used to declare a variable,function or object and that will be immutable (cant changed). ALl the Constants are stored in optimised memory (ROM) 

#include<iostream>
using namespace std;

// Macros ex : 
#define PI 2.14159465

// Macros in c++ are the preprocessor directives that allow you to define constants, functions etc generally defined as #define

float areaofcircle(float r){
    return PI * r * r;
}
float circleperimeter(float r){
    return 2 * PI * r;
}
int main(){
    // const int a = 10;//here a is constant
    // // a = 15;//throws error
    // cout<<a<<endl;

    // const with pointers
    int *a = new int;
    *a = 5;//created a pointer with 5
    cout<<*a<<endl;
    int b = 10;
    a = &b;//now assigning the a pointer to address of b.so it can print b value.
    cout<<*a<<endl;

    // BUt if we add a const to the pointer we cant modify it throws error 
    const int *c = new int(2);
    // *c = 10;//throws error because we initialized 2 with *c 
    cout<<*c<<endl;

    // The catch here is we cant reassign the value but we can change the pointer    

    // Function call : 
    cout<<areaofcircle(83.1)<<endl;
    cout<<circleperimeter(43)<<endl;
    return 0;
}
