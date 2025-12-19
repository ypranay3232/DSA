/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].



in simple words :
given an array of integers for nums, and target is a single integer, if nums array indices should
match  with target if matched return the indices.

*/

// 1) Brute Force Approach : O(n^2) because we used two nested loops

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    // create a loop that iterates from nums 0 to end which is i
    for (int i = 0; i < nums.size(); i++)
    {
        // another loop that checks from index 1 to end which is J
        for (int j = i + 1; j < nums.size(); j++)
        {
            // now check if both index add up to the target ? if yes return the index
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
}

// 2) Optimised Solution : Using hashtable (we use a unordered map) that stores elements in key value pairs and in unique fashion and stores in a hashtable

vector<int> Optimised_TwoSum(vector<int>&nums1,int target1){
    // create a unordered map
    unordered_map<int,int>map;
    // Now loop thorough the nums array
    for(int i =0;i<nums1.size();i++){
        // now find the two numbers which add up to target, formula =  target = nums[i] + wanted_num 
        int wanted_number = target1 - nums1[i]; 
        // check if the wanted_number exist in map ?
        if(map.count(wanted_number)){
            // if found return the index of wanted number in map and i (current index)
            return {map[wanted_number],i};
        }
        // if not found then store this current nums[i] into map memory so it can find this
        // if future 

        map[nums1[i]] = i;

    }
}


int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    // To print a vector we always use a for loop
    cout << "The indices of nums which make up the result are : " << endl;
    for (int x : result)
    {
        cout << x;
    }
    cout<<endl;

    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = Optimised_TwoSum(nums1, target1);
    // To print a vector we always use a for loop
    cout << "The indices of nums which make up the result are : " << endl;
    for (int x1 : result1)
    {
        cout << x1;
    }
}