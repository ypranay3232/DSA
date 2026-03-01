// Leetcode Medium
// given n pairs of parentheses, so write a function that generates all possible combinations of well formed parentheses.

// points to consider : dont add more opening braces '(' than N, and dont add more closing braces ')' than opening one (invalid)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// this generates valid parenthesis : result str, current str, no of '(' used, no of ')' used and total no of pairs required.
void generate(vector<string>& result, string current,int openused, int closedused,int n){
    // base case : stopping case if current string length exceeds 2*n (because we consider '(' ')' braces)
    if(current.length() == 2 * n){
        result.push_back(current);//push current str into result
        return;
    }

    // add opening Brace : if '(' is less than n (not used)
    if(openused<n){
        // make a recursive call 
        generate(result,current + '(',openused+1,closedused,n);
    }

    // now add closing brace ')'
    if(closedused < openused){
        generate(result,current + ')', openused, closedused+1,n);
    } 
}

vector<string> generateParenthesis(int n){
    vector<string> result;

    // recursive call 
    generate(result,"",0,0,n);

    return result;
}


int main()
{
    int n = 3; // this generates set of 3 parentheses (, ((, {((, (((),((()),((()))
    vector<string> result = generateParenthesis(n);

    for (string s : result)
    {
        cout
            << s << endl;
    }
    return 0;
}