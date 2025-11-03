/*
So we take input from user (N)

*/
#include<iostream>
using namespace std;

// Works as : first we create a function and provide input from user and we create a sum variable and check if its <= user input and if no we increment it to (sum + i)

/*
if input == 10 

works as : 0 + i = 1
1 + 2 =3
3 + 3 = 9
4 + 4 = 8
8 + 5 = 13
13 + 6 = 21
21 + 7 = 28
28 + 8 = 36
36 + 9 = 45
45 + 10 = 55 ---> output : This is for overall sum we need only even sum so we add a condition as : we start loop from 2 becuase smallest even number is 2. then if less than user input we skip a number i = i+2

*/
int getsum(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum = sum + i;
    }

    return sum;
}

// to print the even number of sum till N 
int Even_sum(int a){
    int even1 = 0;
    for(int i = 2; i<=a; i = i + 2){
        even1 = even1 + i;
    }
    return even1;
}
// we can also use another method to print sum of even numbers. we can just use if(i%2 ==0){sum = sum + i} 
// The modulous operator is a heavy operator that takes a lot of time to process while working in systems, so try to avoid it 

int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;

    // Now we create a vairable that stores the result
    int answer = getsum(n);
    cout<<"The Sum up to "<<n<<" even numbers is : "<<answer<<endl;
    

    // For Even numbers ! 
    int a;
    cout<<"Enter the value of A : "<<endl;
    cin>>a;
    int ans1 = Even_sum(a);
    cout<<"The sum of even numbers up to N is : "<<ans1<<endl;
    return 0;

}