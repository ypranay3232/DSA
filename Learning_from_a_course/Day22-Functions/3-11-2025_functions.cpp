/*
FUnction call stack : A stack is a datastructure That follows last in first our order(LIFO)

By using function call stack : It displays
Function call
The function calls made by other functions
Functions Local Variables
function return type


-----------------------------------
In C++ Main() function gets executed first. And it contains a function called calculate()
and the Main() calls calculate() and inside the calculate it contains a for loop and it gets executed and bring result back to main().
------------------------------------

Once any function is executed it gets poped() form the stack. And at last The main() function returns 0 to Operating system and gets poped().

I.E in simple Terms : whenever a function gets called its entry is stored in stack and when ever a function execution is finished it gets poped()

Now write a function to add 2 numbers.
*/

#include <iostream>
using namespace std;

int add(int a, int b)
{
    ++a;
    cout << a + b << endl; // Here we get a copy of main() variable 'a', because both are in different functions.
    // This is called PassByValue(.i.e. Creating copy or passing a value to other functions), so actual value never gets passed and always a copy is made while passing and copy will be returned to a function.

    // Now lets say i increment the a value here, then which 'A' value gets incremnted ? ofc add() 'a" because we are doing operation inside add() we can check the address using & opeator
    // cout << "The address of a and b is : " << &a << &b << endl;
}
int main()
{
    int a=5,b=10;
    add(a, b);
    // Now if we print 'a' value here we get 5 because we are referring to main() 'a'
    // cout << &a << &b << endl;
}
