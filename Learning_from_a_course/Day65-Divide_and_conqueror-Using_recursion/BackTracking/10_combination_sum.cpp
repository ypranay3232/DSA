#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    // First sort the candidates list
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> currentCombination;

    // Use std::function to allow the lambda to call itself recursively
    function<void(int, int)> backtrack = [&](int startIndex, int remainingSum)
    {
        if (remainingSum == 0)
        {
            result.emplace_back(currentCombination);
            return;
        }

        for (int j = startIndex; j < candidates.size(); ++j)
        {
            // Optimized Pruning: If the current number is > remaining sum,
            // stop loop (rest of the sorted numbers will also be too big)
            if (candidates[j] > remainingSum)
                break;

            currentCombination.push_back(candidates[j]);
            backtrack(j, remainingSum - candidates[j]); // Reuse same index j
            currentCombination.pop_back();              // Backtrack
        }
    };

    backtrack(0, target);
    return result;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Combinations for target " << target << ":" << endl;
    for (const auto &combination : result)
    {
        cout << "[ ";
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
