#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    // 1. Brute Force

    // // Calculate the sum of elements to the left and right of nums and compare them to find evidence
    // int len = nums.size();

    // // now loop through the length of nums and sum both left and right
    // for(int i =0;i<len;i++){
    //     // for left we want a slice of sum from 0 to i, so begin() o to begin()+1 so (o - i) i = middle
    //     int left = accumulate(nums.begin(),nums.begin()+i,0);
    //     // i is pivot middle so from middle + 1, we start the sum.
    //     int right = accumulate(nums.begin()+i+1,nums.end(),0);

    //     // check if both are equal
    //     if(left == right){
    //         return i;
    //     }
    // }
    // return -1;

    // 2. Optimised Solution
    // find length of array, and if length of array is 0 return 0
    int len = nums.size();
    if (len == 0)
        return 0;
    // create a new array called sum and same size as len/nums
    vector<int> sum(len);
    // initializes array starting with 0/nums starting
    sum[0] = nums[0];
    // now loop through the nums array
    for (int i = 1; i < len; i++)
    {
        // now store the total sum in sum array, from nums 0 to nums i -1(last element)
        sum[i] = nums[i] + sum[i - 1];
    }
    // now find left and right sum
    for (int i = 0; i < len; i++)
    {
        // define left as total sum - nums i
        int left = sum[i] - nums[i];
        int right = sum[len - 1] - sum[i];

        // check if left == right
        if (left == right)
        {
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> nums  = {1,7,3,6,5,6};
    int result = pivotIndex(nums);
    cout<<"The Pivot Element is : "<<result<<endl;
}