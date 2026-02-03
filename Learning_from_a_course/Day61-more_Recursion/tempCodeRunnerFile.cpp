// Optimized for Leetcode : 
int climbstairs(int n){
    if(n<=2) return n;

    int first = 1;
    int second = 2;

    for(int i =0;i<=3;i++){
        int third = first + second;
        int first = second;
        int second = third;
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