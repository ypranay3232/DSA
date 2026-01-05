/*
Leetcode : 1910. Remove All Occurrences of a Substring
You are given:

A string s

A string part

Your task is to remove all occurrences of part from s and return the final string.
Logic : 
Search for part inside s

If found, remove it

Repeat until part no longer exists in s

Return the modified string

*/

#include<iostream>
#include<string>
using namespace std;

string removeOccurrences(string s, string part)
{
    // you are given two strings 's', 'Part' and you have to remove 'part' string from 's'
    //  and return the 's'

    // first find the position of of 'part' in 's' so we use find() to get index, if index does not exist then we get npos (no position), where the part string exist inside 's' so we can remove its all occurrences .
    int pos = s.find(part);
    while (pos != string::npos)
    {
        // we search in string 's' until we get npos error
        // if we get valid position we have to erase them
        s.erase(pos, part.length());
        pos = s.find(part);
    }
    return s;
}

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";

    string result = removeOccurrences(s,part);
    cout<<"The string after removal : "<<result<<endl;
    return 0;
}