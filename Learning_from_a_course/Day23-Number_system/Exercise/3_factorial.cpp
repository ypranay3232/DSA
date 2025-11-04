#include<iostream>
using namespace std;


int factorial(int n){
    int fact = 1;
    for(int i =1;i<=n;i++){
        fact = fact * i;
    }
    return fact;
}

int main(){

    int n;
    cout<<"Enter the factorial value : "<<endl;
    cin>>n;

    int result = factorial(n);
    cout<<"The given number "<<n<<" factorial value is : "<<result<<endl;

    return 0;

}