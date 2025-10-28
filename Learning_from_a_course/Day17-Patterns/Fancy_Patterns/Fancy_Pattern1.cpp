/*
Fancy Patterns : Let's print the following Pattern : Where N = 5 fixed

* * * * * * * * 1 * * * * * * * *
* * * * * * * 2 * 2 * * * * * * *
* * * * * * 3 * 3 * 3 * * * * * *
* * * * * 4 * 4 * 4 * 4 * * * * *
* * * * 5 * 5 * 5 * 5 * 5 * * * *

let's break the Pattern into Parts : Left stars and numbers and right stars

first let's print stars which are in decreasing order so : (n-row-1)but we need 8 stars so how we do it (Simple ) we add (N + 3 - row) = 5+3-row(0) = 8 and then 7,6,5,4,3,2,1.

*/
#include <iostream>
using namespace std;

int main()
{

    int n = 5;

    for (int row = 0; row < n; row++)
    {
        // first lets print the stars of left side :
        for (int stars = 0; stars < n + 3 - row; stars++)
        {
            cout << "* ";
        }

        // Now print the numbers along with stars between : 
        /*
        rows  numbers  How_Many_Times
        0       1          1
        1       2          2
        2       3          3
        3       4          4
        4       5          5      

        1 
        2 * 2
        3 * 3 * 3
        4 * 4 * 4 * 4

        so to print it we need first we declare number=0 and increment by 1 and print a space. 
        now print a space only if (Number != row) means print the stars only if we are not at last digit.

        */
        for (int Num = 0; Num <= row; Num++)
        {
            cout << row + 1 << " ";
            // The number = 0, row is the last digit we printed (and its incremented till <=N)
            if (Num != row)
            {
                cout << "* ";
            }
        }

        // Now Let's print the right stars :
        for (int stars = 0; stars < n + 3 - row; stars++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
