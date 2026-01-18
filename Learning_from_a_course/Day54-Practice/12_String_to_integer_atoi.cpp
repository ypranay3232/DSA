#include <iostream>
#include <string>
#include<climits>
using namespace std;
int myAtoi(string s)
{
    // convert a string to 32 bit integer, similar to a stl function atoi()
    // return  atoi(s.c_str());

    // But strings are often messy, follow the algorithm : 1)remove white spaces at start
    //  check the number sign + or -
    //  now check the number until you hit a non digit and ignore everything after that
    //  your integer size should be in the 32 bit range

    int i = 0;            // pointer to move through the string
    int sign = 1;         // by default we assume our sign is positive
    long long result = 0; // to store string

    // now loop the string and if current index is space " " ignore it and move forward
    while (i < s.length() && s[i] == ' ')
    {
        i++;
    }
    // now check the sign if it is - then update sign to -1.
    if (i < s.length() && s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-')
        {
            sign = -1;
        }
        i++;
    }
    // now build the number from string, first check if < length and check if the str is a digit
    while (i < s.length() && isdigit(s[i]))
    {
        // now generate the digit. we do it by subtracting current digit with 0.
        // the ascii ex: '5' = 53 and to get number 5 we have to sub with 0, 0 = 48(53 - 48 = 5)
        int digit = s[i] - '0';
        result = (result * 10) + digit;

        // check for overflow
        if (result * sign >= INT_MAX)
            return INT_MAX;
        if (result * sign <= INT_MIN)
            return INT_MIN;
        i++;
    }
    return (int)(result * sign);
}

int main(){
    string s = "1337c0d3";
    cout<<" The string to integer is : "<<myAtoi(s)<<endl;
    return 0;
}