/*
53. Maximum Subarray

Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

because we solve it as using two pointers i,j = i points to 1st index j points to 2nd index [i,j] sum for each element and we find the maxsubarray

*/
// 1)Brute force approach : looping through all sub arrays
#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    // 1) Brute force checks every possible subarray to find which has largest sum
    int result = nums[0];
    // now loop through the nums
    for (int i = 0; i < nums.size(); i++)
    {
        // keep track to current sum
        int currentsum = 0;
        // now another loop to start after i
        for (int j = i; j < nums.size(); j++)
        {
            // now we have nums (1st index and 2nd index from i,j) so sum both. Update currentsum
            currentsum = currentsum + nums[j];
            // now update result as : if currentsum is better than result then push it to result
            result = max(result, currentsum);
        }
    }

    return result;
}
// 2) Optimised using Ka

// 2) Optimised using Kadane's algorithm : Idea is to loop through an array only one time, when both numbers result of sum leads to a negative value we abandon and create a new streak with both two elements.
// first create two variables 1) for max sum, another for currentmaxending upto the index
int maxSubArray_Optimised(vector<int> &nums1)
{
    int maxsumtilnow = nums1[0];
    int currentmaxelement = nums1[0];
    // now loop through the array
    for (int i = 1; i < nums1.size(); i++)
    {
        // step1 : decision currentmaxelement can either start a new streak or continue with old
        currentmaxelement = max(nums1[i], currentmaxelement + nums1[i]);
        // works as : sum of current ele of nums + nums[0] = currentmaxele.
        // now check if maxsumtilnow is less than currentmaxelement then update it
        maxsumtilnow = max(maxsumtilnow, currentmaxelement);
    }
    return maxsumtilnow;
}
int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result1 = maxSubArray(nums);
    cout << "The maximum sub array is : " << result1 << endl;

    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result2 = maxSubArray_Optimised(nums1);
    cout << "The maximum sub array is : " << result2 << endl;
}