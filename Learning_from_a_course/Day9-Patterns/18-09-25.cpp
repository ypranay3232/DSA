// Solid square pattern print a square with solid 6 stars

#include <iostream>
using namespace std;

int main()
{
    for (int Rows = 0; Rows < 6; ++Rows)
    {
        for (int Columns = 0; Columns < 10; ++Columns)
        {
            cout << "*";
        }
        cout << endl;
    }
    // working principle : works as first enters the outer loop (rows) and checks condition which is true then checks inner loop (columns) and now prints a star until 10(*********) now we print in new line with a endl statement.
    // now again checks rows = 1 and cols which are 0 because we are in a new line and prints 1- stars and break the line  and enter new line and goes on until rows become 6.


    
    // Patterns Question 2
    // How to print Hollow square Pattern (A Square pattern with only boundaries)
    //  how we do is first we create two loops (outer and inner) then we add a if condition where we skip the stars

    int n;
    cout<<"Enter the value of N : "<<endl;
    cin>>n;
    for(int i =0;i<n;++i){
        for(int j =0;j<n;++j){
            // prints stars only on 1st row and last row and for first column and last column
            if(i==0 || i == n-1 || j ==0 || j == n-1){
                cout<<"*";
            }else{
                // but if its not first row and last row we have to print space !
                cout<<" ";
            }
        }
        // And we print with endline for each completion of a row and a column ********
        cout<<endl;
    }

    // Question 3 : Hollow inverted Half pyramid ! 
    int m;
    cout<<"Enter the Value of M : "<<endl;
    cin>>m;

    for(int row1=0;row1<m;++row1){
        for(int col1=0;col1<=m;++col1){
            // Everything is same till now the condition is (print star only if row ==0 and col ==0 ) but about the middle line its 
            // we print the inverted triangle as : as the row increases the cols decreases ! 
            if(row1==0 || col1==0 || col1== m-row1-1){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        // adding endl because we need to start at new line after each column.(*******\n)
        cout<<endl;
    }
}