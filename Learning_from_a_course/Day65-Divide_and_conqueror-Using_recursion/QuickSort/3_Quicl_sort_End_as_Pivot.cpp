/*
This approach is same but here we take pivot as at element : 
first sort an array then place elements > pivot to right side and less to left side

        start            end
ex:         7,2,1,8,6,3,5,4
        i   j
where i = start -1, and j = start


simple logic : base condition until i< pivot (start < end) 
while(i<pivot){
    if(a[j] <a[pivot]){
        i++ //move the pointer 
        swap(a[i],a[j])//swap values of i with j 
    }
        j++
}
*/

// The pivot = last index wont work with Hoare's, Hoare's partition is designed such that the pivot doesn't necessarily move to its final sorted spot; it just ensures elements are partitioned.

// The fix we use: Lomuto Partition. This is the logic you actually described in your initial comment (i = start - 1, j = start).

#include<iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot is the last element
    int i = low - 1;       // Pointer for the smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    // Swap the pivot element with the element at i + 1
    swap(arr[i + 1], arr[high]);
    return (i + 1); // Return the final position of the pivot
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        // In Lomuto, the pivot 'p' is in its CORRECT spot,
        // so we sort the elements BEFORE and AFTER it.
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main() {
    int arr[] = {7, 2, 1, 8, 6, 3, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]); 

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}