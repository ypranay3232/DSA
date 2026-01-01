#include<iostream>
#include<vector>
#include<string>//to use getline
using namespace std;

int main(){
    // How to take input 2) ways : 1>as sequence 
    char ch[100];
    cout<<"Enter your name : "<<endl;
    cin>>ch;
    cout<<"Your name is "<<ch<<endl;

    // 2) As char by char
    char cha[10];
    cha[0] = 'a';
    cha[1] = 'b';
    cha[2] = 'c';
    cha[3] = 'd';

    cout<<cha[0]<<cha[1]<<cha[2]<<cha[3]<<endl;

    // String termination contains a null value 
    char c[10];
    cin>>c;
    for(int i =0;i<7;i++){
        cout<<"index "<<i<<" value "<<c[i]<<endl;
    }

    // as we can see when input is less that length of array we can see after the array length we have an empty space and below it a ? symbol that is array garbage value. ignore it but the space is null value lets check it by converting it into integer 

    int check = (int)c[4];
    cout<<check<<endl;//returns 0 --> 0 ACII value 0 belongs to null value 

    // Task Create a character array and create it with space in between and print it, if you teaks input as "hello world" the input is registered only unto hello not the world, Because the cin>>reads the input until it finds a space/tab or new line (" " or \t or \n)
    char task[100];
    // cin>>task;
    // cout<<"The Value is : "<<task<<endl;
    // to fix we use getline and it belongs to string, and before using getline() we have to clear the buffer so use cin.ignore();
    cin.ignore();
    cout<<"Enter full input "<<endl;
    cin.getline(task, 100);
    cout<<"The fix is as : "<<task<<endl;
}