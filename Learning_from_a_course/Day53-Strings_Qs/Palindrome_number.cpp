#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
    // 1. Check if x < 0 (negative numbers are not palindromes)
    // Example: -121 reversed is 121-, so it's not the same.
    if (x < 0)
    {
        return false;
    }

    // 2. Store the original value to compare later
    // We need this because we are going to "destroy" x in the loop.
    int original = x;

    // 3. Use 'long long' to prevent overflow
    // If x is 1,234,567,899, reversing it would break a regular 'int'.
    long long reversed = 0;

    // 4. Now reverse the number digit by digit
    // We keep going until x is empty (0).
    while (x > 0)
    {
        // Get the last digit
        // Example: 123 % 10 = 3
        int lastDigit = x % 10;

        // Shift and add
        // We multiply 'reversed' by 10 to move the current digits to the left,
        // then we drop the 'lastDigit' into the new empty spot.
        // Example: (0 * 10) + 3 = 3 ... then (3 * 10) + 2 = 32
        reversed = (reversed * 10) + lastDigit;

        // This removes the last digit
        // In C++, integer division (x/10) just cuts off the decimal.
        // Example: 123 / 10 = 12
        x = x / 10;
    }

    // 5. Compare the flipped version with the original
    // If they are identical, it's a palindrome!
    return original == reversed;
}

int main() {
    int myNumber = 121;
    if (isPalindrome(myNumber)) {
        cout << myNumber << " is a palindrome!" << endl;
    } else {
        cout << myNumber << " is NOT a palindrome." << endl;
    }

    return 0;
}