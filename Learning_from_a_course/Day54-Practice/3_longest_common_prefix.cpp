#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    // write a function that checks common prefix (longest) by comparing all strings
    // ex: flower
    //     Flow
    //     Flight
    // The longest prefix is fl because we compare all three string fl matches for all 3 and o does not match with (flight) so we break and that is the longest prefix array of string

    // we use vertical scanning approach to solve this problem instead of checking an entire string we check their each index and if they match we proceed further else stop.

    // first check if the string is empty()
    if (strs.empty())
        return "";

    // now check the first string from strs and check its first character .
    // strs[0] = "flower" --> length () == 5, charc c stores strs[0][i] --> strs[0] = 'f' and [i] is the 'f' from 0th index of strs. both match so store them.
    for (int i = 0; i < strs[0].length(); i++)
    {
        char c = strs[0][i];

        // inner loop to check other words from the strs, and checks if the other words start from same index 'f'. ex: It checks if strs[1][0] (the 'f' in "flow") and strs[2][0] (the 'f' in "flight") match our c ('f').
        for (int j = 0; j < strs.size(); j++)
        {
            // if we reach to end of any words we stop ex: flow has 3 letters but flower has 5, when we compare both we have to stop at index 5 because flow is out of words, and if any words dont match we return the substring til which we matched.
            if (i == strs[j].length() || strs[j][i] != c)
            {
                return strs[0].substr(0, i);
                /*
                ex: strs[j][i] != c
                i = 0: All words have 'f'. Match!
                i = 1: All words have 'l'. Match!
                i = 2:
                strs[0][2] is 'o'
                strs[1][2] is 'o'
                strs[2][2] is 'i'
            Mismatch! The code immediately returns strs[0].substr(0, 2), which is "fl".
*/
            }
        }
    }
    return strs[0];
}

int main()
{
    vector<string> case1 = {"flower", "flow", "flight"};
    vector<string> case2 = {"dog", "racecar", "car"};

    cout << "Longest common prefix is " <<longestCommonPrefix(case1) << endl; 
    cout << "No Longest Common Prefix " <<longestCommonPrefix(case2) << endl; 
    return 0;
}