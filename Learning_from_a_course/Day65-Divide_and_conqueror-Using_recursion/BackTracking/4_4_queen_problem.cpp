// In the 4 queen problem, we have 4 queens (which attack row, column, diagonal wise) so place the queens in such a order that not two queens could harm each other (generally in 4 X 4 chess board)

// In the 4 queen problem, we have 4 queens (which attack row, column, diagonal wise) so place the queens in such a order that not two queens could harm each other (generally in 4 X 4 chess board)

#include <iostream>
#include <vector>
using namespace std;

void printsol(vector<vector<char>> &board, int n)
{
    // now print the vector
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}


// now create issafe ()
// OPTIMIZED: Instead of scanning board, we use hash arrays for O(1) safety check
bool issafe(int row, int col,
            vector<int> &rowhash,
            vector<int> &upperDiaghash,
            vector<int> &lowerDiaghash,
            int n)
{
    // we can find safe spot by checking into 3 directions, as a queen moves (upper left diagonal, bottom left diagonal)

    // check row on left side :
    if(rowhash[row] == 1)
        return false;

    // upper left diagonal :
    if(upperDiaghash[n - 1 + col - row] == 1)
        return false;

    // bottom left diagonal :
    if(lowerDiaghash[row + col] == 1)
        return false;

    // if still not found queen it is safe position :
    return true;
}

void solve(vector<vector<char>> &board,
           int col,
           int n,
           vector<int> &rowhash,
           vector<int> &upperDiaghash,
           vector<int> &lowerDiaghash)
{
    // Base case / stopping condition : when we place all the 4 queens in 4 cols we stop
    if (col >= n)
    {
        printsol(board, n);
        return;
    }

    // solve one case and let recursion handle rest : the case would be try to place a queen in every row
    for (int row = 0; row < n; row++)
    {
        // now we check is it safe to place the queen here?
        if (issafe(row, col, rowhash, upperDiaghash, lowerDiaghash, n))
        {
            // if safe place the queen in that row
            board[row][col] = 'Q';

            // mark the queen in hash arrays so future checks become O(1)
            rowhash[row] = 1;
            upperDiaghash[n - 1 + col - row] = 1;
            lowerDiaghash[row + col] = 1;

            // now let recursion handle rest
            solve(board, col+1, n, rowhash, upperDiaghash, lowerDiaghash);

            // now use backtracking to remove the queen which placed earlier, (0 = no queen,1 = queen)
            board[row][col] = '-';

            // remove marks from hash arrays during backtracking
            rowhash[row] = 0;
            upperDiaghash[n - 1 + col - row] = 0;
            lowerDiaghash[row + col] = 0;
        }
    }
}

int main()
{
    // create a 4 X 4 board
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '-'));

    // hash arrays to optimize issafe check from O(n) to O(1)
    vector<int> rowhash(n, 0);
    vector<int> upperDiaghash(2*n - 1, 0);
    vector<int> lowerDiaghash(2*n - 1, 0);

    int col = 0;

    // function call :
    solve(board, col, n, rowhash, upperDiaghash, lowerDiaghash);

    return 0;
}