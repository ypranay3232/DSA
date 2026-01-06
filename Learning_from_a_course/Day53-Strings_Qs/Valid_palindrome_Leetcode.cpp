#include<iostream>
#include<string>
using namespace std;


bool checkPalindrome(string s, int i, int j)
{
    // check if a given string is valid or not ? so loop the string
    while (i <= j)
    {
        // check if i ! = j its not a palindrome return false
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool validPalindrome(string s)
{
    // given a string return true if the string is palindrome after removing an element from it
    // intution : we use two pointer to solve palindrome: check if i == j then its can form a valid palindrome so i++, j--
    // if i != j remove i or j, then its a palindrome

    int i = 0;
    int j = s.length() - 1;

    // now check the condition
    while (i <= j)
    {
        // til i <j if (i ! = j)
        if (s[i] != s[j])
        {
            // we have two possibilities  we get a palindrome if we remove i or by removing j
            // here we create a function checkpalindrome that returns if a given string is palindrome, we use it to check (1) condition if we remove i(so we check from i+1) to j                condition(2) if we remove j (j-1) so we check upto j-1 that's  it.
            return checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j - 1);
        }
        else
        {
            // if i == j we just move forward
            i++;
            j--;
        }
    }
    return true; // palindrome confirmed
}

int main(){
    string s;
    cout<<"Enter string to test"<<endl;
    cin>>s;
    bool result = validPalindrome(s);
    // cout<<result; //this only return 1 or 0, so to make it human readable we use boolalpha it return the 1 and 0 as true and false.
    cout<<boolalpha<<result;

}