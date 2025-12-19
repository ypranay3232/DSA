/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
*/

#include<iostream>
#include<vector>
using namespace std;

// 1) Solution of O(n) but takes extra space so space = O(n)

// define a nums array 
vector<int> Brute_force_Running_sum(vector<int>& nums){
    // first define a runningsum and sum
    vector<int> runningsum;
    int sum = 0;

    // Now to return the running sum of Nums, so loop through the nums and store sum + current number of nums, so we get (1 + 2, = 3, 3 + 3 = 6 etc )
    for(int i =0;i<nums.size();i++){
        sum = sum + nums[i];
        // now store the sum value into RunningSum
        runningsum.push_back(sum);
    }
    return runningsum;
}

// 2) Optimised solution : O(N) time and space O(1)
vector<int> optimised_runningSum(vector<int>&nums1){
    // now loop through the nums1 array
    for(int i =0;i<nums1.size();i++){
        // now apply logic as : nums[i] current index + nums[i-1], so we get : 1+1-1 = 1, then 
        // 2 + 2-1 = 3
        nums1[i] += nums1[i-1];
    } 
    return nums1;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> result = Brute_force_Running_sum(nums);
    for(int x : result){
        cout<<x<<" ";
    }
    cout<<endl;
    vector<int> nums1 = {1,2,3,4};
    vector<int> result1 = Brute_force_Running_sum(nums);
    for(int x1 : result1){
        cout<<x1<<" ";
    }
}