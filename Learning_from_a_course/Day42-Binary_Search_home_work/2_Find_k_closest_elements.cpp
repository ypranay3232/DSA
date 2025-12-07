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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1) Brute force approach using sort(). Time complexity O(n log n)
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

// 2) two pointer approach : O(n)
/* works as : contains a window (right - left) that covers array,
s1 : start array with left =0, right = n-1,
while window size > k
compare (left or right) which is far from "X".... if left is far move left++, else move right --

by doing so window size becomes "K".. the subarray left,right is our answer
*/

vector<int> TwoPointer_approach(vector<int>&arr, int k, int x){
    // creating total size of elements and left and right pointer
    int n = arr.size();
    int left =0;
    int right = n-1;

    // now reduce the overall window size to k so..
    //  ex: array is [1,2,3,4,5] so right = n-1 (4) and left = 0 so : 
    // 4 - 0 + 1 = 5 >k (window size) But k = 4 so we need only 4 elements
    while(right - left + 1 > k){

        // our x = 3, k = 4
        // now get diff arrays for each array index (left = 1 - 3 = 2) so left[0] = 2
        int differenceleft = abs(arr[left] -x);
        int differenceright = abs(arr[right] -x);


        if(differenceleft > differenceright){
            // if left diff values are greater than right : 2 > 2 nope !
            left ++; 
        }
        else{
            right --; //drop right side element
        }
    }

    // now window size is exactly k, so return the sub array, by creating a var result and loop from left to right and push each index into result
    vector<int> result;
    for(int i = left; i<=right; i++){
        result.push_back(arr[i]);
    }
    return result;

}

// 3) Binary search approach : Optimal solution because O(log n + k)
vector<int> Binartsearch(vector<int>&arr, int k, int x){
    int left = 0;
    int right = arr.size()-k;

    while(left<right){
        int mid = left + (right - left)/2;

        // array = {1,2,3,4,5} and x = 3, k = 4 so : diffleft = 3-3 = 0
        int diffleft = x-arr[mid];
        int diffright = arr[mid+k]-x;//right is 3 + 4 - 3 = 4. we got window size

        // now check if distance of left is > right then move it to right 
        if(diffleft>diffright){
            left = mid + 1;
        }else{
            // if no diffleft < right then assign right value to mid; (i.e mid = 4)
            right = mid;
        }
    }
    // since left holds the starting we take it and we iterate it from left to left + k (0+4)
    vector<int> result;
    for(int i = left;i<left+k;i++){
        // now push back the iterated values (i.e array values to result)
        result.push_back(arr[i]);
    }
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

    vector<int> twoptr = TwoPointer_approach(arr,k,x);
    cout<<"The closest elements are : "<<endl;
    for(int val : twoptr){
        cout<<val<<" ";
    }
    cout<<endl;

    vector<int> bs = Binartsearch(arr,k,x);
    cout<<"The closest elements are : "<<endl;
    for(int val : bs){
        cout<<val<<" ";
    }
    return 0;
}
