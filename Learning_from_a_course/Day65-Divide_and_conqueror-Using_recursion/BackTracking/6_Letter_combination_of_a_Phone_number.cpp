// // given a string input n  it can contain  empty string or   1-9 digits, return all possible letter combinations.

// /*
// Given :
// 2 = 'abc'
// 3 = 'def'
// 4 = 'ghi'
// 5 = 'jkl'
// 6 = 'mno'
// 7 = 'pqrs'
// 8 = 'tuv'
// 9 = 'wxyz'

// we can either map these into an array or create a map both has O(1).

// ex: if input is : 23
// first we point to '2' so we can have (a,b,c) as output and now we point to '3' so
//                          2          3
//                     a   b       c           (2)
//                 d e f   d e f   d e f       (3)
// */

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// void solve(vector<string> &ans, int index, string output, string digits, vector<string> &mapping)
// {
//     // Base case :
//     if (index >= digits.length())
//     {
//         ans.push_back(output);
//         return;
//     }

//     // recursion case :
//     int digit = digits[index] - '0'; // to get a integer and conver it from character to integer
//     string value = mapping[digit];
//     for (int i = 0; i < value.length(); i++)
//     {
//         char ch = value[i];
//         output.push_back(ch);
//         solve(ans, index + 1, output, digits, mapping);
//         // backtrack
//         output.pop_back();
//     }
// }

// vector<string> letterCombinations(string digits)
// {
//     vector<string> ans;
//     if (digits.length() == 0)
//         return ans;

//     int index = 0;
//     string output = "";
//     vector<string> mapping(10);
//     mapping[2] = "abc";
//     mapping[3] = "def";
//     mapping[4] = "ghi";
//     mapping[5] = "jkl";
//     mapping[6] = "mno";
//     mapping[7] = "pqrs";
//     mapping[8] = "tuv";
//     mapping[9] = "wxyz";

//     // recursive call :
//     solve(ans, index, output, digits, mapping);

//     return ans;
// }

// int main(){
//     string input;
//     cout<<"Enter the digits : "<<endl;
//     cin>>input;

//     vector<string> results = letterCombinations(input);
//     cout<<"The possible combinations of the entered input "<<input<<endl;
//     for(const string& s : results){
//         cout<<s<<endl;
//     }
//     cout<<endl;

//     return 0;
// }

// optimised sol using backtracking :
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Backtracking function : pass all by const reference 
void solve(int index,
           const string &digits,          
           string &current,               
           const vector<string> &mapping, 
           vector<string> &result)
{
    // Base case: if we've processed all digits we we return result 
    if (index == digits.length())
    {
        result.push_back(current);
        return;
    }

    // Convert char digit to integer index
    int digit = digits[index] - '0';

    // Get corresponding letters
    const string &letters = mapping[digit];

    // Try each possible letter
    for (char ch : letters)
    {
        current.push_back(ch);                     
        //Back tracking logic :  Choose, explore, backtrack 
        solve(index + 1, digits, current, mapping, result); 
        current.pop_back();                                 
    }
}
vector<string> letterCombinations(string digits)
{

    vector<string> result;

    // Edge case: empty input
    if (digits.empty())
        return result;

    // Phone mapping (index = digit)
    const vector<string> mapping = {
        "", "", // 0,1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    string current;
    current.reserve(digits.length()); // Avoid repeated reallocations

    solve(0, digits, current, mapping, result);

    return result;
};

int main()
{
    string input;

    cout << "Enter digits: ";
    cin >> input;

    vector<string> ans = letterCombinations(input);

    cout << "Combinations:\n";
    for (const string &s : ans)
    {
        cout << s << endl;
    }

    return 0;
}