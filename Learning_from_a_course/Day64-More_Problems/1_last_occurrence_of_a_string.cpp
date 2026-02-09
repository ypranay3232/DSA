// given a string : a,b,c,d,d,e,f,d,g --> find the last occurrence of 'd'
//                  0 1 2 3 4 5 6 7 8
// we can say that 'd' last occurrence is at index '7'. So how to find it we have two ways
// 1) start from index 0 and find 'd' and store it til the end of array
// 2) start at the end of string and find the first 'd' and find the index.

// another method we can use strrchr()

#include <iostream>
#include <string>
using namespace std;

// // method1 : searching the string from star: O(n) and O(N)
// void LastOccurrenceOfString(string &s, char target, int &ans, int i = 0)
// {
//     // base case : stop if i > string size.
//     if(i>=s.size()){
//         return;
//     }
//     // condition :
//     if (s[i] == target)
//     {
//         ans = i;
//     }

//     // recursion :
//     LastOccurrenceOfString(s, target, ans, i + 1);
// }

// method2 : searching the string from end, we change the i from 0 to s.size()-1 end : O(n) and O(N)
void LastOccurrenceOfString(string &s, char target, int &ans, int i)
{
    // base case : stop if i > string size.
    if(i<0){
        return;
    }
    // condition :
    if (s[i] == target)
    {
        ans = i;
        return ;//to stop searching once found the target element
    }

    // recursion :
    LastOccurrenceOfString(s, target, ans, i - 1);
}

int main()
{
    cout<<"Enter a string to find : "<<endl;
    string s;
    cin >> s;
    cout<<"Enter the target element to find : "<<endl;
    char target;
    cin >> target;
    int ans = -1;
    // LastOccurrenceOfString(s, target, ans, 0);
    LastOccurrenceOfString(s, target, ans, s.size()-1);
    cout<< ans << endl;
    return 0;
}