/* LeetCode Problem 75 :

75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.


Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]


Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.


Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/

// There are N number of solutions to this question. But we focus on optimised solution : Dutch National Flag Algorithm 
//  as we can think of it as : a two pointer or triplet sum. We just need 3 pointers (start,end,mid which traverse thoughout array)

// we do as : we check the mid value with high ? (mid<=high) then if(mid == 0) then swap it with start, so we get 0 at start and then we increment both (start ++ so we dont repeat operations on same index) and mid++ so we can move to next index

#include <iostream>
#include <vector>
using namespace std;

// creating a function and take reference of vector and a argument arr to the function
void sort_colors(vector<int> &arr)
{
    // declare the size of array and create 3 pointers
    int n = arr.size();
    int start = 0, mid = 0, end = n - 1;

    // now check the condition (if mid< end) ofc it is then check if mid == 0
    while (mid <= end)
    {
        if (arr[mid] == 0)
        {
            // if equal then swap mid with low and increment start and mid so we dont repeat operations on same index
            swap(arr[start], arr[mid]);
            ++start;
            ++mid;
        }
        else if (arr[mid] == 1)
        {
            // if equal to 1 then no need to swap because we already placed 0's in array so we get the 1's in order. now increment the mid to move to next index.
            ++mid;
        }
        else
        {
            // if the element is 2 then we swap it with high
            swap(arr[mid], arr[end]);
            --end;
        }
    }
}

int main()
{
    // now lets create a vector with values :
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    // now create a function that does the sorting of array in order
    sort_colors(arr);
    // now iterate through the array
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}