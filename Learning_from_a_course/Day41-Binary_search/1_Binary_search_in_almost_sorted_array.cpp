/*
Binary search in a nearly sorted array : ex: {10,3,40,20,50,80,70}
And any element (index) can be found in 3 positions (at ith index or i+1 index or i-1 index) if the array was sorted. But here we need to write 3 cases for if statement to check mid value if target == mid or target = mid-1 or target == mid+1. to cehck if element exist in any of the folowing (-1,0,1) of its index
*/

#include<iostream>
#include<vector>
using namespace std;
int Binarysearchforalmostsortedarray(vector<int>arr, int target){
    int start =0;
    int end = arr.size()-1;
    int mid = start+ (end - start)/2;

    while(start<=end){
        if(arr[mid]==target){
            return mid;
        }
        // can go out of bounds so make sure to handle this 
        if(mid+1 < arr.size() && arr[mid+1] == target){
            return mid+1;
        }
        // when target value is at starting index when we check at -1 we may get a negative number so : 
        if(mid-1>=0 && arr[mid-1]==target){
            return mid-1;
        }
        // This above code is to find middle element now lets find the right and left element

        if(target>arr[mid]){
            // then search right
            start = mid + 1; //becasue we already searched for mid+1 earlier so we do mid + 2
        }
        else{
            end = mid -2;
        }
        // now updated mid values
        mid = start + (end-start)/2;
    }
    return -1;
}
int main(){
    vector<int> arr = {10,3,40,20,50,80,70};
    int target = 40;//target is at index 2

    int ans = Binarysearchforalmostsortedarray(arr,target);
    cout<<"index of "<<target<<" is "<<ans<<endl;
}