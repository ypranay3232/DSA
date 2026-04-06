// An Inline function is a function where compiler tries to replace function call with an actual function code at runtime. we add inline keyword infront of a function.

// When we call a function : stack frame is created, control flow jumps to function from main, executes and then returns back( this is function overhead )

// So instead of calling a function inline function passes the function body (faster execution)

#include<iostream>
using namespace std;

// function created and returns a+b when function call occurs 
int add(int a,int b){
    return a+b;
}

// Inline is just a request to the compiler not a guarantee response, when function is too large,contains oops etc compiler ignores the request.
inline int add1(int a,int b){
    return a+b;
}


// ex : 
inline int square(int x) {return x * x;}   
int main(){
    cout<<add(2,3)<<endl;

    // calling inline function 
    cout<<add1(2,3)<<endl;//this inline function call replaces add1(2,3) with direct (cout<<(2+3) and prints)

    // square function call : 
    cout<<square(10)<<endl; 
    return 0;
}