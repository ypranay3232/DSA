/*
Mountain array = increase values intil it reaches a highest point then decrease and return the highest valye index
Peak element in a mountain array : {0,10,5,2} their index is 0,1,2,3  
now we have to find a peak element from the array. 
Time complexity is : O(logn) which is binary search complexity. 

we see two approaches 1)brute force 2)Binary search Optimised sol


*/
#include<iostream>
#include<vector>
using namespace std;

int findmountainele_brute_force (vector<int>&arr){
    // get the size of array to iterate
    int n = arr.size();

    for(int i =0;i<n-1;i++){
        // now check condition if array current index is greater than its next index its the peak
        if(arr[i]>arr[i+1]){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {0,10,5,2};
    int func_call = findmountainele_brute_force(arr);
    cout<<"The Brute force approach is : "<<func_call<<"\n";

}