// Rat in a maze : find out a path for rat to get out of maze( try all possibilities and backtrack when a path is valid)

// given a grid N X N containing 0, 1 (0 -> path is blocked rat cant move, 1-> open path rat can move)
// rat starts at top-left : and wants to reach bottom-right(N-1,N-1)

// The rat can move : Down(D),Left(L),Right(R),Up(U)

/*
maze =
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

Down → Down → Right → Down → Right → Right
at every cell we have 4 choices :
       Up
       ↑
Left ← Rat → Right
       ↓
      Down

So recursion will: Try each direction If valid → move and If invalid → backtrack


Why Backtracking is Needed
Example:

1 1 0
1 0 1
1 1 1

Suppose rat goes right, right → stuck

Now it must go back and try another direction → Down
*/

#include <iostream>
#include <vector>
using namespace std;

// Check if position is valid
bool isSafe(int x, int y, int n,
            vector<vector<int>> &maze,
            vector<vector<bool>> &visited)
{
    // Condition 1: inside maze boundaries
    // Condition 2: cell must be 1 (open)
    // Condition 3: not already visited
    if (x >= 0 && x < n &&
        y >= 0 && y < n &&
        maze[x][y] == 1 &&
        visited[x][y] == false)
    {
        return true;
    }

    return false;
}
void solve(int x, int y,
           vector<vector<int>> &maze,
           int n,
           vector<string> &result,
           string path,
           vector<vector<bool>> &visited)
{
    // BASE CASE: destination reached
    if (x == n - 1 && y == n - 1)
    {
        result.push_back(path);
        return;
    }
    // Mark current cell visited
    visited[x][y] = true;
    // DOWN
    int newX = x + 1;
    int newY = y;

    if (isSafe(newX, newY, n, maze, visited))
    {
        path.push_back('D'); // add move
        solve(newX, newY, maze, n, result, path, visited);
        path.pop_back(); // backtrack
    }
    // LEFT
    newX = x;
    newY = y - 1;

    if (isSafe(newX, newY, n, maze, visited))
    {
        path.push_back('L');
        solve(newX, newY, maze, n, result, path, visited);
        path.pop_back();
    }
    // RIGHT
    newX = x;
    newY = y + 1;

    if (isSafe(newX, newY, n, maze, visited))
    {
        path.push_back('R');
        solve(newX, newY, maze, n, result, path, visited);
        path.pop_back();
    }
    // UP
    newX = x - 1;
    newY = y;

    if (isSafe(newX, newY, n, maze, visited))
    {
        path.push_back('U');
        solve(newX, newY, maze, n, result, path, visited);
        path.pop_back();
    }
    // BACKTRACK: unmark visited
    visited[x][y] = false;
}
vector<string> findPath(vector<vector<int>> &maze, int n)
{
    vector<string> result;

    // Edge case: start blocked
    if (maze[0][0] == 0)
        return result;

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    string path = "";

    solve(0, 0, maze, n, result, path, visited);

    return result;
}

int main()
{
    // Define maze
    vector<vector<int>> maze =
        {
            {1, 0, 0, 0},
            {1, 1, 0, 1},
            {1, 1, 0, 0},
            {0, 1, 1, 1}};

    int n = maze.size();

    vector<string> result = findPath(maze, n);

    cout << "All Paths:\n";

    for (string path : result)
    {
        cout << path << endl;
    }

    return 0;
}