/*
Exponential Search : works on Sorted array

Consider an example :

Array = 3,4,5,6,11,13,14,15,56,70
Index   0,1,2,3,4, 5, 6, 7, 8, 9

Find Element x = 13
Now what we can do is either we can apply a Linear search and search throughout the array one by one
The Time Complexity is : O(N)

To improve the complexity we use the binary search :

first we take the mid element (start+end/2) and we go to middle of the array and now we check if
mid is less or greater if less (move right) else move(left)

We take log(n) time so by using exponential search we improve that time complexity by little

here we jump between two elements, (i.e. i = i*2)


Works as :

// if array index 0 has the x value then no need of checking all other elements
if(arr[0]==x)
return 0;

// now loop through the i until its less than array (n - last index) and current index is < or = x
int i = 1;
while(i<n && a[i]<=x){
    // now jump between indexes
    i = i*2;
}
what it does it : we jump through the index as : 1,2,4,8,16 because 2^0,2^1,2^2,2^3...

ex:
Array = 3,4,5,6,11,13,14,15,56,70
Index   0,1,2,3,4, 5, 6, 7, 8, 9

we search as (i will be at index 1,2,4,8 at 8 stop because x=13 we crossed it)
and we cant do as index 4+1 = index 5 we get (x) Nope we are not applying a linear search here.

because of i=i*2 and now we apply binary search
between (4,8) and we do it as :
we apply a Binarysearch function from algorithms and our current array index is at 8(56) so we
divide it by 2 and the ending element to be passed here is min(i,n-1), x to find

(i.e. starting binarysearch index is at i/2 (8/2 = 4 index), and ending index is upto(i,n-1)because when we search for a large number the next index will be out of array range  so we limit search up to array length)

Binarysearch(a,i/2,min(i,n-1),x)

*/

#include <iostream>
#include <algorithm>
using namespace std;

// now implement a simple binary search.
int bs(int a[], int start, int end, int x)
{
    // while start < = end (array 0 to n)
    while (start <= end)
    {
        // divide mid by index 2 and keep it in canter, and check if mid ==x if yes return
        int mid = (start + end) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        // else if mid ! = x check if it less or greater than mid, if less (left) so move right
        else if (a[mid] < x)
        {
            start = mid + 1;
        }
        else
        {
            // the mid is greater than x we need to decrement it
            end = mid - 1;
        }
    }
    // if we dent get the value we return -1
    return -1;
}

int exponenttialSearch(int a[], int n, int x)
{
    // check condition1 if x is at index 0 return that
    if (a[0] == x)
        return 0;

    // now we initialism i = 1. because each time we iterate (i=i*2 if i =0 we get all 0s)
    int i = 1;
    while (i < n && a[i] <= x)
    {
        i = i * 2;
    }
    return bs(a, i / 2, min(i, n - 1), x);
}

int main()
{
    // step1 create an array
    int a[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int n = sizeof(a) / sizeof(int);
    int x = 13;
    int answer = exponenttialSearch(a,n,x);
    cout << "The answer is : " << answer;
}