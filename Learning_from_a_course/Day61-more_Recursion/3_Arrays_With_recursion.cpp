// write an algorithm that checks if the next element is greater than current element if yes return true else return false
#include<iostream>
#include<vector>
using namespace std;
bool checksorted(vector<int>& arr, int& n, int i){
    // base case
    if(i == n-1) return true;

    // condition of algorithm 
    if(arr[i+1]< arr[i]) return false;

    // recursion 
    return checksorted(arr,n,i+1);//i+1 increment to next position 
}

int main(){
    vector<int> v{10,20,30,40,68,54};
    int n= v.size();
    int i =0;

    bool issorted = checksorted(v,n,i);

    if(issorted){
        cout<<"Array is Sorted";
    }else{
        cout<<"Array is Not Sorted";
    }

}