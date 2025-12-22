#include <iostream>
#include <vector>
using namespace std;

int moveZeroes(vector<int> &nums)
{

    // 1. First Approach is using a TWO Pointer Approach :
    // First create a variable to store non-zero numbers
    int nonZeroNums = 0;
    // Now loop through the array and check if current number is equal to zero.
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            // If not equal swap the current element which is non zero into nonZeroNums variable
            swap(nums[nonZeroNums], nums[i]);
            // now move to next index
            nonZeroNums++;
        }
    }
}

int main(){
    vector<int> nums = {0,1,0,3,12};
    int result = moveZeroes(nums);
    for(int x : nums){
        cout<<"the output is : "; 
        cout<<x<<endl; 
    }
}