/*
917 : Reverse Only Letters
Given a string s,reverse the string according to the following :
-->The characters which are not english letters remain in same position
-->The english letters should be reversed

-->return S, after reversing !

ex:
Example 1:

Input: s = "ab-cd"
Output: "dc-ba"
Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"


Constraints:

1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'.


ex: this is a two pointer approach, we have to swap the characters from both ends at same time
if we encounter a non alphabet we ignore it,

Start: [a] b - c [d],  "Left is 'a', Right is 'd'. Both are letters. Swap them."
Move: d [b] - [c] a,   "Left moves to position 'b', Right moves to 'c'. Both are letters. Swap them"
Next: d c [-] a,       "Both pointers move to '-'. Since it's not a letter, they pass it."
Result: dc-ba,The pointers have crossed. We're done!
*/

#include <iostream>
#include <string>
using namespace std;

string reverseOnlyLetters(string s)
{
    // given a string contains english and non english characters, reverse only english alphabets ignore non english alphabets.
    // This is a two pointer approach : this is a two pointer approach, we have to swap the characters from both ends at same time, if we encounter a non alphabet we ignore it

    // Approach is too simple, create two pointers
    int left = 0;
    int right = s.length() - 1;

    // now loop the string til left < right now check if left is a alphabet or not.
    while (left < right)
    {
        // now check if left is an alphabet, we use a isalpha() that checks if current element is alphabet or not. if yes (not an alphabet we skip it)
        if (!isalpha(s[left]))
        {
            left++;
        }
        else if (!isalpha(s[right]))
        {
            right--;
        } // now if both are letters swap them
        else
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    // now return the string
    return s;
}
int main()
{
    string test1 = "ab-cd";
    string test2 = "a-bC-dEf-ghIj";
    string test3 = "Test1ng-Leet=code-Q!";

    cout << "Test 1: " << reverseOnlyLetters(test1) << endl;
    cout << "Test 2: " << reverseOnlyLetters(test2) << endl;
    cout << "Test 3: " << reverseOnlyLetters(test3) << endl;

    return 0;
}