#include<iostream>
using namespace std;

int main(){
    // Lets try to print a full pyramid as we know : s1: print rows, s2: print cols
    
    // first we check the Condition if true then we enter inner loop of cols where if condition is true then we print a star. (first star) and now we break the loop and we start over again ! we check this time row=1 which is <5 the mentioned condition (so it enters inner loop) and now inner loop is rows+1 = (1+1=2) so prints (**)and same stars will be printed again and again until the given condition is false. 
    for(int rows=0; rows<6;rows+=1){
        for(int cols=0;cols<rows+1;cols+=1){
            cout<<"*";
        }
        cout<<endl;
    }

    // lets see how to print a  square or rectangle pattern (it's simple just make both rows=cols)

    for(int r1=0;r1<10;r1+=1){
        for(int c1=0;c1<10;c1+=1){
            cout<<"*";
        }
        cout<<endl;
    }
}



