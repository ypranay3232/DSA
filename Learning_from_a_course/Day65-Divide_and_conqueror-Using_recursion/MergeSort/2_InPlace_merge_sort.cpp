// Leetcode : 912 Sort an array

// Given an array "nums", sort it in ascending order and return it. NOTE: dont use any inbuilt functions and return time space in most optimised sol

#include <iostream>
#include <vector>
using namespace std;

// Function to sort array
vector<int> sortArray(vector<int> &nums)
{
    // create an frequency array of 1000 and initialize them with 0's
    int freq[100001] = {0};
    // NOTE : arrays cant have -ve index so, so we add 50,000 to every number in array.
    for (int i = 0; i < nums.size(); i++)
    {
        freq[nums[i] + 50000]++;
    }
    // now loop the freq array for smallest to largest values.
    int j = 0;
    for (int i = 0; i < 100001; i++)
    {
        // if a element has value > 0, that exist in our list. so we subtract the number - 50,000 (overwriting the original array )
        while (freq[i] > 0)
        {
            nums[j] = i - 50000;
            freq[i]--;
            j++;
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {5, 2, 3, 1};
    nums = sortArray(nums);
    for (int x : nums)
        cout << x << " ";
}