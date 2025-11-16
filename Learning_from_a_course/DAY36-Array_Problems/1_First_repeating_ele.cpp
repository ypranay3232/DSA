/*
A question from GFG : 
Given an array arr[], find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.

(.i.e. return the first repeating element from an array so considering the below ex: we should return its index (1), because it repeat first. And from below ex: we can understand that the array indexing starts from 1, because the index of 5 is meantioned as 2. )

Note:- The position you return should be according to 1-based indexing. 

Examples:

Input: arr[] = [1, 5, 3, 4, 3, 5, 6]
Output: 2
Explanation: 5 appears twice and its first appearance is at index 2 which is less than 3 whose first the occurring index is 3.
Input: arr[] = [1, 2, 3, 4]
Output: -1
Explanation: All elements appear only once so answer is -1.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106

Expected Complexities
Company Tags
Amazon Oracle


Approaches : 1) To use a loop and check array's current index with every other element (i == i+1) if true then we return current value of (i).


*/
#include<iostream>
#include<vector>
using namespace std;

int first_repeating_sol(int arr[],int n){
    for(int i =0;i<n;i++){
        // now we find the repeated element ! 
        // another loop that runs from i + 1 so our array index will be i+1. so that we can check array elements with next index.
        for(int j = i+1;j<n;j++){
            // now check condition if a[i] == a[j] if yes make isrepeatd = true;
            if(arr[i]==arr[j]){
                return i + 1;//because we need first occurence of a repeating element.
            }
        }
    }
    return -1; //if not found any repeating element return false.
}

int main(){
    vector<int> arr = {1,5,3,4,3,5,6};
    cout<<"The repeating element is : "<<first_repeating_sol(arr.data(),arr.size())<<endl;
}