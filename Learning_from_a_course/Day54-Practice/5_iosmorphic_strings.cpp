/*
205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.



Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:
The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true



Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.


*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;


bool isIsomorphic(string s, string t)
{
    // Given two strings s and t and are said to be isomorphic if there exist a one to one mapping between their characters. means each character in s must map to t, no two characters can map to the same character.

    // in question given that t.length == s.length so no need to check
    // create two arrays to store the s and t last seen characters.
    int arr_S[256] = {0};
    int arr_T[256] = {0};

    // now loop the s
    for (int i = 0; i < s.length(); i++)
    {
        // now check if s[i] seen at same position t[i], but at starting t[i] is new so update its first Position to seen.
        if (arr_S[(int)s[i]] != arr_T[(int)t[i]])
        {
            return false;
        }
        arr_S[(int)s[i]] = i + 1;
        arr_T[(int)t[i]] = i + 1;
    }
    return true;
}
int main(){
    string s = "egg";
    string t = "add";

    cout<<" Given Strings are : "<<endl;
    cout<<s<<" "<<t<<endl;
    cout<<(isIsomorphic(s,t) ? "true" : "false")<<endl;
    return 0;

}