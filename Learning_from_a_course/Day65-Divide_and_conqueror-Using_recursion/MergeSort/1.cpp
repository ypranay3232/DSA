// divide and conqueror using recursion !
// Merge Sort : given an array [7,3,2,16,24,4,11,9]  first we sort the array when we divide it into two equal parts.

// Before diving here first we have to understand how to merge two arrays :
/*
given array1 = [1,3,5] array2=[2,4,5,6,7,8]

here we use two pointer approach : i,j if i<j we insert it into result array, else we insert j. and if array1 or 2 is finished first then we copy the remaining elements into result.

*/

/*
Merge sort :
[38,27,43,3,9,20] : step1 find mid, step 2 : break the array into two parts, step 3: sort the parts using recursion, step 4 : merge two parts

-->mid = 43
-->[38,27,43]  [3,9,20]

-->now again divide : assuming mid : 27, divide until there is only single element left
[38,27][43] [3,9] [20]

[38] [27] [43] [3] [9] [20]

-->now we merge them : if we merge the array we get sorted valued :

[27,38,43]  [3,9,20]

[3,9,20,27,38,43]
*/
#include <iostream>
#include <vector>
using namespace std;

void Merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    // NOTE : we dont have two separate arrays, its  just a single array and we call the left part start part and right part of array end.

    // now we create a new array for left part : because its a single array.

    // end to mid is another sub array. and we copy the values into it

    // left part :
    int len1 = mid - start + 1;
    // right part :
    int len2 = end - mid;

    // now create the arrays dynamically :
    int *left = new int[len1];
    int *right = new int[len2];

    // now copy the values :
    int k = start;
    // copy values for left
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k]; // storing values in k
        k++;
    }

    // for right values :
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // merge logic :
    int leftindex = 0;
    int rightindex = 0;
    int mainarrayindex = start;
    while (leftindex < len1 && rightindex < len2)
    {
        if (left[leftindex] < right[rightindex])
        {
            arr[mainarrayindex++] = left[leftindex++];
        }
        else
        {
            arr[mainarrayindex++] = right[rightindex++];
        }
    }

    // if an array ends first : copy logic for left array
    while (leftindex < len1)
    {

        arr[mainarrayindex++] = left[leftindex++];
    }

    // for right array
    while (rightindex < len2)
    {
        arr[mainarrayindex++] = right[rightindex++];
    }

    // Good practice: free the memory
    delete[] left;
    delete[] right;
}

void Mergesort(int *arr, int start, int end)
{
    // base case/ stopping case : if start == end invalid array and if start>= end. invalid array
    if (start >= end)
    {
        return;
    }
    // now get mid :
    int mid = start + (end - start) / 2;

    // recursion call :  to sort the left part.
    Mergesort(arr, start, mid);

    // recursion call to sort right part
    Mergesort(arr, mid + 1, end);

    // now merge two parts: create a function that sorts the both parts
    Merge(arr, start, end);
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 20};
    int n = 6; 
    int start = 0;
    int end = n - 1;

    // now we create a function and we pass it array, start ,end
    Mergesort(arr, start, end);
    // now print it :
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}