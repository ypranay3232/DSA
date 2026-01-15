/*
1768. Merge Strings Alternately

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.



Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d


Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*/

#include <iostream>
#include <string>
using namespace std;

string mergeAlternately(string word1, string word2)
{
    // given two strings merge first character and then merege first character of another string but when a string has more characters than other then we append the remaining chars to end

    // first get length of both strings and use a result string
    int s1 = word1.length();
    int s2 = word2.length();
    string result = "";

    // now allocate some memory for both strings to avoid reallocations
    result.reserve(s1 + s2);

    // now loop the string characteres and store the string to result and increment to move to next index
    int i = 0;
    while (i < s1 && i < s2)
    {
        result.push_back(word1[i]);
        result.push_back(word2[i]);
        i++;
    }

    // condition if any string contains substring after adding to result (substr) append it
    if (i < s1)
    {
        result.append(word1.substr(i));
    }
    if (i < s2)
    {
        result.append(word2.substr(i));
    }
    return result;
}

int main(){
    string word1 = "abc";
    string word2 = "pqrst";

    string merge = mergeAlternately(word1,word2);
    cout<<"merged string : "<<merge<<endl;
    return 0;
}