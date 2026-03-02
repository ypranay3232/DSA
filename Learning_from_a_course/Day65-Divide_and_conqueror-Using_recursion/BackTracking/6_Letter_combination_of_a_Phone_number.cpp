// given a string input n  it can contain  empty string or   1-9 digits, return all possible letter combinations.

/*
Given :
2 = 'abc'
3 = 'def'
4 = 'ghi'
5 = 'jkl'
6 = 'mno'
7 = 'pqrs'
8 = 'tuv'
9 = 'wxyz'

we can either map these into an array or create a map both has O(1).

ex: if input is : 23
first we point to '2' so we can have (a,b,c) as output and now we point to '3' so
                         2          3
                    a   b       c           (2)
                d e f   d e f   d e f       (3)
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(vector<string> &ans, int index, string output, string digits, vector<string> &mapping)
{
    // Base case :
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    // recursion case :
    int digit = digits[index] - '0'; // to get a integer and conver it from character to integer
    string value = mapping[digit];
    for (int i = 0; i < value.length(); i++)
    {
        char ch = value[i];
        output.push_back(ch);
        solve(ans, index + 1, output, digits, mapping);
        // backtrack
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.length() == 0)
        return ans;

    int index = 0;
    string output = "";
    vector<string> mapping(10);
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    // recursive call :
    solve(ans, index, output, digits, mapping);

    return ans;
}

int main(){
    string input;
    cout<<"Enter the digits : "<<endl;
    cin>>input;

    vector<string> results = letterCombinations(input);
    cout<<"The possible combinations of the entered input "<<input<<endl;
    for(const string& s : results){
        cout<<s<<endl;
    }
    cout<<endl;

    return 0;
}