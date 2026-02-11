// given an array : 1,2,3,4,5 printing all the sub arrays will be as follow :
// 1,2,3,4,5 then (1,2) (1,2,3) (1,2,3,4) (1,2,3,4,5)

// we have two pointers start and next, start will be fixed to value 1, which tells we need to move from 1 to 2,3,4,5.  when we are in first subarray 1. start = 0 and end = start,  now after one iteration start = 0, end = end+1. and start = 0, end = end +2, end + 3, end + 4.

// now move to next set of sub array '2' : here start = 1, end = start, start = 1, end = end + 1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printsubarrays_util(vector<int> &nums, int start, int end){
    // base case : stop when reach the end of array
    if(end == nums.size()){
        return ;
    }

    // 1st case : when printing 1 sub array
    for(int i = start;i<=end;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;//printing one sub array 

    // Recursion to increment end + 1,2,3,4
    printsubarrays_util(nums,start,end+1);
}

// for case 2 : 
void printsubarrays(vector<int> &nums){
    for(int start=0;start<nums.size();start++){
        int end = start;
        printsubarrays_util(nums,start,end);
    }
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5};
    
    printsubarrays(nums);   
    return 0;
}