#include <iostream>
#include <string>

using namespace std;

// Recursive function to check palindrome
bool isPalindrome(string str, int start, int end) {
    // Base Case: If indices meet or cross, we've checked everything
    if (start >= end) {
        return true;
    }

    // Check if characters at the current bounds match
    if (str[start] != str[end]) {
        return false;
    }

    // Move inward: increment start and decrement end
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isPalindrome(input, 0, input.length() - 1)) {
        cout << "\"" << input << "\" is a palindrome!" << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}