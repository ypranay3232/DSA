#include <iostream>
#include <string>
#include<vector>
using namespace std;

/*
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]


*/

void reverseString(vector<char> &s)
{
    // Its a two pointer approach so create two pointers
    int left = 0;
    int right = s.size() - 1;
    // now loop and check if left < right then swap and loop til left <= right if left > right then we are counting the char again
    while (left < right)
    {
        // swap the left with right and move the pointer
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    cout << "Original String before reversal ";
    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;
    reverseString(s);
    cout << "After reversal string ";
    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}