#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    // Given an sorted array, remove duplicates and return unique elements
    // From a sorted array, keep only one copy of each number, put all unique numbers at the
    // front, and return how many unique numbers exist.

    // Observation : If an array is sorted then the duplicates are always next to each other
    // and we have to modify the elements not delete them, an only first k letters matter

    // initialize two pointers i is at index 0 and j checks if it is == i then duplicate
    int i = 0;
    for (int j = i; j < nums.size(); j++)
    {
        // now check if unique element is found then move i to next index
        if (nums[j] != nums[i])
        {
            i++;
            // and if nums[j] ! = nums{i} means nums[j] is unique so store it in nums[i]
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k = removeDuplicates(nums);
    cout << "Unique count: " << k << endl;
    cout << "Array after removing duplicates: ";
    for(int i =0; i<k;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}