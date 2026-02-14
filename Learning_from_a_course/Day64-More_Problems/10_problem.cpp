#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int deleteAndEarn(vector<int>& nums)
{
    if(nums.empty()) return 0;

    // Step 1: Find maximum value to size our points array
    int maxVal = *max_element(nums.begin(), nums.end());

    // Step 2: Create points array where
    // points[i] = total points we gain by taking number i
    vector<int> points(maxVal + 1, 0);

    for(int num : nums)
    {
        points[num] += num;
    }

    // Step 3: Apply House Robber DP on points array

    int prev1 = 0; // dp[i-1]
    int prev2 = 0; // dp[i-2]

    for(int i = 0; i <= maxVal; i++)
    {
        int skip = prev1;           // skip current number
        int take = prev2 + points[i]; // take current number

        int curr = max(skip, take);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    vector<int> nums = {2,2,3,3,3,4};
    cout << deleteAndEarn(nums);
}