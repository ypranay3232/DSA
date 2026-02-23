// Quick sort : here we partition a element (pivot) then sort all numbers less than the pivot at left and large numbers at right side.

// ex: 8,1,3,4,20,30,60 : pivot = 8, so now check every element if its > pivot or not if yes move if pivot < next element then place pivot at that position based on count. we dp it as : arr[pivot] is swapped with arr[start+count]

#include <iostream>
#include<algorithm>
using namespace std;

int partition(int *arr, int s, int e)
{
    // step1 : select pivot element
    int pivotindex = s;
    int pivotelement = arr[s];

    // step 2 : now find right position for pivot
    int count = 0;
    // because pivot element is at s we start from s+1
    for (int i = s + 1; i <= e; i++)
    {
        // if current ele is <=  pivotelement move the count
        if (arr[i] <= pivotelement)
        {
            count++;
        }
    }

    // now after the loop we found the correct position for pivot
    int correctposition = s + count;
    // now swap current pivot with correctposition
    swap(arr[pivotindex], arr[correctposition]);
    pivotindex = correctposition;

    // now we placed pivot now place numbers less than pivot at left and numbers which are greater than pivot at right side

    int i = s;
    int j = e;

    // until both i,j reach pivot we loop them
    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] < pivotelement)
        {
            i++;
        }
        while (arr[j] > pivotelement)
        {
            j--;
        }

        // now we have two cases here : 1) found some elements to swap after pivot placing
        // 2) no need to swap all the elements are in order
        if (i < pivotindex && j > pivotindex)
        {
            swap(arr[i], arr[j]);
        }
    }
    return pivotindex;
}

void quicksort(int *arr, int s, int e)
{
    // base case or stopping condition when start >= end, its an invalid array
    if (s >= e)
    {
        return;
    }

    // partition logic :
    int p = partition(arr, s, e);

    // recursion call for left part :
    quicksort(arr, s, p - 1);

    // recursive call for right part :
    quicksort(arr, p + 1, e);
}

int main()
{
    int arr[] = {8, 1, 3, 4, 20, 80, 95};
    int n = 7;

    int s = 0;
    int e = n - 1;

    quicksort(arr, s, e);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
