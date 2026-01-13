#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    // Map to store sorted_string -> list of original strings
    unordered_map<string, vector<string>> mp;

    for (string s : strs)
    {
        string key = s;               // Take original: "eat"
        sort(key.begin(), key.end()); // Sort it: "aet"
        mp[key].push_back(s);         // mp["aet"] now contains ["eat"]
    }

    vector<vector<string>> ans;
    // Iterate through the map and collect all groups
    for (auto &i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}


int main()
{
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = groupAnagrams(input);
    cout << "[" << endl;
    for (const auto &group : result)
    {
        cout << "  [";
        for (int i = 0; i < group.size(); i++)
        {
            cout << "\"" << group[i] << "\"" << (i == group.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;

    return 0;
}