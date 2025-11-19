/* Given a 2D matrix :
Leetcode : 54 Spiral Matrix

    1  2  3
    4  5  6
    7  8  9
    10 11 12
// The spiral output will be as : 1 2 3 6 9 12 11 10 7 4 5 8


54. Spiral Matrix
Medium
Topics
premium lock icon
Companies
Hint
Given an m x n matrix, return all elements of the matrix in spiral order.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100



// Lets see how to sovle it :
cols : 0 1 2
--------
row0 | 1 2 3
row1 | 4 5 6
row2 | 7 8 9

we have 3 rows and cols(first we have to print starting row(0), then ending col(2) then we have to print ending row(2)then we print starting col(1)  )

(.i.e. )
starting row
ending col
ending row
starting col

Lets understand it with a big matrix :
    col 0  1  2  3  4  5
row 0   1  2  3  4  5  6
row 1   7  8  9  10 11 12
row 2   13 14 15 16 17 18
row 3   19 20 21 22 23 24
row 4   25 26 27 28 29 30

First we print
(starting row(0) 1,2,3,4,5,6)
(ending col(5) 6,12,18,24,30)
(ending row(4)as n-1 : 30,29,28,27,26,25)
(starting col(0)as n-1 : 25,19,13,7,1)

now after this the :
(starting row becomes : (row1) 7,8,9,10,11)
(ending col becomes (4): 5,11,17,23) because ending col prints upto ending row
(ending row(3):prints as n-1: 23,22,21,20)
(starting col(1): print as n-1: 20,14)

now starting row becomes (Row2)
(starting row(2): 14,15,,16) (it should stop here at 16) we check a condition if we check we traversed total items in the matrix, (M*N) = 5*6 = 30.


-----------------------------------------------------------------------------------------------------
Lets see what is a 2D vector :

Vector<vector<int>> : This is a 2d vector (.ie we can access it as vec[i][j])
means here it contains N number of vectors inside it.

To get rows we do as => vec.size()
But to get cols we do as => vec[0].size()
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> Spiral_matrix(vector<vector<int>> &matrix)
{
    // remember the return type is vector<int> so we should answer in vector.
    vector<int> ans;
    // now define no of rows and cols and total elements to count
    int rows = matrix.size();
    int cols = matrix[0].size();
    int total_ele = rows * cols;

    // now how to initialize the logic
    // 1. The starting Row is started with 0
    int starting_row = 0;
    // 2. The ending col should be printed as colsn-1
    int ending_col = cols - 1;
    // 3. The ending row should be printed as n-1
    int ending_row = rows - 1;
    // 4. The starting col is 0
    int starting_col = 0;

    // Now we write a loop and check if all elements are traversed or not !
    int count = 0;
    while (count < total_ele)
    {
        // Step 1 : first we print starting row, so to print it we we to go from (startcol to ending_col) because we print values as 1,2,3,4,5,6 ----------

        for (int i = starting_col; i <= ending_col && count < total_ele; i++)
        {
            // Now pushback to matrix (starting row to i (ending) values) to vector.
            ans.push_back(matrix[starting_row][i]);
            count++;
        }
        starting_row++; // to avoid duplicates so when we iterate again for inner starting row we wont repeat elements again. And these make the matrix spiral.

        // Step 2 : Now print the endingcol.(Here Loop runs from starting row last element to ending row last element)
        for (int i = starting_row; i <= ending_row && count < total_ele; i++)
        {
            // Because we have to print ending col we iterate from row wise and print the ending col(which is n-1) so we get values as n-1 col.
            ans.push_back(matrix[i][ending_col]);
            count++;
        }
        ending_col--;

        // Step 3 : Now print ending Row, So to print ending row we run start from cols (ending cols to starting cols) so we use >= and -- to decrement.
        for (int i = ending_col; i >= starting_col && count < total_ele; i--)
        {
            // here we are printing ending row and i elements(ending to start)
            ans.push_back(matrix[ending_row][i]);
            count++;
        }
        ending_row--;

        // Step 4 : Now print starting col. so we have to go from row wise, to get each starting element of rows,
        for (int i = ending_row; i >= starting_row && count < total_ele; i--)
        {
            ans.push_back(matrix[i][starting_col]);
            count++;
        }
        starting_col++;
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> res = Spiral_matrix(matrix);

    for(int x : res){
        cout<<x<<" ";
    }
}