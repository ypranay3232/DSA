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
using namespace std;


// Brute force solution: O(n^2)
int findPairsBruteForce(vector<int> &nums, int k)
{
    int n = nums.size(); 
    set<pair<int, int>> uniquePairs; // To store unique (small, large) pairs

    // Outer loop: pick the first element of the pair
    for (int i = 0; i < n; i++)
    { // Iterate i from 0 to n-1
        // Inner loop: pick the second element of the pair
        for (int j = i + 1; j < n; j++)
        {                                      // j starts from i+1 so i != j
            int diff = abs(nums[i] - nums[j]); 

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

int main(){
    vector<int> nums = {1,2,3,4,5};
    int k = 1;
    int res = findPairsBruteForce(nums,k);
    cout<<"The ans is : "<<res<<endl;
}