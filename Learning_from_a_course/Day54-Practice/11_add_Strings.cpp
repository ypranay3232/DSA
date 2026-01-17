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
int main(){
    cout<<addStrings("11","123")<<endl;
    cout <<addStrings("456", "77") << endl;
    return 0;
}