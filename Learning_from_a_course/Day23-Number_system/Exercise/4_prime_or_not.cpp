// check if a given number is prime or not ! A prime number has two factors 1) it is divided by 1 and 2) it is divided by N(.i.e. itself)

#include<iostream>
using namespace std;


// Works as : first we create a function that takes an parameter 'n' and we start from 2, because a prime number is a number greater than 1 and that is divisible by 1. so we start from 2. and increment til <n. if any number(n) %i == 0 return false. not prime. if % i ==1 then return true. lllllll
bool checkprime(int n){
    int i = 2;
    for(i = 2; i<n;i++){
        if(n%i ==0 ){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;

    bool isprime = checkprime(n);
    if(isprime){
        cout<<"prime\n";
    }else{
        cout<<"not prime \n"<<endl;
    }
}