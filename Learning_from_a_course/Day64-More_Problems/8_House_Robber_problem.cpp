// you are a professional robber planning to rob houses along a street, each house has a certain amount of money, the problem is "adjacent houses has security systems" if two adjacent houses are broken on same night they contact police.

// Rob the max amount of money without alerting the police.

// The approach is to rob the two extremes, not to rob in a sequence as even and odd.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> memo;

// recursive approach :
int solve(int houses, const vector<int> &nums)
{
    // base case : stop if no more houses
    if (houses >= nums.size())
        return 0;

    // return cached result if weave been here before
    if (memo[houses] != -1)
        return memo[houses];

    // recursion :
    int rob = nums[houses] + solve(houses + 2, nums);
    int skip = solve(houses + 1, nums);

    // store and return the values
    return memo[houses] = max(rob, skip);
}

int main()
{
    vector<int> houses = {2, 7, 9, 3, 1};
    // Initialize memo with -1
    memo.assign(houses.size(), -1);
    int result = solve(0, houses);

    cout << "Total Money Stolen: $" << result << endl;

    // Iterative approach :
    vector<int> nums = {2, 7, 9, 3, 1};
    int prev2 = 0, prev1 = 0; // Max money if we stopped 2 houses ago,1 house ago

    for (int money : nums)
    {   // Option A: Rob this house + the max from 2 houses ago
        // Option B: Skip this house and take the max from 1 house ago
        int current = max(money + prev2, prev1);
        // Move our "windows" forward
        prev2 = prev1;
        prev1 = current;
    }

    cout << "Total Money Stolen: $" << prev1 << endl;
    return 0;
}