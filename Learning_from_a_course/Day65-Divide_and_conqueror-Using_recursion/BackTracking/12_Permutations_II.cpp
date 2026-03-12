// Leetcode 47 : 
// given a collection of nums that might contain duplicates return all possible unique combinations
// Leetcode 47 : 
// given a collection of nums that might contain duplicates return all possible unique combinations
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
 
void backtrack(vector<int>&nums, vector<vector<int>>& result,vector<int>& current, vector<bool>& used){
    // Base condition : if current combination is full length push the length  
    if(current.size() == nums.size()){
        result.push_back(current);
        return;
    }

    // now loop the nums
    for(int i = 0; i < (int)nums.size(); i++){
        // if the nums element in already in the current array skip it
        if(used[i]) continue;
        // If (current element == previous element) nums[i] == nums[i-1] and nums[i-1] was NOT used, it means we just finished a branch starting with nums[i-1]

        if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

        used[i] = true;
        current.push_back(nums[i]);
        // recursive call
        backtrack(nums,result,current,used);

        // reset the backtrack
        used[i] = false;
        current.pop_back();
    }
}

vector<vector<int>> PermutationUnique(vector<int>&nums){
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(),false);

    // sort the array 
    sort(nums.begin(),nums.end());
    backtrack(nums,result,current,used);
    return result;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = PermutationUnique(nums);
    
    cout << "The permutation of {1, 2, 3} is: " << endl;
    for(const auto& permu : result){
        cout << "[";
        for(int i = 0; i < (int)permu.size(); i++){
            cout << permu[i] << (i == (int)permu.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl; // Added newline so each permutation is on its own line
    }
    return 0;
}