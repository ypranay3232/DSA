/*write a code that prints sum by adding 4 pairs together */
#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> arr = {10,20,30,40,60,70,80,90};
    int target = 200;

    // now we create 4 loops and add a contidion to check if all together sum == target
    for(int i=0;i<arr.size();i++){
        // here we use i+1 because we want to continue from next element after i took an element we dont want to repeat the same value with itself
        for(int j=i+1;j<arr.size();j++){
            for(int k=j+1;k<arr.size();k++){
                for(int l=k+1;l<arr.size();l++){
                    // now add condition 
                    if(arr[i]+arr[j]+arr[k]+arr[l]==target){
                        cout<<"("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<","<<arr[l]<<")"<<endl;
                    }
                }
            }
        }
    }

}