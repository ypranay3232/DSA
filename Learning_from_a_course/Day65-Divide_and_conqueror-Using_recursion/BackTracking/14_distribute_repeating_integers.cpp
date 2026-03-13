#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Helper function to perform backtracking with pruning.
     * counts: Available frequency buckets of integers.
     * quantity: The requirements for each customer.
     * idx: Current customer index we are trying to satisfy.
     */
    bool backtrack(vector<int>& counts, const vector<int>& quantity, int idx) {
        // Base Case: If we've satisfied all customers, we're done!
        if (idx == quantity.size()) {
            return true;
        }

        for (int i = 0; i < counts.size(); ++i) {
            // PRUNING 1: Skip duplicate buckets. 
            // If the previous bucket had the same capacity and failed, this one will too.
            if (i > 0 && counts[i] == counts[i - 1]) continue;

            // Check if current frequency bucket can satisfy the customer's quantity
            if (counts[i] >= quantity[idx]) {
                counts[i] -= quantity[idx]; // Choose
                
                if (backtrack(counts, quantity, idx + 1)) return true; // Explore
                
                counts[i] += quantity[idx]; // Un-choose (Backtrack)
            }
        }
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        // Step 1: Count frequencies of each number
        unordered_map<int, int> freqMap;
        for (int x : nums) freqMap[x]++;

        vector<int> counts;
        for (auto const& [val, count] : freqMap) {
            counts.push_back(count);
        }

        // PRUNING 2: Sort quantities descending (Largest requirements first)
        // This is the most important optimization for early exits.
        sort(quantity.rbegin(), quantity.rend());

        // PRUNING 3: Sort counts descending
        sort(counts.rbegin(), counts.rend());

        // PRUNING 4: We only need as many buckets as there are customers
        if (counts.size() > quantity.size()) {
            counts.resize(quantity.size());
        }

        return backtrack(counts, quantity, 0);
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4, 4, 4, 4};
    vector<int> quantity1 = {2, 2};
    cout << "Test 1: " << (sol.canDistribute(nums1, quantity1) ? "True" : "False") << endl;
    // Explanation: Number '4' appears 4 times. Can satisfy two customers needing 2 each.

    // Test Case 2
    vector<int> nums2 = {1, 2, 3, 3};
    vector<int> quantity2 = {2};
    cout << "Test 2: " << (sol.canDistribute(nums2, quantity2) ? "True" : "False") << endl;
    // Explanation: Number '3' appears 2 times. Can satisfy one customer needing 2.

    // Test Case 3
    vector<int> nums3 = {1, 1, 2, 2};
    vector<int> quantity3 = {3};
    cout << "Test 3: " << (sol.canDistribute(nums3, quantity3) ? "True" : "False") << endl;
    // Explanation: No single number appears 3 times.

    return 0;
}