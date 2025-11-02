// In Genearl a function is a block of code designed to perform a specific task and you can re use it any where.

// Assume that i want to print a statement 5 times, what can we do ? we can use loops ? yes let's see

#include <iostream>
using namespace std;

void Repeat_and_reuse_ex() // Here in the braces we declare input parameters which are going to be used inside the fucntion.
{
    int n;
    cout << "Enter the value of n : " << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Hello world" << endl;
    }
}
int main()
{
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << "Hello world" << endl;
    // }

    // but when i want to use the same code again, i have to copy paste the same code again ! we miss DRY Principle (dont repeat yourself), This makes code lengthy. so we have a mechanism called functions.

    // so now lets call the function we created ! (this is called calling a function/function call)
    Repeat_and_reuse_ex();

    /* The format of a function is as follow :

        return type(input arguments/parameters){

            // Body of the function

            
            Return 0;
        }

        What is return 0 --> it indicates that the program is successfully executed without errors. (Normal termination) but if we return any non zero values such as 'Return 1' --> The os checks the script/code to detect it. 
        
        
        Simply the return 0 --> Works as an error flag (if 0 all fine if set to 1 or something os somes into picture and try to fix it)
    */
}