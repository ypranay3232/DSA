/*
Let's print the Floyd's Triangle Pattern
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
16 17 18 19 20 21
22 23 24 25 26 27 28

Learnings from Yesterday Pattern : we can use a counter to keep track of the numbers
Then we can increment after each row after printing the counter, so that we get this pattern.

*/
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the height of the tringle : "<<endl;
    cin>>n;

    int Counter = 1;

    for(int row=1; row<=n;row=row+1){
        for(int cols=1;cols<=row;cols=cols+1){
            cout<<Counter<<" ";
            Counter++;
        }
        cout<<endl;
    }

}