#include <iostream>
#include <string>
using namespace std;
// given a string representing roman numbers convert them to numbers
// NOTE: if a input contains non roman number such as (L or A or B etc) get their symbolic representation of a number
// mostly the roman numbers follow addition (written from largest to smallest :XII)

// But subtraction occurs when a smallest number occurs before largest ex: (IV) unlike (XII)

// // create a map to store the pairs
// unordered_map<char, int> map = {
//     {'I', 1}, {'V', 5}, {'X', 10},
//     {'L', 50}, {'C', 100},
//     {'D', 500}, {'M', 1000}
// };
// int result =0;
// // now loop the string
// for(int i =0;i<s.length();i++){
//     // we check the condition:  if the current number is smaller than next one we should subtract else we add them
//     if(i+1<s.length() && map[s[i]] < map[s[i+1]]){
//         result -= map[s[i]];
//     }
//     else{
//         result += map[s[i]];
//     }
// }
// return result;

// instead of map we create a function that has the number (only for this leetcode problem)
// this is not efficient but like a temp fix as adding all if()
int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
    return -1;
}

int romanToInt(string &s)
{
    // store the result
    int res = 0;

    // now loop the string
    for (int i = 0; i < s.length(); i++)
    {

        // now get value of current roman number
        int s1 = value(s[i]);

        // after getting this compare it with next symbol if it exists
        if (i + 1 < s.length())
        {
            int s2 = value(s[i + 1]);

            // if current value is greater or equal add it to result
            if (s1 >= s2)
            {
                res += s1;
            }
            else
            {
                // else, add the difference and skip to next symbol
                res += (s2 - s1);
                i++;
            }
        }
        else
        {
            res += s1;
        }
    }

    return res;
}
int main(){
    string s = "LVIII";//L = 50 , V = 5, I = 1(1*3) = 58
    cout<<"Roman to string is : "<<romanToInt(s)<<endl;
    return 0;
}