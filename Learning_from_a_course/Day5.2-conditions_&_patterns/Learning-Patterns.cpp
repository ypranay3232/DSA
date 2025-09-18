#include <iostream>
using namespace std;
int main()
{
    // full square pattern :
    //  for(int row = 0; row<3; row = row+1){
    //      for(int col=0;col<15;col = col +1){
    //          cout<<"*";
    //      }
    //      cout<<endl;
    //  }
    //  whats the difference between: i = i + 1, i+=1, i++. a simple difference among all is 1) i = i + 1(means take current value of i and add +1 to it then assign the result back to i) 2)i+=1 : same add 1 to i. 3) i ++ (this is an increment operator) means increment i + 1 after using i current value. (i = 5; i<10; i++) first use i=5 then increment by 1. (i = 6) at 2nd iteration

    // now lets print a square (same as rectangle but equal inner and outer loops)
    // for(int rows1 = 0; rows1<5;rows1 = rows1 + 1){
    //     for(int col1=0;col1<5;col1 = col1 + 1){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    // now lets make a user input no of star pattern
    // int No_of_Rows, No_Of_Columns;
    // cout<<"Enter the no of Rows you want : ";
    // cin>>No_of_Rows;
    // cout<<"Enter the no of Columns you want : ";
    // cin>>No_Of_Columns;
    // for(int rows=0;rows<No_of_Rows;rows+=1){
    //     for(int columns=0; columns<No_Of_Columns;columns+=1){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    // now lets print a Hollow rectangle

    /* ***********
       *         *
       ***********

    */

    // // first lets understand how rows and columns work. here we have 3 rows right ? and now we see that in first row we have to print 10 stars and in 2nd row 1st and last stars and print space in between and in 3rd we again need 10 stars
    // for (int rows = 0; rows < 1; rows += 1)
    // {
    //     for (int cols = 0; cols < 10; cols += 1)
    //     {
    //         cout << "*";
    //     } // first create a single row and a column with 10 stars and end the line
    //     cout << endl;
    //     for (int a = 0; a < 1; a += 1) // now create another row
    //     {
    //         cout << "*"; // and print star
    //         for (int b = 0; b < 8; b += 1)
    //         // now inside the single row create a column with spaces of 8(+2 rows at start and ending)
    //         {
    //             cout << " ";
    //         }
    //         for (int c = 0; c < 1; c += 1) // now fill the last row
    //         {
    //             cout << "*";
    //         }
    //         cout << endl; // and end the line
    //     }
    //     for (int d = 0; d < 10; d += 1)
    //     { // now repeat the same create a row and a column with 10 stars
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // NOTE : Never follow this approach because its not scalable and not used too many loops.


    // you can also do it as :
    for (int row = 0; row < 3; row += 1) // create a row if it is a first row or last row we print 10 stars
    {
        if (row == 0 || row == 2)
        {
            for (int col = 0; col < 10; col += 1)
            {
                cout << "*";
            }
            cout << endl;
        }
        else
        {
            // if it is row2 then we print a row and create a for loop that prints 8 spaces and we print a *
            cout << "*";
            for (int i = 0; i < 8; i += 1)
            {
                cout << " ";
            }
            cout << "*";
            cout << endl;
        }
    }


    // Lets see how to solve this : 
    /*      *********************
            *                   *
            *                   *
            *                   *
            *                   *
            *********************
    
    */ 
    int RowCount, ColCount;
    cout<<"Enter the no of rows you want : ";
    cin>>RowCount;
    cout<<"Enter the no of cols you want : ";
    cin>>ColCount;
    // Takes input from user

    for(int row = 0; row<RowCount; row+=1){ //creates rows and checks if rows < input if yes then increment 
        if(row == 0 || row == RowCount-1){  //if the row is first and (n-1) last
            for(int col=0; col<ColCount;col++){ //then print 10 stars as columns
                cout<<"*";
            }
        }
        else{ //else if the rows are not first and last(n-1)
            cout<<"*";//first print a star
            for(int space = 0; space<ColCount-2; space+=1){//then print n-2 spaces because we print 2 stars fist and last
                cout<<" ";
            }
            cout<<"*";
        }
        cout<<endl;//now end lien and start in new line for last row
    }
}