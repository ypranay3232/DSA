/*
Searching is a process of finding a specific element from a given collection of data.
1) Linear search

ex: array = {3,2,1,5,7,9} --> if we want to Find the element 7 which is at index 4, we have to check all possible elements to get 7. ---> This takes O(n) complexity because if we use 1 for loop its O(N) if we use 2 its time complexity : O(n^2) and so on ...

so Assume if we have an array with 1000 elements then by using Linear search at worst case the program does 1000 comparisions.

But There is another algorithm called as binary search (ex: array with 1000 elements the comparision can be done under 10 comparisions)

Binary Search : To apply binary search we have a rule the array elements should be in Monotnic order (.i.e. the elements should be in either ascending order or descending order) it should be sorted in simple words

ex: [1,3,7,9,11,13,15,19] and Target = 15, so first we intialize start with index 0. end - index-1,       mid = start + end
      -----------
           2
(.i.e. 0 + 7 / 2 = 3) so the mid is at index 3.
Now we check if mid greaterthan or less than Target value(15) and now we shift to greater than part and change mid again : (start+end)/2 so : start gets updated to mid index, and mid is updated again after an operation so is at index (4 and end = 7) : (4+7)/2 = 11/2 = 5. so mid(5)
mid (5) = 13, so Target is greater than mid. Now we check again (mid = start + end (5+7=12/2=6)) so mid =6. Target == mid so found element.

Now Start = 6, end = 7 and mid = 6 so now Target value == mid yes.

What is the time complexity of the Binary Search :
In First iteration the binary search will be n-size.
at second iteratin the size will be : n/2 (becomes half) (n/2^1)
at third iteration the size becomes : n/4 (n/2^2)
at third iteration the size becomes : n/8 (n/2^3) so on up to

at kth iteration size will be : (n/2^k)

so we can say that : (n/2^k) = 1, so n = 2k, and logn = k

Time complexity = O(K) --> O(logn)

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int B_s(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    // int mid = (start + end) / 2; //This might arise an integer overflow issue ex: start = integer range 2^31-1 and end = integer range 2^31-1 the integer value overflows. so we use another formula which works same : mid = start +(end-start)/2

    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        int ele = arr[mid];

        if (ele == target)
        {
            // then we return index
            return mid;
        }
        else if (target < ele)
        {
            // if less than then we search left
            end = mid - 1;
        }
        else
        {
            // search in right side !
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    // if we get out of this loop means the element is not found
    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int target;
    int size = 8;
    cout << "Enter the element to search form given array : " << endl;
    cin >> target;

    int result = B_s(arr, size, target);

    if (result == -1)
    {
        cout << "Target not found !" << endl;
    }
    else
    {
        cout << "target found at index : " << result << endl;
    }

    // We have a Binary_search in STL : from algorithm package.
    vector<int> v{1, 2, 3, 4, 5, 6};
    // Lets see how to apply binary search function in arrays
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size1 = 9;

    // By using arrays :
    if (binary_search(arr1, arr1 + size1, 3)) // starting to iterate on vector from start to end and searching for element 3.

    // By using vectors
    // if(binary_search(v.begin(),v.end(),3))//starting to iterate on vector from start to end and searching for element 3.
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found " << endl;
    }
    return 0;
}