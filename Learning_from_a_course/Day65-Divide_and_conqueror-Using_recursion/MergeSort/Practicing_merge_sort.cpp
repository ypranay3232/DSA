// merge sort problem : [3,1,6,2,5,2,64,56,23,67,95]

#include <iostream>
using namespace std;

void Merge(int *arr, int s, int e)
{
    // now we create two sub arrays. which contains pointers to point, for left and right parts
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1; // left sub array
    int len2 = e - mid;     // right sub array

    // now create arrays dynamically and assign them to len1,len2
    int *left = new int[len1];
    int *right = new int[len2];

    // now copy the values into left, assign left current values into arr.  then increment it.
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k];
        k++;
    }
    // same for right part, as it starts from mid + 1
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // now merge logic :
    int leftindex = 0;
    int rightindex = 0;
    int mainarrayindex = s;
    while (leftindex < len1 && rightindex < len2)
    {
        if (left[leftindex] <= right[rightindex])
        {
            arr[mainarrayindex++] = left[leftindex++];
        }
        else
        {
            arr[mainarrayindex++] = right[rightindex++];
        }
    }

    // if the left array ends first copy remaining elements
    while (leftindex < len1)
    {
        arr[mainarrayindex++] = left[leftindex++];
    }
    // for right array
    while (rightindex < len2)
    {
        arr[mainarrayindex++] = right[rightindex++]; // Correctly using right
    }

    // now release the memory used by right and left
    delete[] left;
    delete[] right;
}

void MergeSort(int *arr, int s, int e)
{
    // Base Case : or stopping condition (when start > e its invalid)
    if (s >= e)
    {
        return;
    }
    // now get the mid
    int mid = s + (e - s) / 2;
    // now recursive call : to sort the left part of array
    MergeSort(arr, s, mid);

    // now recursive call to sort right part which starts from mid+1 to end
    MergeSort(arr, mid + 1, e);

    // now crucial part : we have to merge the two parts (left and right ?) so create a function that do the merging: this works as :
    // ex: arr1 = {1,3,5}
    // ex: arr1 = {1,3,5 } arr2 = {2,4,6,7} we use two pointer approach (left,right or i,j) if i<j we copy i to result array. else we copy j and when one array will be finished we copy remaining to the result.

    Merge(arr, s, e);
}
int main()
{
    // first define an array then also define the start, end, size of array
    int arr[] = {3, 1, 6, 2, 5, 2, 64, 56, 23, 67, 95};
    int s = 0;
    int n = 11;
    int e = n - 1;

    // now we create a recursive function that breaks the array into parts. (s1 : base case, s2: get mid, s3: recursive call, s4: merge)
    MergeSort(arr, s, e);
    // now print it :
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}