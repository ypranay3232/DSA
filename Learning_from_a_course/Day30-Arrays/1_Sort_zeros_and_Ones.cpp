/*
from a given set of numbers of 0's and 1 's sort 0's and 1's this is also known as : Dutch national problem

ex: array = {0,1,1,0,1,0,1,0,0}

output = { 0,0,0,0,0,1,1,1,1}

We use two pointer approach : first we create two pointers : start and end
and assign 'start' at starting of index and with value (0)
and assign 'End' with ending of index and with value (1)

and we take another variable 'i' and we assign it to start and we increment (i) and start and now we add a condition (if arr[i] ==0 ){ then swap(arr[i], with arr[start]) }
so we get 0's at start
and if(arr[i] == 1){ then swap(arr[i], with arr[end]) } and we decrenent end so we get 1 at end

Time complexity : O(N) space 0(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> array = {0, 1, 1, 0, 1, 0, 1, 0, 0};
    int n = array.size();

    int start = 0;
    int end = n-1; // so we can start with ending
    int mid = 0;//The mid vatiable is like a traversing pointer which traverse and check each number with start and end

    // now check if mid <= end which is alway true because 0< n-1 == True 
    while(mid<=end){
        // if array of mid ==0 : means (i)which is 0 so if 0 encountered swap with start  and increment both so we can get next values 
        if(array[mid]==0){
            swap(array[start],array[mid]);
            start++;
            mid++;
        }
        else if(array[mid]==1){
            // if mid value ==1 swap with end and decrement end value so we can get next values
            swap(array[mid],array[end]);
            end --;
        }
    }
    // now to print the sorted array elements : 
    cout<<"sorted array elements : ";
    for(int x : array){
        cout<<x<<" ";
    }


}
