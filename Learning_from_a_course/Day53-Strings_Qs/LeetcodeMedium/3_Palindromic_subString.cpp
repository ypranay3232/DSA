#include <iostream>
#include <string>
using namespace std;

/*
647. Palindromic Substrings
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/
int expandAroundCenter(string &s, int left, int right)
{
    int count = 0;
    // expand as long as left and right are within range/bounds
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        count++;
        left--;
        right++;
    }
    return count;
}

int countSubstrings(string s)
{
    // given a string you have to count how may substring of palindromes exist
    /*  ex: aaa == 'a' 'a' 'a' 'aa'(0,1 index) 'aa' (1,2) 'aaa' (0-2)

    NOTE : instead of checking every substring we do this : each palindrome starts from center
    and there are two types of palindromes odd and even length palindrome

    odd palindromes has a center ex: odd= 3 so (abc) b  is the center
    Even palindromes have 2 centers ex: even = 4 (abbc) so bb is center

    so if given : (aaa) it has both types of palindromes even, odd ==> a,a,a = odd, but 'aa' even
    so inside a palindrome we have two types of palindromes even,odd
    */

    // first check the length of string and initialize a counter
    int n = s.length();
    int count = 0;

    // now loop the characters
    for (int i = 0; i < n; i++)
    {
        // we assume that every index can be centered
        count += expandAroundCenter(s, i, i);     // odd palindromes
        count += expandAroundCenter(s, i, i + 1); // even palindromes
    }
    return count;
}


int main(){
    system("cls");  //clears terminal what i prefer for each execution 
    string s = "aaa";
    int result = countSubstrings(s);
    cout<<"Total palindromic substrings are : "<<result<<endl;
    return 0;
}