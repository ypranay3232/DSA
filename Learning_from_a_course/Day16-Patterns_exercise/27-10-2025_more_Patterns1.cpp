/*
Let's see how to print this pattern

A
A B A
A B C
A B C B A
A B C D C B A
A B C D E D C B A

before that first print this pattern :
1
12
123
1234

Whats the formula (its as we increment on each column ! )

okay got it now can we make some changes as :

1
12'1'
123'21'
1234'321'
1234'4321'

its nothing but reverse counting (4321) so lets print it

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the lenght of the pyramid : " << endl;
    cin >> n;

    // for (int row = 0; row < n; row = row + 1)
    // {
    //     for(int cols=0;cols<row+1;cols=cols+1){
    //         cout << cols + 1;
    //     }
    //     cout<<endl;
    // }

    // for (int row = 0; row < n; row = row + 1)
    // {
    //     int cols;
    //     for(cols=0;cols<row+1;cols=cols+1){
    //         cout << cols + 1;
    //     }
    //     cols=cols+1;

    //     // now print the reverse counting of numbers we use (n-1 ) so cols=cols-1.
    //     // it works as (cols = 12) so cols-1 means (pritn 1 from 1,2) and for next iteration (123, col=cols-1) means print 12 from 123.
    //     for(;cols>=1;cols=cols-1){
    //         cout<<cols;
    //     }
    //     cout<<endl;
    // }

    // Now lets replace the numbers with Alphabets ! so lets map the 1 == A, 2 == B, 3 == c, 4 == D.
    // And to print a character from numbers we do it as (m + 'char')

    for (int row = 0; row < n; row = row + 1)
    {
        // inner loop

        int cols;
        for (cols=0; cols < row + 1; cols = cols + 1)
        {
            int answer = cols + 1; // to increment the number by +1 so that we can print a character
            char ch = answer + 'A' - 1;
            cout << ch;
        }
        // Now to print the reverse counting !
        for (int cols = row; cols >= 1; cols = cols - 1)
        {
            int answer = cols;
            char ch = answer + 'A' - 1;
            cout << ch;
        }
        cout << endl;
    }
    /*
    explaination : m = any number 
    m + 'A' - 1

    */
}