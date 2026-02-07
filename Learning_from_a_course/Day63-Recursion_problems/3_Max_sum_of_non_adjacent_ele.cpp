// given an array ex 2,1,4,9 return the max sum of subsequence in which no two elements are adjacent.  in subsequent a ele can be present or absent this pattern can be represented as inclusion and exclusion so we can solve it as : 

// max subsequence = 4+9 = 13, 2+9 = 11..... 
//  2,1,4,9 --> 2 included so : we do i + 2, (now array pointing to 4) now if we include 4 + 2(existing) it becomes 6, goes out of range. so we exclude so i+1, (mow point to 9) now we include 9 + 2 (11 out of range) so we exclude. this is all for array 2 now do the same for all [2,1,4,9]

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void solve(vector<int>& arr,int i,int sum, int &maxi){
    // base case : 
    if(i>= arr.size()){
        // update maximum number
        maxi = max(sum,maxi);
        return;
    }
    // include case : here we did i +2 because we should include only non adjacent elements, so if we include i, awe cant include i+1, so we include i +2
    solve(arr,i+2,sum+arr[i],maxi);

    // exclude 
    solve(arr,i+1,sum,maxi);

}
int main(){
    vector<int> arr{2,1,4,9};
    int sum = 0;
    int i =0;
    int maxi = INT_MIN;
    solve(arr,i,sum,maxi);
    cout<<"The result is : "<<maxi<<endl;
    return 0;
}