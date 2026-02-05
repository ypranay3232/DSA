// The core funda of BS is divide an array with mid (where mid = start+end/2)
#include<iostream>
#include<vector>
using namespace std;

int binarsearch(vector<int> arr,int start, int end,int key){
    // base case : the program should stop when start > = end
    if(start > end) return -1;

    int mid = (start+ end)/2;
    // and if current index found key the program should stop
    if(arr[mid] == key) return mid;

    // if arr[mid] < key then key will exist on right
    if(arr[mid]<key){
        return binarsearch(arr,mid+1,end,key);
    } else{
        // then search at left side.
        return  binarsearch(arr,start,mid-1,key);
    }
}

int main(){
    vector<int> arr{10,20,30,40,70,99};
    int target = 70;

    int n = arr.size();
    int start = 0;
    int end = n-1;

    int ans = binarsearch(arr,start,end,target);
    cout<<"The answer is : "<<ans<<endl;

    return 0;
}