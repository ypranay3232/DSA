// given a number n, print all combinations of balanced parentheses of length n.
// A balanced parentheses is only when it have opening ")" and "(" and closing bracket in correct order.

// ex: 2 = ["()"] => only 1 valid sequence can be formed using 1 pair of parentheses.
// c++ program to generate all the combinations of balanced
// parenthesis.

#include <iostream>
#include <vector>
#include <string> // Good practice to include this
using namespace std;

void validParentheses(int n, int open, string curr, vector<string> &res) {
    if (curr.length() == 2 * n) {
        res.push_back(curr);
        return;
    }

    if (open < n)
        validParentheses(n, open + 1, curr + '(', res);

    // Number of closed brackets = (total length - open brackets)
    if (curr.length() - open < open)
        validParentheses(n, open, curr + ')', res);
}

vector<string> generateParentheses(int n) {
    vector<string> res;
    // Assuming n is the number of pairs (e.g., n=2 results in length 4)
    validParentheses(n, 0, "", res);
    return res;
}

int main() {
    int n = 3; // This will generate all 3-pair combinations
    vector<string> res = generateParentheses(n);

    for (const string &seq : res) {
        cout << seq << endl;
    }

    return 0;
}