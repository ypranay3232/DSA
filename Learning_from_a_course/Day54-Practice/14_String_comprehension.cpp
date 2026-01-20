#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Note : Read = moves forward and scans the original array 
// write : moves forward and overwrite the compressed data
// n = count of array, currentchar = the characters that are currently appending, count to keep track of repeats
int compress(vector<char> &chars)
{
    // Given a set of characters compress the repeating charcters. if the characters appear once keep them as it is, else if it appears K times: write the character by the digit of k(Its repeating time)

    // Constraints: must modify the same chars array, must use O(1) space, and return the new lenght of compressed array
    // We need one pointer to read the originally characters, and another to update the characters

    int n = chars.size(); // first get the size of chars
    // create two pointers to read and update
    int read = 0;
    int write = 0;

    // now read the characters
    while (read < n)
    {
        // Get the current char and set count = 0, now becomes read = 0, chars[read] = 'a', so current char = 'a'.
        char currentchar = chars[read];
        int count = 0;

        // now count how many times we got 'a', or the number appear then move to next character and keep track of the current readed element and increment the counter.
        while (read < n && chars[read] == currentchar)
        {
            read++;
            count++;
        }

        // now write the charcter into write 
        chars[write] = currentchar;
        write++;

        // if count is > 1 write each digit seperately
        if (count > 1)
        {
            string freq = to_string(count);
            for (char digit : freq)
            {
                chars[write] = digit;
                write++;
            }
        }
    }
    return write; // constraint to not return the string seperately
}

int main(){
    vector<char> chars = {'a','a','b','b','c','c','c'};
    cout<<"Original array is : "<<endl;
    // to print a vector string we have to do this (using short hand for)
    for(const auto& x : chars){
        cout<<x<<" ";
    }
    cout<<endl;
    int newlength = compress(chars);
    cout<<"The Array Compressed to Length : "<<newlength<<endl;
    cout<<"The Compressed array is : ";
    for(int i=0;i<newlength;i++){
        cout<<chars[i]<<" ";
    }
    return 0;


}