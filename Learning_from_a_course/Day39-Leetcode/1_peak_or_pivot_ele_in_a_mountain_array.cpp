/*
Mountain array = increase values intil it reaches a highest point then decrease and return the highest valye index
Peak element in a mountain array : {0,10,5,2} their index is 0,1,2,3
now we have to find a peak element from the array.
Time complexity is : O(logn) which is binary search complexity.

we see two approaches 1)brute force 2)Binary search Optimised sol


*/
#include <iostream>
#include <vector>
using namespace std;

int findmountainele_brute_force(vector<int> &arr)
{
    // get the size of array to iterate
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        // now check condition if array current index is greater than its next index its the peak
        if (arr[i] > arr[i + 1])
        {
            return i;
        }
    }
    return -1;
}

// optimized approach : Binary Search (O(log(n)))
int peakIndexelement(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;

    // Run loop until low < high (from starting to end of array)
    while (low < high)
    {
        int mid = low + (high - low) / 2;

        // now check if mid < its next element.
        if (arr[mid] < arr[mid + 1])
        {
            // if mid is less than its next element then move low to mid+1, so we know the peak element is in right side no need to search from left side so move left to mid + 1 and search again
            low = mid + 1;
        }
        else
        {
            // if mid is greater than next index so the peak element, so mid is peak or somewhere in left. So move high to mid. and search from high
            high = mid;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {0, 10, 5, 2};
    int func_call = findmountainele_brute_force(arr);
    int Opt_sol = peakIndexelement(arr);
    cout << "The Brute force approach is : " << func_call << "\n";
    cout << "The Brute Optimized approach is : " << Opt_sol << "\n";
}