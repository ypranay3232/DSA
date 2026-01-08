#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isAnagram(string s, string t)
{
    // Given two strings and return true if string t is an anagram of s, Otherwise False
    // An Anagram is a word formed by rearranging the letters of a different word, using the original letters only once

    // first check if the length of both strings are equal if not they are not a valid anagram
    if (s.length() != t.length())
    {
        return false;
    }

    // Brute force : using sort()
    // // now sort both, because two string are anagrams if both have same letters
    // sort(s.begin(),s.end());
    // sort(t.begin(),t.end());

    // // return them after sorting
    // return s==t;

    // Optimised solution
    // first create a frequency array for alphabets (26)
    vector<int> freq(26, 0);

    // now check the characters in string (s) and ch counts how many lowercase letters appear in
    // string s and for string t check in freq array from bottom to top.

    for (char ch : s)
    {
        freq[ch - 'a']++;
    }

    for (char ch : t)
    {
        freq[ch - 'a']--;
    }

    // now check if both string have same frequency for each character, if any one character is
    // differ then we call it a not valid anagram
    for (int count : freq)
    {
        if (count != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "anagram";
    string t = "nagaram";

    if (isAnagram(s, t))
    {
        cout << "String s = " << s << endl;
        cout << "String t " << t << endl;
        cout << "are valid anagrams" << endl;
    }
    else
    {
        cout << "String s = " << s << endl;
        cout << "String t " << t << endl;
        cout << "are not valid anagrams" << endl;
    }

    return 0;
}