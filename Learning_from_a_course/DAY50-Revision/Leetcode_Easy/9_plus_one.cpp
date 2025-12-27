#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    // This problem is very easy : Assume array is = [1,2,3] no we need to add +1 to last element
    // but if the array last element is 9 = {1,2,9} by adding 1 = becomes 10 and we cant store 10 double digit number in a single digit/integer array. so we add (10) = o to 9 and, 1 to element before 9

    // what is we have all 9's {9,9,9} = then we extend array as = {1,0,0,0}

    // first loop through the array, initialize i to last element of array, and check if its >=0, and decrement the array (right to left)
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        // check if last digit is 9, by adding +1 leads to 10, so store 0 inplace of 9 and +1 with before element
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            // else if digits ! = 9 then no worries just add +1 and return
            digits[i]++;
            return digits;
        }
    }
    // Handling special case : if all {999} then we have to insert (1) at beginning
    digits.insert(digits.begin(), 1);
    return digits;
}

int main(){
    vector<int> digits = {1,2,3};
    // vector<int> digits = {1,2,9};
    // vector<int> digits = {9,9,9};
    vector<int> result = plusOne(digits);
    for(int x : result){
        cout<<x<<" ";
    }
}