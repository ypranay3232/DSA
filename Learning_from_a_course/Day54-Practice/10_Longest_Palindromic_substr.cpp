#include <iostream>
#include <string>
using namespace std;

// first let's create a helper function that finds the center ?
// if left >= 0 and right < s.length()-1; s[left] == s[right] left ++,-- return right - left -1
int helperPalindrome(string &s, int left, int right)
{
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        left--;
        right++;
    }
    // now return the length of palindrome
    return right - left - 1;
}
string longestPalindrome(string s)
{
    // Given a string return the longest palindromic substring in s. A palindrome reads the same forward and backward.
    // A palindrome is defined by center and left and right characters are matched.
    // for a even palindrome we have two centers
    // For a Odd palindrome has 1 center

    int n = s.length();
    if (n == 0)
        return "";

    // now get the longest and shortest palindrome
    int start = 0;
    int maxlen = 1;

    for (int i = 0; i < n; i++)
    {
        // Case 1 : Assuming that Odd length palindrome (so center at i) (only 1 center)
        int len1 = helperPalindrome(s, i, i);
        // Case 2: Assuming that Even length (two centers i+1)
        int len2 = helperPalindrome(s, i, i + 1);

        // now select the longest palindrome
        int len = max(len1, len2);

        // update the result if no longer palindrome is found
        if (len > maxlen)
        {
            maxlen = len;
            // if no longest palindrome is found then return the starting indexes
            start = i - (len - 1) / 2;
        }
    }
    // now return the longest substring
    return s.substr(start, maxlen);
}
int main()
{
    string s;
    cout << "enter a string" << endl;
    cin >> s;
    // test : babad --> bab
    cout <<longestPalindrome(s);
    return 0;
}