// given a string "abc" count the no of subsequences of the string occurrences : a,b,c,ab,ac,ba,bc,ca,cb..

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintSubSequence(string str, string Output, int i)
{
    // base condition : if i> string then we stop
    if (i >= str.length())
    {
        // now print sub sequence
        cout<<Output<<endl;
        return;
    }

    // two recursive calls 1) include 2)exclude 

    // exclude: increment i +1 moving to next case/index
    PrintSubSequence(str,Output,i+1);

    // include : add current character to the output string ! 
    Output.push_back(str[i]);
    PrintSubSequence(str,Output,i+1);
}

int main()
{
    string str = "abc";
    string Output = "";

    int i = 0;
    PrintSubSequence(str, Output, i);
    return 0;
}