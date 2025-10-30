/*
Let's see how to print a Butterfly Pattern :

*                 *
* *             * *
* * *         * * *
* * * *     * * * *
* * * * * * * * * *
* * * * * * * * * *
* * * *     * * * *
* * *         * * *
* *             * *
*                 *

First Let's break this pattern into 4 Half Pyramid.

*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the height of the pyramid : " << endl;
    cin >> n;

    for (int row = 0; row < n; row++)
    {
        // now Let's print the first right half Pattern : as we can observer the Pattern it's just row+1
        for (int cols = 0; cols <= row; cols++)
        {
            cout << "* ";
        }

        // now lets print space between the next left triangle an (we need spaces as 5,4,3,2,1)
        for (int spaces = 0; spaces < (2 * n - 2 * (row + 1)); spaces++)
        {
            // Remember to Print 2 spaces not 1
            cout << "  ";
        }

        // Now lets print right stars:
        for (int cols = 0; cols <= row; cols++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // Now let's print the Lower Half of pyramid. we just have to invert the pyramid so we are decrement the stars so :
    for (int row = n - 1; row >= 0; row--)
    {

        for (int cols = 0; cols <= row; cols++)
        {
            cout << "* ";
        }

        // for spaces :
        for (int spaces = 0; spaces < (2 * n - 2 * (row + 1)); spaces++)
        {
            // Remember to Print 2 spaces not 1
            cout << "  ";
        }

        // bottom right half stars
        for (int cols = 0; cols <= row; cols++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}