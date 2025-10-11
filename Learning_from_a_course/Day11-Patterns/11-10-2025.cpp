// Let's see how to print a Hollow full pyramid.

/*
 *
 *  *
 *      *
 * * * * * *
 */

// first lets print a full pyramid : TO print it we have a formula : ex : rows = 5, then cols = 2*rows-1
// and we have to print odd number of stars in each row (1,3,5,7,9...)

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the no of rows : \n";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k = 0; // because we want this k to count for every row if we keep it outside it wont count for every row.

        // now How many cols we want we add that condition here
        for (int j = 0; j < ((2 * n) - 1); j++)
        {
            if (j < (n - i - 1))
            {
                cout << " ";
            }
            else if (k < 2 * i + 1)
            {
                cout << "*";
                k++;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    // now lets print a Hollow full pyramid ! as we know to Print a hollow we just need to print their 0th and N-1th position of the star.

    int m;
    cout << "Enter the no of rows : \n";
    cin >> m;

    for (int i1 = 0; i1 < m; i1++)
    {
        int k1 = 0; // because we want this k to count for every row if we keep it outside it wont count for every row.

        // now How many cols we want we add that condition here
        for (int j1 = 0; j1 < ((2 * m) - 1); j1++)
        {
            if (j1 < (m - i1 - 1))
            {
                cout << " ";
            }
            else if (k1 < 2 * i1 + 1)
            {
                if(k1 == 0 || k1==2*i1 || i1 == n-1){
                    cout<<"*";
                }else{
                    cout<<" ";
                }
                k1++;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

}
