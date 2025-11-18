/* Assume : we have 3 sorted arrays and they are all in increasing order. find the elements that are common in all three arrays.

NOTE : can you take care of duplicates without any additional structure ?

ex :
n1 = 6; A = {1,5,10,20,40,80}
n2 = 5; B = {6,7,20,80,100}
n3 = 8; C = {3,4,15,20,30,70,80,120}

output : 20, 80

Explanation : 20 and 80 are the only common elements in A, B and C

expected Time Complexity : O(n1+n2+n3)
expected Auxilary Space : O(n1+n2+n3)

// we can say that if (a[i]==b[j]==c[k]) then we find the common element.then we move next (i++,j++,k++)
if not equal we check if(a[i]<b[j]) then i++, move next.
if (b[j]<c[k]) we increment j++
else : last condition is (k++) because c[k] is low
*/
#include <iostream>
#include <vector>
// #include <set>

using namespace std;

vector<int> common_ele(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> ans;
    // set<int> st;
    // now create 3 pointers and initialize with 0
    int i = 0, j = 0, k = 0;
    // now a while loop (i -->which points to A(n1),j--> which points to B(n2), k -->which points to C{n3} ))
    while (i < n1 && j < n2 && k < n3)
    {
        // now check the condition
        if (A[i] == B[j] && B[j] == C[k])
        {
            // ans.push_back(A[i]); //we are counting duplicate values also so to avoid we use set
            // st.insert(A[i]);// The optimised sol without using Data structures (set)

            // so we check a condition if ans is empty add numbers, if ans is not empty check the last number you added, if last added number is different then add this new number, if last number is same then dont add this number (avoids duplication )
            if (ans.empty() || ans.back() != A[i])
            {
                // then push answer to A[i]
                ans.push_back(A[i]);
            }
            // create a variable val, and check condition (while i< n1 yes and A[i] ==val) (.ie. keep moving i until A[i] is no longer equal to A[i] until array is finished)
            int val = A[i];
            // skip duplicates in each array
            while (i < n1 && A[i] == val)
                ++i;
            while (j < n2 && B[j] == val)
                ++j;
            while (k < n3 && C[k] == val)
                ++k;
        }
        // now if not equal to each other then we have to find the smallest number among
        else if (A[i] < B[j])
        {
            // if less then we increment it
            i++;
        }
        else if (B[j] < C[k])
        {
            j++;
        }
        // if i and j are also not small numbers then k will be the one so increment it.
        else
        {
            k++;
        }
    }
    // // now lets print the set !
    // for (int i : st)
    // {
    //     ans.push_back(i);
    // }
    return ans;
}

int main()
{
    int A[] = {1, 5, 10, 20, 40, 80};
    int B[] = {6, 7, 20, 80, 100};
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};

    int n1 = sizeof(A) / sizeof(A[0]);//to calculate the size of array instead of manually declaring n1 = 6 total bytes / single byte
    int n2 = sizeof(B) / sizeof(B[0]);
    int n3 = sizeof(C) / sizeof(C[0]);

    // now call the function.
    vector<int> Result = common_ele(A, B, C, n1, n2, n3);
    // And print the array
    for (int X : Result)
    {
        cout << X << " ";
    }
    return 0;
}

// What is Auto : its a keyword from c++ 11 (from 2011) it simplify a for loop, Here Instead of declaring a data type we just give auto. ex:
// for(auto i : st){ code} --> works same as : for(int i =0;i<st;i++){ code }