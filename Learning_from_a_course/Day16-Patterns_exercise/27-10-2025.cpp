// Let's do a exercise
/*
Print the following pattern :

*
* *
* * *
* * * *

As we can see we just need to increment the stars in each row right ? so formula is (row+1)

simple right ? now lets remove the star and add (row+1) to print the numbers as :

1
22
333
4444
4444
333
22
1

so we can break the pattern in two parts first half and second half upto 4


But we want the pattern as :

1
2*2
3*3*3
4*4*4*4
4*4*4*4
3*3*3
2*2
1

*/
#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter the length of the Triangle : " << endl;
    cin >> n;

    // for(int row=0;row<n;row=row+1){
    //     // now lets print inner loop of stars
    //     for(int cols=0;cols<row+1;cols=cols+1){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // for(int row=0;row<n;row=row+1){
    //     // now lets print inner loop of stars
    //     for(int cols=0;cols<row+1;cols=cols+1){
    //         cout<<row+1;
    //     }
    //     cout<<endl;

    // Now to print the numbers and the stars we need a star inbetween each cahracter so we can add a if condition as we need to print the star only at inbetween not at last so (if row !=cols) then prints a star, means if you are not a last character then print a star.
    for (int row = 0; row < n; row = row + 1)
    {
        // now lets print inner loop of stars
        for (int cols = 0; cols < row + 1; cols = cols + 1)
        {
            cout << row + 1;
            if (row != cols)
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    // Now try to print the inverted half pyramid:
    /*

    * * * *
    * * *
    * *
    *

    so we need to find the formula :
    rows stars
    0      4
    1      3
    2      2
    3      1
    4      0

    so we can do it as (n-row) = 4-0=4, 4-1=3, 4-2=2, 4-3=1,4-4=0.
    we got a working formula!

    now remove the star and add (n-row) which prints numbers

    now to add stars in between we know the formula as we did it for upper half pyramid
    */

    for (int row = 0; row < n; row = row + 1)
    {
        // now lets print the triangle
        for (int cols = 0; cols < n - row; cols = cols + 1)
        {
            cout << n-row;
            if(cols != n-row-1){
                cout<<"*";
            }
        }
        cout<<endl;
    }
}