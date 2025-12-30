#include <iostream>
#include <vector>
using namespace std;
int removeElement(vector<int> &nums, int val)
{
    // You are given a array and a target value (val), what you cant do it
    // you cant create another vector array and keep the numbers in it.

    // So you have to modify the existing array, the question does not care
    // if you delete bad numbers they just want you to move all good numbers to front.

    // ex: array = [3,2,2,3] you need to remove 3
    // now you need to move the 2's to front to the vector can start from 2,
    // the numbers at the end will not matter

    // Your function returns a number, assume that as k: If you return 2,
    //  nums[0] and nums[1] will be checked that's it.

    // ex; [0,1,2,2,3], val = 2(bad so remove to end), we push (0,1,3) as good elements
    // and push them to front, and now return (K = 3 becasue you found 3 good numbers at front)

    int k = 0; // counts good numbers
    for (int i = 0; i < nums.size(); i++)
    {
        // loop through the array and check if current element != val
        if (nums[i] != val)
        {
            // then we found good element (because val == bad element we move it to end)
            // now move the good number to next good number spot at index k
            nums[k] = nums[i];
            k++; // to go to next good number index
        }
    }
    return k;
}

int main() {

    // Test Case: array = [3, 2, 2, 3], val = 3
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    cout << "Original array: ";
    for(int x : nums) cout << x << " ";
    cout << "\nValue to remove: " << val << endl;

    // Call the function
    int k = removeElement(nums, val);

    // Print the result
    cout << "Return value (k): " << k << endl;
    cout << "Modified array (first k elements): ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}