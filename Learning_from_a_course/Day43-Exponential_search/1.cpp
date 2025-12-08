#include<iostream>
#include<vector>
using namespace std;

// Binary search used after finding the range
int binarySearch(vector<int>& arr, int left, int right, int target) {
    while (left <= right) {

        int mid = left + (right - left) / 2;  // middle index to check

        if (arr[mid] == target)               // target found
            return mid;

        else if (arr[mid] < target)           // go to right half
            left = mid + 1;

        else                                  // go to left half
            right = mid - 1;
    }
    return -1;                                // target not found
}

// Exponential Search
int exponentialSearch(vector<int>& arr, int target) {

    // Step 1: Check if the first element is the target
    if (arr[0] == target)
        return 0;

    int n = arr.size();
    int i = 1;                                  // starting jump index

    // Step 2: Keep doubling until we exceed array or pass the target
    while (i < n && arr[i] < target) 
        i = i * 2;                              // exponential jump

    // Step 3: Apply binary search in the found range [i/2, min(i, n-1)]
    return binarySearch(arr, i/2, min(i, n-1), target);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 12, 15, 18, 21, 24};
    int target = 15;

    int index = exponentialSearch(arr, target);

    cout << "Target found at index: " << index << endl;

    return 0;
}
