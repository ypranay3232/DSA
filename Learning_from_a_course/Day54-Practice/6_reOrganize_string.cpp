/*
You are given a string s.
You must rearrange its characters so that:

No two adjacent characters are the same

If it is not possible, return an empty string ""
===================================================================================================
If any character appears more than (n + 1) / 2 times, it is impossible to separate it with other characters.

The safest way to place the most frequent character is at even indices (0, 2, 4, …) so it never touches itself.

Once the most frequent character is placed, fill remaining characters into the leftover positions.

This avoids the need for a priority queue and runs in O(n) time.

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reorganizeString(string s)
{

    // We need to rearrange the string such that no two adjacent characters are the same
    // If it's impossible to do so, return an empty string ""

    // Get length of string
    int n = s.length();

    // Count frequency of each character (a - z)
    int freq[26] = {0};
    for (char c : s)
    {
        // Map character to index (a -> 0, b -> 1, ...)
        freq[c - 'a']++;
    }

    // Find the character with the maximum frequency
    int max_freq = 0;
    char max_char = 'a';

    for (int i = 0; i < 26; i++)
    {
        // If current character appears more times than previous max
        if (freq[i] > max_freq)
        {
            max_freq = freq[i];
            max_char = 'a' + i;
        }
    }

    // Check if rearrangement is possible
    // If any character appears more than (n + 1) / 2 times,
    // it cannot be rearranged without adjacent duplicates
    if (max_freq > (n + 1) / 2)
    {
        return "";
    }

    // Create result string filled with dummy characters
    string result(n, ' ');

    // Index pointer for placing characters
    int index = 0;

    // Step 6: Place the most frequent character at even indices
    while (freq[max_char - 'a'] > 0)
    {
        result[index] = max_char; // place character
        freq[max_char - 'a']--;   // decrease frequency
        index += 2;               // move to next even index
    }

    // Place remaining characters
    for (int i = 0; i < 26; i++)
    {
        while (freq[i] > 0)
        {

            // If we exceed string length while filling even indices,
            // switch to odd indices
            if (index >= n)
            {
                index = 1;
            }

            result[index] = 'a' + i; // place current character
            freq[i]--;               // reduce frequency
            index += 2;              // move by 2 to avoid adjacency
        }
    }

    // Return the string
    return result;
}
int main(){
    string s = "aab";
    cout<<"Given string is : "<<s<<endl<<"ReOrganized string "<<reorganizeString(s)<<endl;
    return 0;
}