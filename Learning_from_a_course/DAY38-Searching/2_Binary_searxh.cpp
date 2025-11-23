/*
checking the first occurence of the array in binary search ex:
[1,3,4,4,4,4,4,6,7,9]
Target = 4

first we check start =0,end=9, and mid = start +end /2 = 0+9/2 = 4.
at idnex 4 we have value 4. so we found the traget but we dont print it we store it and check if we have any first occurences before this so we check left and do the same process.

Time Complexity of Binary Search is : O(logn)
*/
#include <iostream>
#include <vector>
using namespace std;

int firstocc(vector<int> v, int target)
{
    int start = 0;
    int end = v.size() - 1;
    int ans = -1;

    // Until start is less than or equal to end
    while (start <= end)
    {
        // Because mid depends on start and end, and start/end change every iteration. If you compute mid once outside the loop, it becomes stale, incorrect, and useless after the first update.
        
        int mid = start + (end - start) / 2;
        // if arr[mid] == target element then store the result and go to left
        if (v[mid] == target)
        {
            ans = mid;
            end = mid - 1; // to go to left to check if any first occurences are there
        }
        // if target is greater than mid value then move right side
        else if (target > v[mid])
        {
            start = mid + 1; // to move right
        }
        else
        {
            end = mid - 1; // move left even if mid is not equal to target and not greater than target (.i.e. its less than target so move left)
        }
    }
    return ans;
}

int main()
{
    vector<int> v{1, 3, 4, 4, 4, 4, 4, 6, 7};
    int target = 4;

    int indexof_firstoccurene = firstocc(v, target);
    cout << "The answer is : " << indexof_firstoccurene << endl;
    return 0;
}