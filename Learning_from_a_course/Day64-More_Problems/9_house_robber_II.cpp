#include <iostream>
#include <vector>
using namespace std;

// Recursive robber for linear range
int solve(vector<int>& nums, int i, int end)
{
    // Base case: crossed boundary
    if(i > end)
        return 0;

    // Option 1: Rob this house
    int rob = nums[i] + solve(nums, i+2, end);

    // Option 2: Skip this house
    int skip = solve(nums, i+1, end);

    return max(rob, skip);
}

int rob(vector<int>& nums)
{
    int n = nums.size();

    // Edge case: only one house
    if(n == 1)
        return nums[0];

    // Case 1: exclude last
    int case1 = solve(nums, 0, n-2);

    // Case 2: exclude first
    int case2 = solve(nums, 1, n-1);

    return max(case1, case2);
}

int main()
{
    vector<int> nums{2,3,2};
    cout << rob(nums);
}