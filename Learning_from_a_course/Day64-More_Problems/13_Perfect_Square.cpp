// given an integer n, return the least number if perfect squares whose sum is == n
// ex of perfect squares : 1,4,9 (3 root = 2, 9 root = 3 etc)  any number root value should not be in points is should be perfect integer number not a float number.

// use some perfect squares and make N, ex: n = 12 so using perfect squares : 1,4. if we sue the 1 we have to use 1+1+1+...1 = 12 (we need 12 1's to get 12) but we need to find the least amount of numbers used to find N. ex: 4 = 4+4+4 = 12 (3 4's are used )

#include <iostream>
#include<vector>
using namespace std;

int numSquares(int n)
{
    // create a static array to store squares
    static vector<int> dp{0};
    // while array size < n
    while (dp.size() <= n)
    {
        int m = dp.size(), squares = INT_MAX;
        // generate the squares
        for (int i = 1; i * i <= m; ++i)
            squares = min(squares, dp[m - i * i] + 1);
        // push them back into array and return it
        dp.push_back(squares);
    }
    return dp[n];
}

int main(){
    int n = 12;
    cout<<"The  min no of perfect square's required for "<<n<<" is : "<<numSquares(n);
}