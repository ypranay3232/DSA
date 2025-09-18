#include<iostream>
using namespace std;
int main(){
    // in how many ways can we write a condition 

    // for(int i = 0; i<= 10; i++){
    //     cout <<i<<endl;
    // }


    // and what if we write it like this ? 

    // int a = 5;
    // for(;a<=10;a++){
    //     cout <<a<<endl;
    // }

    // we can also write the code as :  because we initialized a variable and then we added a condition to check and then we also added incremental statement so nothing is wrong in this code.
    
    
    // int Counter = 0;
    // for( ; ; ){
    //     if(Counter<10){
    //         cout<<Counter<<endl;
    //         Counter = Counter + 1;
    //     }
    // }

    int input; //declared a input 
    if (cout << "input") { //here the cout<<"input" this return an object ! so as we kept it in if statement 
        // if (cout obj){
        //  then cout<<"Hello" so thats the reason it prints (inputHello)
        //  }
        cout << "Hello" << endl;
    }

    cout<<"Enter your input : "<<endl;
    if(cin>>input){ //here the cin trying to read the input (if it is integer type) then it returns (hello world) else it returns invalid input
        cout<<"Hello world"<<endl;
    }else{
        cout<<"Invalid Input ! "<<endl;
    }
}