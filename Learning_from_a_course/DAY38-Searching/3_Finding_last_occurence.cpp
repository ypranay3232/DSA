/*
In binary search as we know how to find the first occurence and in the same process we find last element !

ex: {2,5,7,7,7,7,9,10}

we initialise start = 0, end = 7, mid = start+end/2 = 4,
so Mid point to (7 at index 4), now we check if (arr[mid]==target)
{
if yes then we store target (ans = mid)
And for first occurence we go to left and check it any 7 occured before this so we go to left
Anf for Last occurence we go to right and check  does the 7 contains any other 7 on right side ? so it makes a last occurence and if yes we store it else we encountered the 7.

}

*/
#include <iostream>
#include <vector>
using namespace std;

int lastoccurence(const vector<int> &v, int target)
{
    int start = 0;
    int end = static_cast<int>(v.size()) - 1;
    int ans = -1;
    // Run the loop until start is less than end.
    while (start <= end)
    {
        // if mid matches with target, create a ans variable and store mid init, move to right side to check next occurences
        int mid = start + (end - start) / 2;

        if (v[mid] == target)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (v[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> v = {2, 5, 7, 7, 7, 7, 9, 10};
    cout << "Enter the target element to search from array " << endl;
    int target;
    if (!(cin >> target)) {               // read target once and validate
        cout << "Invalid input.\n";
        return 0;
    }
    int result = lastoccurence(v, target);
    if (result == -1)
    {
        cout << "Target not found !" << endl;
    }
    else
    {
        cout << "target found at index : " << result << endl;
    }
    return 0;
}