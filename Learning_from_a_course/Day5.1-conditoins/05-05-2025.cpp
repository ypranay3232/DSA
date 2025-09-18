#include<iostream>
using namespace std;

int main(){
    // Nested if else

    // int grades;
    // cout<<"Enter your grade i will tell your figure : "<<endl;
    // cin>>grades;

    // if(grades>=95){
    //     cout<<"Better luck Next time"<<endl;
    // }
    // else{
    //     if(grades>=80){
    //         cout<<"Work hard next time"<<endl;
    //     }
    //     else{
    //         if(grades>=70){
    //             cout<<"paisaa barbaadh "<<endl;
    //         }
    //     }
    // }
    // cout<<"Kal se Padai likhayi bandh "<<endl;



    // We can do the same thing using else if.

    // if(grades>=95){
    //     cout<<"Better luck Next time"<<endl;
    // }
    // else if(grades>=80){
    //     cout<<"Work Hard next time"<<endl;
    // }
    // else if(grades>= 70){
    //     cout<<"Paisaa barbadh"<<endl;
    // }
    // else if(grades<70){
    //     cout<<"Kal se Padai likhayi bandh"<<endl;
    // }


    // // exercise:
    // cout<<"------------------------------------------------------------------------------"<<endl;
    // int Num_Of_Backlogs;
    // cout<<"kitte Back he subjects ? "<<endl;
    // cin>> Num_Of_Backlogs;

    // if(Num_Of_Backlogs == 0){
    //     cout<<"OOO Topper he saala ! "<<endl;
    // }else{
    //     cout<<"koi na hamaara bhi wahi haal he "<<endl;
    // }


    // Loops : we use Loops to repeat a task N no of times (for, for each, while , do while)
    for(int i = 0;i<5;i++){
        // cout<<"Hello world"<<endl;
        cout<<i;
    }
    for(int i = 5; i>0; i = i-1){
        cout<<i<<endl; //THe condition is (i = 5 then we did i-1 so 4 .... and at 1-1 = 0. now 0 is not >0 so false)
    }
    cout<<"---------------------"<<endl;

    // exercise: 
    for(int i = 1;i<=10;i = i+1){
        cout<<2*i<<endl;
        // works as (i = 1.....10 now we print as 2*i which is 2*1....2*10 = 20 so output is : 2,4,6,8...20)
    }cout<<"---------------------"<<endl;



    // Understand this : 
    for(int i = 0;i<=10;i = i+2){
        cout<<i<<endl;//Here we are skipping 2 elements each time 0,3(skipped 0-->1 and 1-->2)
    }
    cout<<"---------------------"<<endl;

    for(int i = 1; i<=10;i = i*2){
        cout<<i<<endl;
    }
    cout<<"---------------------"<<endl;

    
    for(int i = 100; i>=10; i = i/2){
        cout<<i<<endl;
    }

    

}