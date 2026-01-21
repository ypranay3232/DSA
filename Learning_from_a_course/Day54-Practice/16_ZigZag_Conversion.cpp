/*

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I


1. Problem in Very Simple Terms : You are given A string s

A number numRows

You must:  Write the string in a zigzag pattern across numRows

Then read the characters row by row

Return the final string

This is not about printing the zigzag — it’s about simulating the placement.


2. What Is Actually Happening (Core Intuition)
Key Observation

The zigzag movement follows a repeating pattern:

Go down row by row (P A Y P) first 4 characters are written in column then next char is written in row

Then go up diagonally

Repeat

For numRows = 3:

Row index movement:
0 → 1 → 2 → 1 → 0 → 1 → 2 ...


For numRows = 4:

0 → 1 → 2 → 3 → 2 → 1 → 0 → 1 ...

like this :
 P     I    N
A   L S  I G
Y A   H R
P     I


1. First: What zigzag ACTUALLY looks like (mentally)

Take this example:
s = "PAYPALISHIRING"
numRows = 4

When written in zigzag, the characters go like this:

Row 0: P     I     N
Row 1: A   L S   I G
Row 2: Y A   H R
Row 3: P     I


Important:
Characters are placed in two kinds of moves:
Straight down (vertical)

Slanted up (diagonal)

2. What are “vertical” characters?

Vertical characters are placed when we are moving straight down.

Example (first column):

P   ← row 0
A   ← row 1
Y   ← row 2
P   ← row 3
(result.push_back(s[j]); )

3. What are “diagonal” characters? 

After reaching the bottom row, we do NOT go straight up.

Instead, we go up diagonally:

    L   ← row 1
   A     ← row 2

These are diagonal characters.

They: Appear between vertical columns and Exist only in middle rows

Do NOT exist in first and last rows

*/


#include <iostream>
#include <string>
using namespace std;

string convert(string s, int numRows)
{
    // given a string and numrows, write the string in zigzag pattern across numrows

    // check if there is only 1 row then zigzag cant be possible
    if (numRows == 1)
        return s;
    // create a string to store result
    string result;
    // get the length of string s
    int n = s.length();

    // now to print the pattern we do as :
    int pattern = 2 * (numRows - 1); // ex : (2 * ( 4-1) = 6) so 3 characters up and 3 down

    // now loop the numRows
    for (int i = 0; i < numRows; i++)
    {
        for (int j = i; j < n; j += pattern)
        {
            // adding vertical characters
            result.push_back(s[j]);

            // diagonal character
            int diagonalchar = j + pattern - 2 * i;

            // Add diagonal character only for middle rows : if i !=  0 == don't add diagonal to first row, then (row != numRows - 1) == dont add diagonal chars for last row
            if (i != 0 && i != numRows - 1 && diagonalchar < n)
            {
                result.push_back(s[diagonalchar]);
            }
        }
    }
    return result;
}

int main(){
    string s = "PAYPALISHIRING";
    int numRows = 4;

    string result = convert(s,numRows);
    cout<<result<<endl;
}