/*
To find the factorial we do as : 5 ! = 1*2*3*4*5 = 120;
THis arises a problem, is the storage 5 factorial = 120; -> 2^32 which can be stored in INT, but the factorial of 50,100 is so big that we cant store it in INT.

SO we use a array to store the values and we represent the first digit in it. Because if a number goes out of range in int then the values are not stored !


EX: Add two numbers represented by two arrays . (if both numbers are represented in arrays how to sum them)
--> example values :
Arr1 = [9,5,4,9]
arr2 = [2,1,4]

we sue two pointers(i,j) both point to arr1,2, then we sum last digits of i,j(9+4) = 13. so we store (3) here and (1) as carry

we do it as :
carry =0;
int x = a[i]+b[j]+carry;//9+4 = 13
int digit = x%10;//13 % 10 = 3, we take digit as 3 and store 1 as carry
carry = x/10;//13/10 = 1.
i--, j--; //so both can decrement and go to next index.

at last we will be having only (9) so we take (j) as 0, so 9+0 =9, and we will have a carry we place it after the 9.

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string calculate_sum(int *a, int n, int *b, int m)
{
    int carry = 0;
    string ans;
    // To initalise the (first array) we use n-1 so we can start from end.
    int i = n - 1;
    int j = m - 1;

    while (i >= 0 && j >= 0)
    {
        int x = a[i] + b[j] + carry;
        int digit = x % 10;
        ans.push_back(char(digit + '0')); // because digit is int and answer is string so we convert it to string by using (digit + '0')
        carry = x / 10;
        i--, j--; // to traverse to next digit
    }
    // if i > 0, (.i.e. we have a element at i but not at j)so we assume b as 0.
    while (i >= 0)
    {
        int x = a[i] + 0 + carry;
        int digit = x % 10;
        ans.push_back(char(digit + '0')); // because digit is int and answer is string so we convert it to string by using (digit + '0')
        carry = x / 10;
        i--, j--; // to traverse to next digit
    }
    // if j > 0, (.i.e. we have elements at j but not at i)so we assume a as 0.
    while (j >= 0)
    {
        int x = 0 + b[j] + carry;
        int digit = x % 10;
        ans.push_back(char(digit + '0')); // because digit is int and answer is string so we convert it to string by using (digit + '0')
        carry = x / 10;
        i--, j--; // to traverse to next digit
    }
    if (carry)
    {
        ans.push_back(char(carry + '0'));
    }

    // We get zero at end : so to remove we do as : we revrse the number
    reverse(ans.begin(), ans.end());

    // Remove leading zeros (if any). Preserve single "0" if the result is zero.
    size_t first_non_zero = ans.find_first_not_of('0');
    if (first_non_zero == string::npos)
    {
        // result is all zeros -> number is 0
        return "0";
    }
    // otherwise return substring from first non-zero to end
    return ans.substr(first_non_zero);
}
// first create a function !

int main()
{
    vector<int> arr1 = {9, 5, 4, 9};
    vector<int> arr2 = {2, 1, 4};

    string result1 = calculate_sum(arr1.data(), (int)arr1.size(), arr2.data(), (int)arr2.size());
    cout << "9549 + 214 = " << result1 << "\n";

    // Example 2: adding numbers that cause carry propagation
    vector<int> x = {9, 9, 9};
    vector<int> y = {1};
    string result2 = calculate_sum(x.data(), (int)x.size(), y.data(), (int)y.size());
    cout << "999 + 1 = " << result2 << "\n"; // expected: 1000
}