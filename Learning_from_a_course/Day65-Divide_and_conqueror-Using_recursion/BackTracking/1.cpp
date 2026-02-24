// Back tracking is another variant of Recursion thats it, but here we explore all  possibilities of a solution. And once a possibility is discarded if not found we wont include it again

// ex: A,B,C are 3 boxes one of it contains a gold coin, so we check box A if now found we discard it. we check B if found we wont check next box.

// FAQ : Rat in a maze

// ex: permutation of strings : ex: given a string "abc", the all possible permutations of "abc" are
// abc,bac,bca,cab,cba,acb

// we follow this approach : abc we take a pointer (i) which represents a position and points to "a" and we use a loop to traverse thought abc.
// case 1 : a gets swapped with itself (so : abc) and when i="B" j = "b" we get "abc" and when we have "i="b n j="c" we get "acb"  .now i = "a" j = "b" now both gets swapped (bac),do j++, so j ="c" and i ="a" so swap : "bca" now i ="a" j = "c" both gets swapped : (cba) now j++ so j = "a" i ="b" : "cab"
#include <iostream>
#include <string>
using namespace std;
void printpermutation(string &str, int i)
{
    // base case : when array goes out of index
    if (i >= str.length())
    {
        cout << str << " ";
        return;
    }
    // now swapping logic : j starts with i Current index
    for (int j = i; j < str.length(); j++)
    {
        // now swap i with j
        swap(str[i], str[j]);
        // now make the recursive call :
        printpermutation(str, i + 1);
        // till now programs works : but we get duplicate values so we add backtracking
        // backtracking logic : thats it
        swap(str[i], str[j]);
    }
}
int main()
{
    string str = "abc";
    int i = 0;
    printpermutation(str, i);
    return 0;
}