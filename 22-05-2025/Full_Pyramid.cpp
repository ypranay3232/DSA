#include<iostream>
using namespace std;

int main(){
    // Lets try to print a full pyramid as we know : s1: print rows, s2: print cols/formulas logic
    
    for(int rows=0; rows<6;rows+=1){
        cout<<" ";
        for(int cols=0;cols<rows+1;cols+=1){
            cout<<"*";
        }
        cout<<endl;
    }
// hello
}