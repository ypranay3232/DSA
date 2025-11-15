/* Find the missing elements from an given array
ex: Arry = {1,3,5,3,4};

Constrants :
Array elements in array are [1,n]\

Array size = N - array

As per the array elements we can say that '2' is missing from the array. We know that we can also treat this as a index (from last quesion)

Logic :
1,3,5,3,4 --> first we check array index : 1,2,3,4,5 (assuming no '0' this time for a index)

arr[1.3.5.3.4]
    1 2 3 4 5

we start loop (i) from index 1 and we mark 1 as -ve. so it becomes arr[-1,3,5,3,4], now the loop (i) will be on 2nd index and (arr[-1,3,5,3,4]) at index 2 we have value 3 so we go to the (index 3 and mark it visited)
                       1 2 3 4 5
now arr[-1,3,-5,3,4] now next index (3). we have value 5 so we go to index 5 value which is 4
arr[-1,3,-5,3,4]
     1 2  3  4  5

Now next inedx (4) its value is 3, But array index 3 value is already marked as negative (arr[-1,3,-5,3,-4])
so we can say that value 3 is duplicate. okay and now lets move to next, index (5) its value is 4, so we visit index 4 which is (3) and mark it as negative. now array is as :
arr[-1,3,-5,-3,-4]
     1 2  3  4  5
Now we can say that this is our final array but as we can see that we didn't visited (index (2) value 3)is not visited at index(2) because the same element is visited at index(4), so we can say that after the array remaining positive elements are the missing elements from an array. (if we replace 3 with 2 we can say our array is complete)


Method 1) Marking index as negative : time : O(n) because we are passing array N times and space : O(1)
Method 2) sorting + swapping : we can also do as (we can swap each index with its respective values). so we check (arr index == value)
*/

#include <iostream>
using namespace std;

void find_Missing(int *a, int *b, int n)
{
    // visited Method
    for (int i = 0; i < n; ++i)
    {
        // we have a challange because we assume the elements from 1, we need to get index.
        // and we dont need a negative value as indewx so we use absolute
        int index = abs(a[i]) - 1;

        // we do index -i because array starts from 0 and our elements start from 1. and if its not visited we visit the element
        if (index >= 0 && index < n && a[index] > 0)
        {

            a[index] = -a[index];
        }
    }

    // we sucessfully made it half way and pritned the array now we have to find the missing elements (.i.e can we done by changing positive indexes)
    cout << "Missing (method 1): ";
    for (int i = 0; i < n; ++i)
    { // i = 1 because our elements starts from 1
        if (a[i] > 0)
        { // if its a positive number we increment it
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    // Using method 2 :
    int i = 0;
    while (i < n)
    {
        int val = b[i];
        // check if a array element current index is not equal to its value the we swap
        int correct = val - 1; // so we can start from index 1
                               // Only swap when b[i] is within [1,n] and not already in correct place.
        if (val >= 1 && val <= n && b[i] != b[correct])
        {
            swap(b[i], b[correct]);
        }
        else
        {
            // if already index is same with value we just go to next index
            ++i;
        }
    }

    // now print the array
    cout << "Array after cyclic sort: ";
    for (int j = 0; j < n; ++j)
        cout << b[j] << " ";
    cout << "\n";
    cout << "Missing (method 2): ";
    for (int j = 0; j < n; ++j)
    {
        if (b[j] != j + 1)
            cout << j + 1 << " ";
    }
    cout << "\n";
}

int main()
{
    int n;
    int a[] = {1, 3, 5, 3, 4};
    int b[] = {1, 3, 5, 3, 4};
    // getting size of aray
    n = sizeof(a) / sizeof(int);

    // now we create a function named findmissing();
    find_Missing(a, b, n);
}