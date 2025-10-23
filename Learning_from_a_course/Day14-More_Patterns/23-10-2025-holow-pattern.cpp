/*
now lets print a Hollow full diamond

            *
           * *
          *   *
         *     *
        *       *
        *       *
         *     *
          *   *
           * *
            *
first lets find out the formula :

rows  spaces and (N =5)

0      4
1      3
2      2
3      1
4      0
-----------
formula = we have to get 4 spaces so = N =5 -row =0 -1 [n-row-1] = [5-0-1=4]
[5-1-1=3], [5-2-1=2],[5-3-1=1]
------------

now lets print the stars so lets find the formula : here as we can observe in the pattern we print (only 1 character in the first row = 1 star

and for 2nd row we print 3 characters =2 stars and a space in between
3rd row 5 characters = 2 stars and 3 spaces
4th row 7 characters = 2 stars and 5 space)

NOTE : we have a formula to print even and odd numbers !
EVEN = 2*N = 2,4,6,8..
ODD = 2*N-1 (or) 2*N+1 = 1,3,5,7,9...


so here we need odd numbers because : when we observe the pattern on first row we are printing (1 character = 1star and on 2nd row we are printing 3 characters = 2 stars and a space
3rd row 5 characters = 2 stars and 3 spaces
4th row = 7 characters = 2 stars and 5 spaces)

so lets try the formula to print odd numbers : 2*N-1 (or) 2*N+1

row    odd nums
0       1
1       3
2       5
3       7
------------
2*N+1 = 2*(n=row)+1 == (2*0+1 = 1) got odd number
2*1+1 = 3
2*2+1 = 5
2*3+1 = 7

Got it now lets print a star so we have a condition we print star for only first and last character else print a space


*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the length of the Pattern : " << endl;
    cin >> n;

    for (int row = 0; row < n; row = row + 1)
    {
        // now lets print the spaces of first half
        for (int cols = 0; cols < n - row - 1; cols = cols + 1)
        {
            cout << " ";
        }
        // now lets print stars
        for (int cols = 0; cols < 2 * row + 1; cols = cols + 1)
        {
            if (cols == 0 || cols == 2 * row)
            { // 2*row means last row because (cols start from 0,1,2,3,4 and ends at 2*row)
                cout << "* ";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    } // end of first half of pyramid

    // now lets print lower half of pyramid

    for (int row = 0; row < n; row = row + 1)
    {
        // now lets print spaces the formula is (row) because we have equal rows and spaces
        for (int cols = 0; cols < row; cols = cols + 1)
        {
            cout << " ";
        }
        // now lets print stars :
        /* The formula is :

        now lets find formula to print stars

rows  stars(characters) to print  N=4
0      7
1      5
2      3
3      1
-----------
2*N - 2*row-1
-----------

2*4(8) - 2*(0) - 1 = 8-1= 7
2*4(8) - 2*(1) - 1 = 8 -2-1 = 5
2*4(8) - 2*(2) - 1 = 8-4-1 = 3
2*4(8) - 2*(3) - 1 = 8-6-1 = 1

        */
        for (int cols = 0; cols < 2 * n - 2 * row - 1; cols = cols + 1)
        {
            // now add if condition.
            if (cols == 0 || cols == 2 * n - 2 * row - 2)
            {
                cout << "* "; // 2*n-2*row-2 because it is the nth or last digit for 2*n-2*row-1
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
