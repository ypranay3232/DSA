/*

Now let's print this pattern, Hollow half pyramid

1
1 2
1   3
1     4
1 2 3 3 4 5

let's see how to print it

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the Lenght of the Pyramid : " << endl;
    cin >> n;

    // First lets Start with 1 because our pattern stars with 1 and increment it till its <= N
    for (int row = 1; row <= n; row = row + 1)
    {
        // first let's print the stars at startin and ending and print a spcae inbetween the characters
        for (int cols = 1; cols <= row; cols = cols + 1)
        // cols also started at 1 and incremented til they are equal to row
        {
            // now we add the condition as : if cols ==0 (first col) and cols == row (last column in row) and (row == n) last row
            if (cols == 1 || cols == row || row == n)
            {
                cout << cols << " ";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}