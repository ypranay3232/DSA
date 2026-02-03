// this problem calculates total no of ways to reach the nth stair, where you can take 1 or 2 steps at a time, this is a fibonacci sequence problem that uses logic as : ways(n) = ways(n-1)+ways(n-2)
#include<iostream>
using namespace std;

// int climbstairs(int n){
//     // base case to check ! 
//     if(n ==1 || n == 2){
//         return n;
//     }

//     int ans = climbstairs(n-1) + climbstairs(n-2);
//     return ans;

// }

    // Optimized for Leetcode : 
int climbstairs(int n){
    if(n<=2) return n;

    int first = 1;
    int second = 2;
    int third = 0;

    for(int i =0;i<=3;i++){
        third = first + second;
        first = second;
        second = third;
    }
    return second;
}

int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;//ex: 3, to get to stair 3 we have 3 ways, 1)ways : take 1,1,1 steps to reach 3rd stair from 0,
    // 2)way: take 1 stair, 2 stairs (NOTE : we can take 1 or 2 stairs)
    // 3) way : take 2 stairs, 1 stair. 
    cin>>n;

    int ans = climbstairs(n);
    cout<<"The answer is : "<<ans<<endl;

}
