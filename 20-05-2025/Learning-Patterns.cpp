#include<iostream>
using namespace std;
int main(){
    //full square pattern :
    for(int row = 0; row<3; row = row+1){
        for(int col=0;col<8;col = col +1){
            cout<<"*";
        }
        cout<<endl;
    }
}