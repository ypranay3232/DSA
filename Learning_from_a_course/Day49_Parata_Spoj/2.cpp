#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Check if allocation is possible with maxPages limit
bool isPossible(vector<int>& arr, int M, int maxPages) {
    int students = 1;   // Start with first student
    int pages = 0;      // Pages assigned to current student

    for (int i = 0; i < arr.size(); i++) {
        // If current book exceeds limit
        if (arr[i] > maxPages)
            return false;

        // If adding book exceeds current limit
        if (pages + arr[i] > maxPages) {
            students++;         // Move to next student
            pages = arr[i];    // Assign book to new student

            if (students > M)
                return false;
        } else {
            pages += arr[i];   // Add book to current student
        }
    }
    return true;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int M = 2;

    int low = *max_element(arr.begin(), arr.end());     // Minimum possible
    int high = accumulate(arr.begin(), arr.end(), 0);  // Maximum possible
    int answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, M, mid)) {
            answer = mid;       // Store possible answer
            high = mid - 1;     // Try to minimize further
        } else {
            low = mid + 1;      // Increase limit
        }
    }

    cout << answer << endl;
}
