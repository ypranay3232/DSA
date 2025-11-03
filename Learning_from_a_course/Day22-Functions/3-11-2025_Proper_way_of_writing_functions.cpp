#include<iostream>
using namespace std;


// In c++ we have to declare a function above main() because the main() function executes first before the another function. so if we declare it after main() it throws error, but we have a hack to run it. We just need to declare it on top and we can write body of function after main()

int result(int a, int b);
int main(){
    int a;
    cout<<"Enter the value of a : "<<endl;
    cin>>a;

    int b;
    cout<<"Enter the value of b : "<<endl;
    cin>>b;

    int sum = result(a,b);
    cout<<sum<<endl;

}
int result(int a, int b){
    int result = a +b;
    return result;
}