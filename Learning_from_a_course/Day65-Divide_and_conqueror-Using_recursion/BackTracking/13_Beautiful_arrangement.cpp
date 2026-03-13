// Given N integers labeled 1 to n, The permutation of n integers should be : perm[i] % i == 0 or i % perm[i] == 0;

/*
ex :  2 1
index 1 2

when i = 1 : 2 % 1 = 0  (perm[i] % i == 0)
             1 % 2 != 0 (X) (i % perm[i]% == 0 )

             any one of the condition should be true

when i = 2: 1 % 2 != 0;
             or
            2 % 1 == 0
the beautiful arrangement is : 2 (1,2 and 2,1)
*/

#include <iostream>
#include <vector>
using namespace std;

void backtrack(int n, int pos, vector<bool> &visited,int &count)
{
    // Base case: If we've successfully placed numbers in all positions
    if (pos > n)
    {
        count++;
        return;
    }

    // Try placing every available number from 1 to n at the current position 'pos'
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && (i % pos == 0 || pos % i == 0))
        {
            visited[i] = true;              // Choose
            backtrack(n, pos + 1, visited,count); // Explore
            visited[i] = false;             // Unchoose (Backtrack)
        }
    }
}

int countArrangement(int n)
{   
    int count = 0;
    vector<bool> visited(n + 1, false);
    backtrack(n, 1, visited,count);
    return count;
}

int main()
{
    int n = 3;
    cout << "Beautiful Arrangements for n=" << n << ": " << countArrangement(n) <<endl;
    return 0;
}