/*
Pascal's Triangle Pattern
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1

so now to print this : We use the same approach ! we declare a global variable then instead of incrementing it we assign it as : var = var * (row-col)/(cols+1) : which prints next number in same row:

Row     starting_value    var=var*(row-col)/(col+1)                 output
0       1                   1                                          1
1       1                   1*(1-0)/(0+1) = 1                          1 1
2       1                   1*(2-0)/(0+1)=2 -> 2*(2-1)/(1+1) = 1       1 2 1

*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the Height of the Pattern : " << endl;
    cin >> n;

    for (int row = 0; row < n; row++)
    {
        int var = 1;
        for (int cols = 0; cols <= row; cols++)
        {
            cout<<var<<" ";
            var = var * (row - cols)/(cols+1);
        }
        cout<<endl;
    }
}