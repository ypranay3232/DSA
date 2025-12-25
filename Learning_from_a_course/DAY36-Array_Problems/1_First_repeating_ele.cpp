/*
A question from GFG :
Given an array arr[], find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.

(.i.e. return the first repeating element from an array so considering the below ex: we should return its index (1), because it repeat first. And from below ex: we can understand that the array indexing starts from 1, because the index of 5 is mentioned as 2. )

Note:- The position you return should be according to 1-based indexing.

Examples:

Input: arr[] = [1, 5, 3, 4, 3, 5, 6]
Output: 2
Explanation: 5 appears twice and its first appearance is at index 2 which is less than 3 whose first the occurring index is 3.
Input: arr[] = [1, 2, 3, 4]
Output: -1
Explanation: All elements appear only once so answer is -1.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106

Expected Complexities
Company Tags
Amazon Oracle


Approaches : 1) To use a loop and check array's current index with every other element (i == i+1) if true then we return current value of (i). time : O(n^2) because we use two loops space : O(1)

2) To store the array values in a hashtable and check if array value of 1, is repeating no, what about 5 yes its repeating twice because its value is 2, so we return it, ex:

values and no of times they repeated
1 ->1
5 ->2
3 ->2
4 ->1
6 ->1

first we traverse through the loop and store values in hashtable, then we iterate and check if current element has any future occurrence ? if yes that value is first repeating element.

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

int first_repeating_sol(const int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        // now we find the repeated element !
        // another loop that runs from i + 1 so our array index will be i+1. so that we can check array elements with next index.
        for (int j = i + 1; j < n; ++j)
        {
            // now check condition if a[i] == a[j] if yes make isrepeated = true;
            if (arr[i] == arr[j])
            {
                return i + 1; // because we need first occurrence of a repeating element.
            }
        }
    }
    return -1; // if not found any repeating element return false.
}

// Approach 2:

int first_repeating_ele(const int arr[], int n) // here the function header receives a pointer to an array
{
    // first we check if the array is empty ? if array is empty there is nothing to check and return -1.
    if (n <= 0)
        return -1;
    unordered_map<int, int> first_index; // declared a map(hashtable) named first_index --> contains        two int because it has key and value, and key = value from array and value = its first index(0 based)
    first_index.reserve(min(n, 100000)); // It reserves internal space for map to reduce rehashing
    int best = INT_MAX;                  // the best variable holds the smallest value of all repeating elements so we can get which element repeated first.

    // now we start looping the array from left to right from index 0.
    for (int i = 0; i < n; ++i)
    {
        int v = arr[i];                // Int v is current value of i
        auto it = first_index.find(v); // auto it variable points to first_index value an checks if v is already repeated, if exist then (it) points to that if not then (it) equals to first_index

        // now check condition as if the array current value (v) is repeated or not
        if (it == first_index.end())
        {
            // if not repeated then store it in map
            first_index[v] = i; // record the first occurrence
        }
        else
        {
            // if value is already in map so repeated store it in best
            best = min(best, it->second); // it ->second stores first index for v.
        }
    }
    // if best is not updated, no repeats found return -1.
    if (best == INT_MAX)
    {
        return -1;
    }
    else
    {
        return best + 1; // convert the index to 1 based index
    }
}

int main()
{
    vector<int> vec = {1, 5, 3, 4, 3, 5, 6};
    int n = static_cast<int>(vec.size());
    const int *arr = vec.data();
    cout << "The repeating element is : " << first_repeating_sol(arr, n) << endl;
    cout << "Optimized approach : " << first_repeating_ele(arr, n) << " \n";

    return 0;
}