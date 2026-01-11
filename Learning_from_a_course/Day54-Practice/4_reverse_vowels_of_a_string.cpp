#include <iostream>
#include <string>
using namespace std;

string reverseVowels(string s)
{
    // given a string reverse only all vowels (a,e,i,o,u) in string and return. It works as dont touch the non vowels and swap the both vowels from two pointers.
    // first declare two pointers and vowels in a string
    int left = 0;
    int right = s.length() - 1;
    string vowels = "aeiouAEIOU";
    // loop the string from left to right until left<right
    while (left < right)
    {
        // now move the left pointer until we find any vowels.
        while (left < right && vowels.find(s[left]) == string::npos)
        {
            left++;
        }
        // same now move right pointer
        while (left < right && vowels.find(s[right]) == string::npos)
        {
            right--;
        }
        // once vowels are found by the pointers we swap them and move them to next position so we wont stop after swapping one element
        if (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    // return the string
    return s;
}
int main(){
    string s = "IceCreAm";
    cout<<"The result is : "<<reverseVowels(s)<<endl;
}