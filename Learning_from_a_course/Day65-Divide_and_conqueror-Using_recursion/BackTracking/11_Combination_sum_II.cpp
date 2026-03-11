// given a candidates of array and find the target (required sum), return all unique combinations and : each number must be used only once, Duplicate combinations are not allowed.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// to find the combinations we use a function
void solve(vector<int> &candidate, int target, int start, vector<int> &current, vector<vector<int>> &ans)
{
    // base case :  if target ==0 all combinations are valid and return the result
    if (target == 0)
    {
        ans.push_back(current);
        return;
    }

    // now loop the candidates : from start because each number is used only once
    for (int i = start; i < candidate.size(); i++)
    {
        // if i greater than start and current candidate == previous skip
        if (i > start && candidate[i] == candidate[i - 1])
        {
            continue;
        }
        // if current candidate > target then break
        if (candidate[i] > target)
            break;
        // now add combination elements into current array
        current.push_back(candidate[i]);
        // recursive call
        solve(candidate, target - candidate[i], i + 1, current, ans);
        // backtrack
        current.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidate, int target)
{
    // sort the array of candidates
    sort(candidate.begin(), candidate.end());

    vector<vector<int>> ans;
    vector<int> current;

    solve(candidate, target, 0, current, ans);

    return ans;
}

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result = combinationSum2(candidates, target);

    cout << "Valid Combinations:\n";
    for (auto &comb : result)
    {
        cout << "[ ";
        for (int num : comb)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}