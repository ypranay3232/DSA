/* Let's Count numbers from 1 to N : */

#include <iostream>
using namespace std;

// What is the difference between a parameter and a argument a parameter is a value which is passed by the time of declaration or initialization in a function . on The other Hand an Argument is a value which is passed to the function call() which is going to call the defined function so : 

// int n is a Parameter 
void PrintCounting(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    cout<<endl;
}
int main()
{
    // To print a number we have to take input from user of (N)
    int n;
    cout << "Enter the valu of N : " << endl;
    cin >> n;

    // now we call the function.
    // N is a Argument
    PrintCounting(n);
}
