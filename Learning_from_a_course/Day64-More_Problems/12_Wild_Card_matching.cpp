#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        int sIdx = 0, pIdx = 0;
        int lastStarIdx = -1;
        int sTmpIdx = -1;

        while (sIdx < sLen) {
            // Case 1: Match found (direct char match or '?')
            if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            }
            // Case 2: Wildcard '*' found. Record position for potential backtracking.
            else if (pIdx < pLen && p[pIdx] == '*') {
                lastStarIdx = pIdx;
                sTmpIdx = sIdx;
                pIdx++; 
            }
            // Case 3: Current match failed, but we have a '*' to fall back on.
            // Move the string pointer forward and restart pattern from after the '*'.
            else if (lastStarIdx != -1) {
                pIdx = lastStarIdx + 1;
                sTmpIdx++;
                sIdx = sTmpIdx;
            }
            // Case 4: No match and no wildcard available.
            else {
                return false;
            }
        }

        // Handle trailing stars in the pattern (they match empty sequences)
        while (pIdx < pLen && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == pLen;
    }
};

int main() {
    Solution sol;
    
    // Test cases: {String, Pattern, Expected Result}
    struct TestCase {
        string s;
        string p;
        bool expected;
    };

    vector<TestCase> tests = {
        {"aa", "a", false},
        {"aa", "*", true},
        {"cb", "?a", false},
        {"adceb", "*a*b", true},
        {"acdcb", "a*c?b", false},
        {"", "*****", true},
        {"mississippi", "m??*ss*?i*pi", true}
    };

    cout << "--- Wildcard Matching Test Results ---" << endl;
    for (const auto& test : tests) {
        bool result = sol.isMatch(test.s, test.p);
        cout << "String: \"" << test.s << "\" | Pattern: \"" << test.p << "\" -> " 
             << (result ? "MATCH" : "NO MATCH") 
             << (result == test.expected ? " [PASS]" : " [FAIL]") << endl;
    }

    return 0;
}