/* let's do it again ! Here we have to print a solid diamond pattern so :

            *
           * *
          * * *
         * * * *
         * * * *
          * * *
           * *
            *
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

        // first we print the full pyramid so we start by printing spaces then stars
        // think : for spaces it contains 4 and a star... 3 and 2 stars so formula is : (n-row-1)--> 5-0-1 =4 spaces
        for (int cols = 0; cols < n - row - 1; cols = cols + 1)
        {
            cout << " ";
        }
        // now lets prints stars so think : we get stars as 1,2,3,4 etc so (row+1) right ?
        for (int cols = 0; cols < row + 1; cols = cols + 1)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int row = 0; row < n; row = row + 1)
    {
        // now we start printing the inverted full pyramid
        // now lets enter into inner loop and first we print spaces : so to print space which is as 0,1,2,3... same as rows (0,1,2,3,4..) so we can say that row= spaces. so : cols<row

        for (int cols = 0; cols < row; cols = cols + 1)
        {
            cout << " ";
        }
        // now lets print stars so to print them we see it as they decrement in order (5,4,3,2,1) so n-row (because the 5,4,3,2,1 are n value and they decrement in row order) so : N-row

        for (int cols = 0; cols < n - row; cols = cols + 1)
        {
            cout << "* ";
        }
        cout << endl;
    }
}