#include<iostream>
using namespace std;

int finding_Max(int a, int b, int c);
int main(){
    int a,b,c;
    cout<<"Enter the value of a b c :"<<endl;
    cin>>a>>b>>c;

    int find_Max = finding_Max(a,b,c);
    cout<<find_Max<<endl;
}
int finding_Max(int num1, int num2, int num3){
    if(num1 > num2 && num1 > num3){
        cout<<"Num1 is Maximum : "<<endl;
        return num1;
    }else if(num2> num1 && num2 > num3){
        cout<<"Num2 is Maximum : "<<endl;
    }else{
        cout<<"Num3 is Maximum"<<endl;
    }
}