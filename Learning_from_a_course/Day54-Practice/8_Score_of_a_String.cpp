/*
Given a string s. The score of the string is defined as the sum of absolute difference between
ascii values.

ex: hello
output = 13
explanation : h ascii value = 104
e ascii value = 101 ......
now ascii value is (|104 - 101| + .....) total = 13
*/

#include <iostream>
#include <string>
#include<math.h>
using namespace std;

int scoreOfString(string s)
{
    // Given a string calculate the absolute difference between ascii values

    // first create a var to store ans then loop the string
    int ans = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        // now add the current ascii value with next
        ans += abs(s[i] - s[i + 1]);
    }
    return ans;
}

int main(){
    string s = "hello";
    int result = scoreOfString(s);
    cout<<"The score of "<<s<<" is : "<<result<<endl;
    return 0;
}