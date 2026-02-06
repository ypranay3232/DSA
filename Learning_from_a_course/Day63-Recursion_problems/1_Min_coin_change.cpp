// given an input array with distinct values (no duplicates) and size is n, target = x. you have to find the min no of elements required to reach target sum 

// ex: Target = 5, array = {1,2,3,..} 
// to get Target we have many possibilities : {1,1,1,1,1} = 5, {1,2,2} = 5 ....But we need minimum no of elements : ex: to get 5 {2,3} thats it.


#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& arr, int target){
    // Base Case : when the program will end we have only 2 occurrences to end program 1) if 0 2) if <0

    if(target==0){
        return 0;
    }
    if(target< 0){
        return INT_MAX;
    }


    int min_num = INT_MAX;//max
    for (int i = 0; i <arr.size(); i++)//try using every no in array
    {
        int ans = solve(arr, target - arr[i]);//recursive call, pick the current element (arr[i]) and find min element to reach remaining sum : (target - arr[i]) 
        if(ans != INT_MAX){
            min_num = min(min_num,ans+1);
        }
    }
    return min_num;
}

int main(){
    vector<int> arr{1,2,3};
    int target = 5;

    int ans = solve(arr,target);
    cout<<"Min no of elements need to reach "<<target<<" is "<<ans<<endl;
    return 0;
}