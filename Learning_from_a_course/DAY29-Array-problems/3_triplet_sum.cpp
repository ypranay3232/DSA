/* here we need to find the Target number/sum using 3 numbers
simple use 3 loops for brute force approach ! Complexity is O(n^3) because we are using 3 loops
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    int target = 100;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                // now check the condition if arri,j,k == target then print the pairs
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    cout << "(" << arr[i] << "," << arr[j] << "," << arr[k] << ")" << endl; // prints every possible pair But if we want only in order not to repeat any then we can do it as : j = i+1, k = j+1 so we dont repeat the array and we skip to i+1 th position. But if you want all the possible pairs you can use i=0,j=0,k=0
                }
            }
        }
    }

    // we have the optimised solution by using Two pointer aproach ! See as we know for two pointer approach we use two pointers and we move them.

    /*What we do is : we create an array and sort the array inorder so we can traverse through it
    Now we fix an element to compare (.i.e. arr[i])
    now we use two pointers : left = i + 1. because left moves to right so (+1)
    Right = n - 1. because Right moves towards left so (-1)

    now we compute sum ! arr[i] + arr[left] + arr[right]
    and check if : sum == target --> valid triple so print it
    if sum < target -->  Then move the left ++ so we get higher values and we get target
    if sum > target -->  Then move the right -- so we decrement the values and get Target.

    */

    cout<<"======================================="<<endl;

    // optimal solution that reduces one loop so any triple or quadriple which has Time complexity as O(n^3)
    // optimal solution that reduces one loop so any triple or quadriple which has Time complexity as O(n^3) it reduces that to O(n^2) and space complexity is O(1)
    vector<int> array = {30, 20, 40, 50, 10, 80, 70, 60};
    int target1 = 100;
    // now we sort the array
    sort(array.begin(), array.end());
    // now take array size
    int n = array.size();

    // now creating an outer loop to iterate and because we use two pointers we use n-2. because the pointers are pointing to the current elements.
    for (int i = 0; i < n - 2; i++)
    {
        // declare two pointers
        int left = i + 1;
        int right = n - 1;

        // now check the condition while left < right ! which is always true then we create sum. 
        while(left< right){
            int sum = array[i] + array[left] + array[right]; 
            // works as = 10 + left= i+1 index = 20 + right = 60 : 30 + 60 = (10,20,60) = 90

            // now if that sum == target we print the pairs 
            if(sum == target1){
                cout<<"("<<array[i]<<","<<array[left]<<","<<array[right]<<")"<<endl;
                // print and increment so the pointers can move to next steps 
                left ++;
                right --;

            }
            // else if sum is less than target we increment left ++ so we can get higher values and it can become equal to target
            else if(sum < target1){
                left++;
            }
            else{
                // if sum > right then we decrement the values
                right--;
            }
        }
    }
}