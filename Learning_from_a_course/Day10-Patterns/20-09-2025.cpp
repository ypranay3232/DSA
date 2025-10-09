// Lets revise and Practice patterns ! 

// first lets print a solid square
#include<iostream>
using namespace std;

int main(){

    // for(int Rows = 0; Rows<10;++Rows){
    //     for(int cols=0;cols<10;++cols){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    // // Now lets print the Hollow Square ! 
    // int n;
    // cout<<"Enter the value of n : "<<endl;
    // cin>>n;
    // for(int i =0;i<n;++i){
    //     for(int j=0;j<n;++j){
    //         // in previous question we printed the star here now we add a if condition here ! we need to print the stars only at starting and ending for both rows and cols so we keep condition as if i at 0th position or ending position or j at 0th position or at ending position print stars else print space.
    //         if(i==0 || i== n-1||j==0 || j== n-1){
    //             cout<<"*";
    //         }else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // // Now lets print the Hollow inverted half pyramid ! from previous we understood that we can print the 0th index for rows and cols it can print an inverted triangle but about the inverted line we use a formula as : 
    // // cols1= stars-rows1-1
    // int stars;
    // cout<<"Enter the number of stars you want to print : "<<endl;
    // cin>>stars;

    // for(int rows1=0;rows1<stars;++rows1){
    //     for(int cols1=0;cols1<stars;++cols1){
    //         if(rows1==0 || cols1==0| cols1==stars-rows1-1 ){
    //             cout<<"*";
    //         }else{
    //             cout<<" ";
    //         }
    //     }cout<<endl;
    // }

    // print a Hollow Full pyramid ! its a bit tricky but i think i found the pattern ! Here while printing the full pyramid we take only odd number of stars such as (1,3,5,7,9,11)
    int n;
    cout<<"Enter the number of stars: "<<endl;
    cin>>n;
    for(int i=0;i<n;++i){
        int k=0;
        for(int j=0;j<((2*n)-1);++j){
            if(j<n-i-1){
                cout<<" ";
            }else if(k <2*i+1){
                cout<<"*";
                k++;
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}