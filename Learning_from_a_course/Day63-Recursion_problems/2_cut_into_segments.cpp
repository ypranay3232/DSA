// given an integer n that represent the length of a rod. Determine max no of segments you can make
#include <iostream>
#include <vector>
#include <climits>
#include<algorithm>
using namespace std;

int solve(int n, int x, int y, int z, vector<int> &dp)
{
    // base case : stop when rod length is 0
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return INT_MIN;
    }

    // if we already calculated answer for length n, return it
    if (dp[n] != -1)
        return dp[n];

    int ans1 = solve(n - x, x, y, z, dp);
    int ans2 = solve(n - y, x, y, z, dp);
    int ans3 = solve(n - z, x, y, z, dp);

    // now add + 1 only if the path is valid.
    int res1 = (ans1 == INT_MIN) ? INT_MIN : ans1 + 1;
    int res2 = (ans2 == INT_MIN) ? INT_MIN : ans2 + 1;
    int res3 = (ans3 == INT_MIN) ? INT_MIN : ans3 + 1;

    // now store the result in array before returning it.
    return dp[n] = max({res1, res2, res3});
}

int main()
{
    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;
    vector<int> dp(n + 1, -1);

    int ans = solve(n, x, y, z, dp);
    if (ans < 0)
    {
        ans = 0;
    }
    cout << "Answer is : " << ans << endl;//ans = 2, bcz 7 = 5+2 
    return 0;
}