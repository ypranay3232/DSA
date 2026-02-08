// The time complexity of an iterative function : we say that in a iterative program when we have a for(), 1) one after another we say it as : O(N) + O(M) 2) for() inside for() we say O(n^2)

// Computer handles the recursion in Stack : ex:
// first it calls main() --> then recursion(n) processed and allocated n bytes, now we call reclusion for n-1:  recursion(n-1) this process and allocate again and it calls recursion(n-2), the all recursion(n), recursion (n-1) recursion(n-2) all waiting to get a value and once the recursion end they get a value and they return that value to each other and it reaches to main.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printarray(int a[], int n)
{
    // base condition
    if (n == 0)
        return;

    // print : printing the value of a, a points to starting index.
    cout << *a << " ";

    // recursion :
    printarray(a + 1, n - 1); // this increments each element of array +1 for each next recursive call.and when we do n-1 the function gets call for n-1 and when n == 0 it stops.

    // Time complexity : O(n) because it takes,  T(n) = n (array) + k (processing , because these all are constants we ignore and do as : O(n)

    // space complexity : O(n)
}

// factorial :
int fact(int n)
{
    if (n <= 1)
        return 1;

    return n * fact(n - 1); // 5 * 4, 4* 3, 3*2,2*1, now the computation : fact(2) = 2*1 = 2, fact(3) = 3 * 2 = 6, fact(4) = 4 * 6 = 24, fact(5) = 5 * 24 = 120.

    // Times : O(n) because each num from n to 1 is visited exactly once. if n = 5 there are 5 calls
    // space : O(n) : because n = 5 and facts takes fact(5) a const memory gets allocated
}

int BS(int a[], int k, int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (a[mid] == k)
    { // if mid == target element
        return mid;
    }
    else if ((k > a[mid])) // if target > mid increment start
    {
        return BS(a, k, mid + 1, end);
    }
    else
    { // if k < mid then decrement end.
        return BS(a, k, start, mid - 1);
    }

    return mid;

    // time : O(n log n) when you have 1024 elements it takes 10 steps to find it 2^10 = 1024, worst/avg case.  best case L O(1) when the target is found on first try.

    // space : O(log n) : because it adds a new stack frame each time a recursive call occurs
}

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fib(n - 1) + fib(n - 2);//works as : 4 + 3, 3 + 2, 2 + 1.
    // time : O(2^n) : because fib(10) = takes 100calls and fib(30) takes 2.6 million calls, because we are calling n-1 and n-2 both so it takes 2*n, for 10 calls = 10 * 10 = 100.

    // space : O(n) even if we have 2.6 million calls, its dependent on height of tree. which is n so n = 5 so the space is 5.
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    int n = arr.size();
    cout << "The array is ";
    printarray(arr.data(), n); // instead of using &arr[0] we use .data() modern c++ approach to get the pointer to the underlying array used by the vector
    cout << endl;

    // factorial :
    cout << "the factorial is : " << fact(n) << endl;

    // Binary search :
    int a[] = {10, 30, 20, 43, 23, 42, 12, 64, 13, 46, 65, 98, 32};
    int size = sizeof(a) / sizeof(a[0]);
    int target = 43;

    // remember BS works on sorted array or values
    sort(a, a + size);

    int result = BS(a, target, 0, size - 1);

    if (result != -1)
    {
        cout << "found " << target << " at index " << result << endl;
    }
    else
    {
        cout << "not found " << target << endl;
    }

    // fibonacci
    cout << "the fib values are :";
    for(int i=0;i<=n;i++){
        cout<<fib(i)<<" ";
    }
    cout<<endl;


    return 0;
}