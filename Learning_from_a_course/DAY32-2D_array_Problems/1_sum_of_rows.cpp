/* To print the sum of all rows we do it as : we create and initialize a sum variable in a function and we loop it in cols inner loop */

#include <iostream>

using namespace std;

void Rowwisesum(int array[3][3], int row, int cols)
{
    cout << "Printing the sum" << endl;
    // create a loop to traverse through rows and cols
    for (int i = 0; i < row; i++)
    {
        int sum = 0; // creating an sum variable
        for (int j = 0; j < cols; j++)
        {
            sum = sum + array[i][j]; // when we are inside first row we made sum =0, and added with sum values and after first row we printed the values sum, then we re initialized sum with 0 and counted again and printed again.
        }
        cout << sum << endl;
    }
}
void colwisesum(int array[3][3], int row, int cols)
{
    cout << "Printing the sum" << endl;
    // create a loop to traverse through rows and cols
    for (int i = 0; i < row; i++)
    {
        int sum = 0; // creating an sum variable
        for (int j = 0; j < cols; j++)
        {
            sum = sum + array[j][i]; // when we are inside first col we made sum =0, and added with sum values and after first col we printed the values sum, then we re initialized sum with 0 and counted again and printed again.
        }
        cout << sum << endl;
    }
}

int main()
{
    int array[3][3];
    int row = 3;
    int cols = 3;

    bool flag;
    cout << "Enter your choice : 0 --> for Row sum 1 --> for Cols sum " << endl;
    cin >> flag;
    // Taking user input
    cout << "Taking user input " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> array[i][j]; //
        }
    }
    if (flag == true)
    { // now we create a function that prints row wise sum
        Rowwisesum(array, row, cols);
    }
    else
    {
        // now we create a function that prints row wise sum
        colwisesum(array, row, cols);
    }
}