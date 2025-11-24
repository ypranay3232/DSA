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
#include <algorithm>
using namespace std;

int lastoccurence(const vector<int> &v, int target)
{
    int start = 0;
    int end = v.size() - 1;
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
    int target = 7;

    int result = lastoccurence(v, target);
    cout << "Last occurrence (custom binary search): " << result << endl;

    // Actually there is no need to code a custom function to find the first and last occurence of  a element, we can use upper_bound and lower bound form algorithm library they take iterator type so we can use (auto). 

    // The Upper_bound returns last occurence +1 so we have to use -1 to get last occurence, and on the other hand lower_bound returns first occurence.
    auto ans2 = upper_bound(v.begin(), v.end(), target);
    //
    int lastindex = (ans2 - v.begin()-1);
    cout << "The last occurence of an element by using std library function is : " << lastindex<< endl;

    return 0;
}