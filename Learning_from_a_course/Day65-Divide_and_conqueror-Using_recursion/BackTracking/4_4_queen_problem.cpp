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
    cout << endl
         << endl;
}

// now create issafe ()
bool issafe(int row, int col, vector<vector<char>> &board, int n)
{
    // we can find safe spot by checking into 3 directions, as a queen moves (upper left diagonal, bottom left diagonal)
    int i,j;

    // check row on left side :
    for (j = 0; j < col; j++)
        if (board[row][j] == 'Q')
            return false;

    // upper left diagonal :
    for (i = row -1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // bottom left diagonal :
    for (i = row + 1, j = col -1; j >= 0 && i < n; i++, j--)
        if (board[i][j] == 'Q')
            return false; // Fixed: check for 'Q', not 1

    // if still not found queen it is safe position :
    return true;
}

void solve(vector<vector<char>> &board, int col, int n)
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
        if (issafe(row, col, board, n))
        {
            // if safe place the queen in that row
            board[row][col] = 'Q';
            // now let recursion handle rest
            solve(board, col+1, n);
            // now use backtracking to remove the queen which placed earlier, (0 = no queen,1 = queen)
            board[row][col] = '-';
        }
    }
}

int main()
{
    // create a 4 X 4 board
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;
    // function call :
    solve(board, col, n);
    return 0;
}