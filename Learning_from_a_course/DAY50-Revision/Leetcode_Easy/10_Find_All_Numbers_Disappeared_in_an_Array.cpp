#include <iostream>
#include <vector>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    // Given an array nums of size N. contains elements from 1 - N. some numbers are missing
    // ex: nums = [4,3,2,7,8,2,3,1] 5,6  are missing from 1-8 range and some are repeating

    // Approach : we use the array as a checklist by turning numbers into -ve to check visited

    // s1: mark numbers that exist, loop through the array(values) then go to that position of value (assume it as index) and mark that position (index value) as -ve so we can say that the element is visited/ that number exist.

    // How it works : First number: 4

    /*index = abs(4) - 1 = 3

    Go to index 3 and make it negative:

    [4,3,2,-7,8,2,3,1]*/

    // Step1:
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        // create a variable index that takes first value of array -1.
        int index = abs(nums[i]) - 1;
        // now check if array[index] > 0 if greater than 0, mark it -ve
        if (nums[index] > 0)
        {
            nums[index] = -nums[index];
        }
    }
    // step2: find the missing elements: Now we check the array again.
    // Rule: If a position is positive, it was never marked, That means its number is missing

    for (int i = 0; i < nums.size(); i++)
    {
        // if >0 ...+ve then it was never marked
        if (nums[i] > 0)
        {
            result.push_back(i + 1);
        }
    }
    return result;
}

int main(){
    vector<int>nums = {4,3,2,7,8,2,3,1};
    vector<int> result1 = findDisappearedNumbers(nums);
    for(int x1: result1){
        cout<<x1<<" ";
    }
}