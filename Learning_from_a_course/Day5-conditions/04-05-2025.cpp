// conditions : if a condition is true we got into if block and execute that statement. if not we go to else.
#include<iostream>
using namespace std;

int main(){
    while (true)
    {   
    int age;
    int min_age = 18;
    cout<<"Enter your age : "<<endl;
    cin>>age;
    if(age>min_age){
        cout<<"you have to be consistent"<<endl;
    }
    else{
        cout<<"you are just a kid so no excuses just do what you love, find something to believe in"<<endl;
        break;
    }
    cout<<"No matter what be disciplined";

    }
} 