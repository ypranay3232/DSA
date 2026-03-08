#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    // // 1) Brute force checks every possible subarray to find which has largest sum

    // int result = nums[0];
    // // now loop through the nums
    // for(int i =0;i<nums.size();i++){
    //     // keep track to current sum
    //     int currentsum = 0;
    //     // now another loop to start after i
    //     for(int j = i; j<nums.size();j++){
    //         // now we have nums (1st index and 2nd index from i,j) so sum both. Update currentsum
    //         currentsum = currentsum + nums[j];
    //         // now update result as : if currentsum is better than result then push it to result
    //         result = max(result,currentsum);
    //     }
    // }

    // return result;

    // 2) Optimised using Kadane's algorithm : Idea is to loop through an array only one time, when both numbers result of sum leads to a negative value we abondon and create a new streak with both two elements.
    // firest create two variables 1) for max sum, another for currentmaxending upto the index
    int maxsumtilnow = nums[0];
    int currentmaxelement = nums[0];
    // now loop through the array
    for (int i = 1; i < nums.size(); i++)
    {
        // step1 : decision currentmaxelement can either start a new streak or continue with old
        currentmaxelement = max(nums[i], currentmaxelement + nums[i]);
        // works as : sum of current ele of nums + nums[0] = currentmaxele.
        // now check if maxsumtilnow is less than currentmaxelement then update it
        maxsumtilnow = max(maxsumtilnow, currentmaxelement);
    }
    return maxsumtilnow;
}
int main() {
    // Test Case 1: Standard mixed array
    vector<int> case1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max Subarray Sum (Case 1): " << maxSubArray(case1) << endl; 
    // Output: 6 (Subarray: [4, -1, 2, 1])

    // Test Case 2: All negative numbers
    vector<int> case2 = {-5, -1, -8, -2};
    cout << "Max Subarray Sum (Case 2): " << maxSubArray(case2) << endl; 
    // Output: -1 (Subarray: [-1])

    // Test Case 3: Single element
    vector<int> case3 = {10};
    cout << "Max Subarray Sum (Case 3): " << maxSubArray(case3) << endl; 
    // Output: 10

    return 0;
}