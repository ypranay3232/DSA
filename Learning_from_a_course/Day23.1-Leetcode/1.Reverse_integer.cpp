/*
let's solve a medium problem on leetcode :

The LeetCode "Reverse Integer" problem (Problem #7) asks you to reverse the digits of a given signed 32-bit integer x. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then you should return 0. The environment is assumed not to allow storing 64-bit integers.

*/

#include <climits>
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int digit = x % 10;   // extracts last digit of input   
            x = x / 10;           //removes the last digit of input 

            // Overflow checks (32-bit signed limits) means if (ans * 10) == 21474383640. so +7 = overflow, so digit must be <=7.
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) return 0;
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8)) return 0;

            ans = ans * 10 + digit;   
        }
        return ans;                  
    }
};

