#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

string addStrings(string num1, string num2)
{
    // Given two integers but represented as strings return the sum of num1,2 as strings
    // NOTE : cant convert strings to integers.
    /*
    Example
    num1 = "456"
    num2 = "77"

    We align from the right:

      4 5 6
    +   7 7
    --------

    Start from the last digit:

    6 + 7 = 13 → write 3, carry 1

    5 + 7 + 1 = 13 → write 3, carry 1

    4 + 0 + 1 = 5 → write 5

    Result (written backwards): "335"
    Reverse it → "533"        */

    // now get the last digit of num1,2, store carry
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string ans = "";
    // while i, j are >=0 or if there is any carry
    while (i >= 0 || j >= 0 || carry)
    {
        // store the carry in sum
        int sum = carry;
        // if i >=0 add sum + num1's next index (by moving it --)
        if (i >= 0)
            sum += num1[i--] - '0';
        if (j >= 0)
            sum += num2[j--] - '0';
        // in answer we convert the string characters to integers )('5' to 5)
        ans += (sum % 10) + '0';
        carry = sum / 10;
    }
    // now reverse the string because we built the answer backwards.
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    cout << "Sum: " << addStrings("456", "77") << endl; // Output: 533
    return 0;
}

/*
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void addRecursive(string& num1, int i, string& num2, int j, int carry, string& ans) {
    // Base Case: If all digits are processed and no carry remains
    if (i < 0 && j < 0 && carry == 0) {
        return;
    }

    int sum = carry;
    if (i >= 0) sum += num1[i--] - '0';
    if (j >= 0) sum += num2[j--] - '0';

    // Recursive Call (move to the next digits on the left)
    addRecursive(num1, i, num2, j, sum / 10, ans);

    // After coming back from recursion, append the current digit
    // This avoids needing to reverse the string later!
    ans += (sum % 10) + '0';
}

string addStrings(string num1, string num2) {
    string ans = "";
    addRecursive(num1, num1.size() - 1, num2, num2.size() - 1, 0, ans);
    return ans.empty() ? "0" : ans;
}

int main() {
    cout << "Sum: " << addStrings("456", "77") << endl; // Output: 533
    return 0;
}
*/