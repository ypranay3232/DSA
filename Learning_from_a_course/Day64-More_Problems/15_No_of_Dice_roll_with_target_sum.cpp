// Leetcode : 1155. 
// you have N dice, each has k faces numbered from 1 to k. 

// k faces : ex: n = 3 dice, faces (k = 6) , target = 12. given 3 dice with 6 faces now get 12 value by rolling the dice. Now find total no of possible ways to get target.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int MAX_MOD = 1000000007;
        vector<int> prev(target + 1, 0);
        prev[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            vector<int> cur(target + 1, 0);
            long long windowSum = 0;
            for (int t = 1; t <= target; ++t) {
                windowSum += prev[t - 1]; 
                if (t - 1 >= k) {
                    windowSum -= prev[t - 1 - k];
                }
                cur[t] = (windowSum % MAX_MOD + MAX_MOD) % MAX_MOD;
            }
            prev = move(cur);
        }
        return prev[target];
    }
};

int main() {
    // 1. Create an instance of the Solution class
    Solution sol;

    // 2. Define test cases
    int n = 2, k = 6, target = 7;

    // 3. Call the function and print the result
    int result = sol.numRollsToTarget(n, k, target);

    cout << "Number of ways to roll " << n << " dice (with " << k 
         << " faces) to get sum " << target << " is: " << result << endl;

    return 0;
}