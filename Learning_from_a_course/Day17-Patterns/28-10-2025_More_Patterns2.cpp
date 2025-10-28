/*
Exercise : Numeric Palindrome Equilateral Pyramid

                  1
                1 2 1
              1 2 3 2 1
            1 2 3 4 3 2 1
          1 2 3 4 5 4 3 2 1

first let's break the pattern into parts so First we print the spaces
Now break the Pattern into two half's first half is left half pyramid and right half pyramid

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the Height of the pyramid : ";
    cin >> n;

    for (int row = 0; row < n; row = row + 1)
    {
        // first we print spaces so ! let's find the Pattern to print spaces. (as we can see the Spaces are in decreasing order )

        /* Assume : N=4
        rows spaces
        0       4 -1 = 3
        1       3 -1 = 2
        2       2 -1 = 1
        3       1 -1 = 0


        so we can say that (n-row) */
        for (int spaces = 0; spaces < n - row-1; spaces = spaces + 1)
        {
            cout << " ";
        }

        // now lets print the first half of the pyramid : because we print from 1 we declared cols=1
        /* The First half Pattern is as : 1,12,123,1234,12345. so we can say that it's just row + 1 */
        for (int cols=1; cols <= row + 1; cols = cols + 1)
        // This works as : ex: At row 3 it prints up to (1,2,3,4)
        {
            cout << cols<<" ";
        }

        // Think if Letf half pyramid condition is (cols<=row+1) then right half pyramid question would be ? ofc (cols>=1) and cols--
        // Because if we initiate cols = 1 we get two 1's at starting of pattern so we assign it to row ! 
        for (int cols = row; cols >= 1; cols--)
        // ex: At row 3 (because its decrementing values : which are greater than 1 so row 3 ==4 so 3,2,1)
        {
            cout << cols<<" ";
        }
        cout << endl;
    }
}