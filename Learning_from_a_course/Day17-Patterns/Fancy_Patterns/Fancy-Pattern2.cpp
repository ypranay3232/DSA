/*
Now let's create a solid Half pyramid.
*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*

now to print this star as we can see ! we can break it into two parts (first half till 5 and remaining)

as we can observe the pattern its in increasing order (1,2,3,4,5)
rows   stars
0       1
1       2
2       3
3       4
4       5

so we need +1 for all so just make the stars equal to N. (row<n)

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the Height of the pyramid : " << endl;
    cin >> n;

    for (int row = 0; row < n; row = row + 1)
    // Runs up to n(.i.e. 5)
    {
        for (int cols = 0; cols <= row; cols = cols + 1)
        // for each row and column which is less than (row i.e. N(5) we print a star at both row and cols)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // Now let's print the bottom half of pyramid. (row= n-2 ==5-2 = 3) so we dont repeat the (*****) star again, and the condition is untill(row>=0 )decrment and dont print negative values so >=0. so it prints from (3,2,1,0)
    for (int row = n - 2; row >= 0; row--)
    {
        // if cols and less than or equal to row (i.e. 3) increment from 0(0,1,2,3)
        for (int cols = 0; cols <= row; cols = cols + 1)
        {
            cout << "* ";
        }
        // (.ie. so we print the stars on both rows and cols)
        cout << endl;
    }
}
