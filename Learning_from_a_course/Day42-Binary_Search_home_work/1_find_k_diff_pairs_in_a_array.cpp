/*
Leetcode medium problem 532 :  K-diff Pairs in an Array

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length (both should be in range of 0 and ,lenght)
i != j (i and j should not equal to each other)
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val. (use absolute function dont worry about +, -)



Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).


Constraints:

1 <= nums.length <= 104
-107 <= nums[i] <= 107
0 <= k <= 107


1) approach : Brute force
2) two pointers
3)Binary search
*/

// Brute force approach :

#include <iostream>
#include <vector>
#include <set>
#include<algorithm>
using namespace std;


// Brute force solution: O(n^2)
int findPairsBruteForce(vector<int> &nums, int k)
{
    int n = nums.size(); 
    set<pair<int, int>> uniquePairs; // To store unique (small, large) pairs

    // pick the first element of the pair
    for (int i = 0; i < n; i++)
    { // Iterate i from 0 to n-1
        // pick the second element of the pair
      
        // j starts from i+1 so i != j
        for (int j = i + 1; j < n; j++)
        {
            int diff = abs(nums[i] - nums[j]); //makes both i,j non negative

            if (diff == k)
            {
                int a = min(nums[i], nums[j]); // Normalize pair: smaller value first
                int b = max(nums[i], nums[j]); // Larger value second
                uniquePairs.insert({a, b});    // Insert into set to ensure uniqueness
            }
        }
    }

    // The number of unique k-diff pairs is the size of the set
    return (int)uniquePairs.size(); // Convert size_t to int
}

int findviaBinarysearch(vector<int>&nums, int k){
    // first sort the array 
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;//counter to count k different pairs
    
    // loop the array and skip duplicates
    for(int i =0;i<n;i++){
        // if found duplicate skip it.
        if(i>0 && nums[i] == nums[i-1]){
            continue;
        }
        int target = nums[i]+k;

        // now search the sub array.
        bool found = binary_search(nums.begin()+i+1, nums.end(),target);
        if(found){
            count ++;
        }
    }
    return count;

}

// Two-pointer solution: O(n log n) due to sorting
int findPairsTwoPointers(vector<int>& nums, int k) {

    // Step 1: sort the array 
    sort(nums.begin(), nums.end());

    int n = nums.size(); // Store array length
    int i = 0; // Left pointer
    int j = 1; // Right pointer (always ahead of i)
    int count = 0; // To count unique k-diff pairs

    // Step 2: move pointers until both are within array 
    while (i < n && j < n) {  // Loop as long as i and j are valid
        if (i == j) {   // Ensure i != j
            j++;   // Move j forward if they are equal
            continue;  // Skip to next iteration
        }

        long long diff = (long long)nums[j] - nums[i]; // Calculate difference

        if (diff == k) {// Found a k-diff pair
            count++;  // Increase count of unique pairs

            int leftVal = nums[i];// Value at index i
            int rightVal = nums[j]; // Value at index j

            // Skip duplicates on the left side so we don't count same pair again
            while (i < n && nums[i] == leftVal) {
                i++; // Move i until nums[i] changes
            }

            // Skip duplicates on the right side
            while (j < n && nums[j] == rightVal) {
                j++;  // Move j until nums[j] changes
            }
        }
        else if (diff < k) {  // Difference too small
            j++;// Move right pointer to increase difference
        }
        else {// diff > k, difference too large
            i++; // Move left pointer to reduce difference
        }
    }

    return count; // Return total unique k-diff pairs
}



int main(){
    vector<int> nums = {3,1,4,1,5};
    int k = 2;
    int res = findPairsBruteForce(nums,k);
    int res1 = findviaBinarysearch(nums,k);
    int res2 = findPairsTwoPointers(nums,k);
    cout<<"The ans is : "<<res<<endl;//returns 2 because we have only 2 possible pairs in the array (1,3) (3,5)
    cout<<"The ans is : "<<res1<<endl;//returns 2 because we have only 2 possible pairs in the array (1,3) (3,5)
    cout<<"The ans is : "<<res2<<endl;//returns 2 because we have only 2 possible pairs in the array (1,3) (3,5)
}