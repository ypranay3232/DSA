// Lets print an inverted pyramid or triangle

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the Length of pyramid : " << endl;
    cin >> n;
    for (int row = 0; row < n; row = row + 1)
    {
        // use the inner loop for spaces !
        for (int cols = 0; cols <row; cols = cols + 1)
        {
            cout <<" ";
        }
        // now print stars
        for(int cols=0;cols<n-row;cols=cols+1){
            cout<<"* ";
        }
        cout<<endl;
    }
}