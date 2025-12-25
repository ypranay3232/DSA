#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{

    // // 1)Brute force approach O(N^2) and space 0(1): TO check if a number repeats, first loop through the array and create inner loop and check start it with (i+1) index so (we get i,j as [1,2] and we check if i ==j) return true we have duplicates else return false
    // for(int i =0;i<nums.size();i++){
    //     for(int j = i+1; j<nums.size();j++){
    //         if(nums[i] == nums[j]){
    //             return true;
    //         }
    //     }
    // }
    // return false;

    // // 2) Better Solution Using arrays O(N log n) Time and space O(1):
    // // First sort the array and then loop through it
    // sort(nums.begin(),nums.end());
    // // here we use size_t is an unsigned integer size_t that guarantee to store any object size
    // for(size_t i =0; i<nums.size()-1; i++){
    //     // now check if current element and its next element are equal (i,i+1) = [1,2]
    //     if(nums[i]==nums[i+1]){
    //         return true;
    //     }
    // }
    // return false;

    // 3) Optimized approach Using set:
    // // it's simple we just create a unordered set and store the values of nums in it.
    // unordered_set<int> set(nums.begin(),nums.end());
    // // Unordered set only stores unique values so we can check based on the size both
    // // in simple terms nums == 4 size, unorderset == 3 because it ignores duplicates
    // return set.size() != nums.size();

    // Its taking so much time to run so lets optimize  it: First sort the nums, then loop through it and check if current element and current element -1, before i. both are equal if yes return true we found duplicates. else return false.
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
            return true;
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    bool result = containsDuplicate(nums);

    // we use a string to make the sentence make sense
    string status = result ? "do" : "do not";
    cout << boolalpha; // This makes true/false print as "true"/"false"
    cout << result << ": The duplicates " << status << " exist." << endl;

    return 0;
}