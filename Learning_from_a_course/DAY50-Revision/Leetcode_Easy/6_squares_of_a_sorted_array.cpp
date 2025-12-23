/*
977. Squares of a Sorted Array

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.


Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

(.i.e. sort the array and find square values)
*/

// 1)Brute force approach :

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    // 1) brute force approach : just sort the arrays and find square values
    // first loop the array and find square values
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = nums[i] * nums[i];
    }
    // now sort the array
    sort(nums.begin(), nums.end());
    return nums;
}

vector<int> optimised_Sol(vector<int> nums1)
{
    int n = nums1.size();
    vector<int> result(n);
    // now create two pointers left and right
    int left = 0;
    int right = n - 1;
    // now fill the result array with elements from right to left, back to front
    // start from end(n-1) check if num is >0 is so decrement the array
    for (int i = n - 1; i >= 0; i--)
    {
        // now look for left and right numbers on array, if left is greater than right then square it
        if (abs(nums1[left]) > abs(nums1[right]))
        {
            result[i] = nums1[left] * nums1[left];
            // and increment left pointer to move to next index
            left++;
        }
        else
        {
            // if left < right
            result[i] = nums1[right] * nums1[right];
            right--;
        }
    }
    return result;
}
int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sortedSquares(nums);
    for (int x : result)
    {
        cout << x << " ";
    }
    cout<<endl;
    vector<int> nums1 = {-4, -1, 0, 3, 10};
    vector<int> result1 = optimised_Sol(nums1);
    for (int x1 : result1)
    {
        cout << x1 << " ";
    }
}