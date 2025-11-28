/*
Implementation of binary search on 2d arrays:
here we use end as n*m-1, to get the size of array
Assume a array with 5 rows and 4 cols elements from 1 - 20. so mid would be = 0+19/2
*/

#include <iostream>
#include <vector>

using namespace std;

int binarysearch(int arr[][4], int rows, int cols, int target)
{
    // n = rows and m = cols
    int start = 0;
    int end = rows * cols - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        int rowIndex = mid / cols;
        int colIndex = mid % cols;

        // now check if element is > = target then return true
        if (arr[rowIndex][colIndex] == target)
        {
            cout<<"Found at Index : "<<rowIndex<< " "<<colIndex<<endl;
            return true; // element found
        }
        if (arr[rowIndex][colIndex] < target)
        {
            // then search left side
            start = mid + 1;
        }
        else
        {
            // else if current index > target then search left side
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return false;
}

int main()
{
    int arr[5][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16},
                     {17, 18, 19, 20}};
    int target;
    cout << "enter the target element to search : " << endl;
    cin >> target;

    int rows = 5;
    int cols = 4;

    bool ans = binarysearch(arr, rows, cols, target);
    if (ans)
    {
        cout << "Binary search element found : " << endl;
    }
    else
    {
        cout << "binary search element not found " << endl;
    }
    return 0;
}