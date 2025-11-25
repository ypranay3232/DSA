/* Find the missin element in a sorted array usign binary search, without using sum formula !
ex: 1,2,3,4,6,7,8 (the missing element is 5)

For a perfect array without missing numbers : array index + 1 = values of array
now if (!= arrayindex + 1 ) it is the missing number is encountered

Lets solve with two approaches 1) brute force 2)Optimised
*/

// Bruteforce
#include <iostream>
#include <vector>
using namespace std;

int Bruteforce(const vector<int> &arr)
{
    for (int i = 0; i < (int)arr.size(); i++)
    {
        // check for pattern breaking
        if (arr[i] != i + 1)
        {
            return i + 1; // it is the missing number
        }
    }
    return -1; // if no missing element exist
}

// Optimised approach !
int findmissingelement(vector<int> &arr)
{
    int low = 0;
    int high = (int)arr.size() - 1;

    // now check until low < = high
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // check condition !
        if (arr[mid] == mid + 1)
        {
            low = mid + 1; // if mid = array+1 index then mmove the mid to right half
        }
        else
        {
            // if mid is != mid value so the missing element must be left side
            high = mid - 1;
        }
    }
    if (low < (int)arr.size())
        return low + 1;
    return -1;
}

int main()
{
vector<int> arr;
    int choice;

    cout << "Press 0 for static input, 1 for dynamic input: ";
    cin >> choice;// take user choice

    if (choice == 0)
    {
        // Static input
        arr = {1, 2, 3, 4, 6, 7, 8};// sample static array
    }
    else if (choice == 1)
    {
        // Dynamic input
        int n;
        cout << "Enter size of array: ";
        cin >> n;

        arr.resize(n);// allocate array

        cout << "Enter " << n << " sorted elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];// taking input values from user
        }
    }
    else
    {
        cout << "Invalid choice!";
        return 0;
    }

    cout << "Bruteforce: " << Bruteforce(arr) << '\n';
    cout << "BinarySearch: " << findmissingelement(arr) << '\n';

    return 0;
}
