/*
658. Find K Closest Elements
Medium

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b


Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3

Output: [1,2,3,4]

Example 2:

Input: arr = [1,1,2,3,4,5], k = 4, x = -1

Output: [1,1,2,3]



Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104


algotithm works as :
[1,2,3,4,5] k = 4, x = 3 now find the difference
array = [1,2,3,4,5] if we take difference (3-1=2,3-2=1,3-3=0,3-4 = 1(take absolute value and ignore -ve), 3-5 = 2)

so we got array as [1,2,0,1,2]
array = [1,2,3,4,5]
         2 1 0 1 2
so the array values and difference pair values are (1,2)(2,1)(3,0)(4,1)(5,2)
so now sort these using sort method : to get in ascending order

(0,3)(1,2)(1,4)(2,1)(2,5)
the array is now as : [3,2,4,1,5]

so k = 4 so take first 4 elements
[3,2,4,1]

and sort it : (1,2,3,4)

*/

// 1) Brute force approach using sort()
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findclose_ele(vector<int> &arr, int k, int x)
{
    // first create a pair list to store both values (difference and array value)

    vector<pair<int, int>> difflist;
    // now compute array - x (find difference between both array values - x and return absolute values)
    for (int i = 0; i < arr.size(); i++)
    {
        int diff = abs(arr[i] - x);         // array current element - x
        difflist.push_back({diff, arr[i]}); // now push the difference value with array's current index
    }
    // now sort the array so we get : (0,3)(1,2)(1,4)(2,1)(2,5) so : array is [3,2,4,1,5]
    sort(difflist.begin(), difflist.end());

    // difflist is a pair so it contains first and second values our second value is 3, 2nd is 0. so iterate second values with and store them in result

    vector<int> result;

    for (int i = 0; i < k; i++)
    {
        int val = difflist[i].second;
        result.push_back(val);
        // we get the array as : [3,2,4,1] upto k size
    }
    // now sort it to
    sort(result.begin(), result.end());

    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    vector<int> result = findclose_ele(arr, k, x);
    cout << "The closest elements are : " << endl;

    for (int val : result)
    {
        cout << val << " ";
    }
    cout<<endl;



    return 0;
}
