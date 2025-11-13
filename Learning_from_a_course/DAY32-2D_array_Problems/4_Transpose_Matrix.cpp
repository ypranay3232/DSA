/* The Transpose Matrix : Here the rows becomes cols and cols become rows.
ex: array :
1 2 3
4 5 6
7 8 9

The row = 1 2 3 now becomes a column1, and 456 becomes column2 and 789 becomes column3
1 4 7
2 5 8
3 6 9

as we can observe that from original array the values : ex: 2 is at arr[0][1] (0th row and 2nd col)
and after transposing the matrix we can see that it is now at arr[1][0] (at col0 and row 1)

so we can say that we just need to swap the rows with cols !
arr[i][j] with arr[j][i]
(.i.e. arr[0][1] with arr[1][0])

as we know just use algorithm file and use swap()
*/

#include <iostream>
#include <algorithm>

using namespace std;

// we create two functions Transpose_matrix which swaps rows with cols and returns nothing so we call it explicitly and another function Print_transpose() which prints the transpose() and this also have no return type so we call the both functions explicitly.
void Transpose_matrix(int arr[3][3], int row, int col)
{
    // now loop through the array and swap each row with col
    for (int i = 0; i < row; i++)
    {
        for (int j = i + 1; j < col; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}
void Print_Transpose(int arr[3][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // first create an array by taking user input

    int arr[3][3];
    int row = 3;
    int col = 3;

    cout << "Enter the array values " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
        cout << endl;
    }

    // now create a function that swaps the array elements and call the function
    Transpose_matrix(arr, row, col);

    // now print the matrix
    cout<<"Printing Transpose matrix : "<<endl;
    Print_Transpose(arr,row,col);
}