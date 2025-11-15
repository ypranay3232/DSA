/* A famous question from leetcode find duplicate number :

287. Find the Duplicate Number
Medium

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// (n+1 integers where range is (1-n) so there should be N integers but has an extra integer n+1)

// There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.



Example 1:

Input: nums = [1,3,4,2,2] // Here in input array we have 5 values (if we remove that extra 1) our elements are (n = 4) and as we can see that one element is repeating more than 1 time (its 2) so we print that repeating number.
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3


Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n

// All the integers in nums appear only once except for precisely one integer which appears two or more times.


Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?

*/

// we have many approaches to solves this :

// 1) use sort() to find duplicates, but how we find it, we simply add a condition that checks if (i == i+1) if true means both values are same so print that value and iterate the loop upto n-1. because n-1 is last index of a iteration.

// Time complexity is O(N logn) space : O(N)

// 2) so We follow another approach called Negative marking method. Here we assume the array values as index (assume : nums[i] is index now we iterate through each inedx and mark as visited, and if we find an element which is already visited we mark it as duplicate)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// now create a function that finds duplicate elements
int find_dup(vector<int> &nums)
{
    // now we sort the array
    sort(nums.begin(), nums.end());

    // now loop the aray to check the condition
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return nums[i];
        }
    }
    return -1;
}

int find_dup1(vector<int> &nums)
{
    // for 2nd approach :
    int ans = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]);

        // now check if an element is already visited ? it should be in -ve because we mark it.
        if (nums[index] < 0)
        {
            ans = index;
            break;
        }
        nums[index] *= -1; // we mark the visited value as -ve
    }
    return ans;
}

// approach 3 : Positioning Method. Here we think of sending the elements to their respective position so ex: 1,3,4,2,2. so if we swap them with the index : 1,2,3,4 (extra 2) can't be stored because already a 2 exist at the index 2.

int find_dup2(vector<int> &original)
{
    // Approach 3 :
    while (original[0] != original[original[0]])
    {
        // if the starting element is not at their respective index we swap the value with their index
        swap(original[0], original[original[0]]);
    }
    return original[0]; // here after swapping when we have a value which is at index 0 and also at its respective index then we call it a duplicate element and we return it.
}
int main()
{
    // first create an array
    vector<int> nums = {1, 3, 4, 2, 2};
    vector<int> original = {1, 3, 4, 2, 2};
    // now call the function
    cout << "The Duplicate element using navie approach : " << find_dup(nums) << endl;

    cout << "The Duplicate element By changing index to negative : " << find_dup1(nums)<<endl;
    // but this breaks a condition in questoin that we shouldn't change the array (dont mark the array as -ve)but we did it. 
    
    
    // So we use approach 3. And here also we are modifying the array. so we use binary search.
    cout << "The Duplicate element by swapping values to index : " << find_dup2(original);
}
