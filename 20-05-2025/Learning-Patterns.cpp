#include<iostream>
using namespace std;
int main(){
    //full square pattern :
    for(int row = 0; row<3; row = row+1){
        for(int col=0;col<15;col = col +1){
            cout<<"*";
        }
        cout<<endl;
    }
    // whats the difference between: i = i + 1, i+=1, i++. a simple difference among all is 1) i = i + 1(means take current value of i and add +1 to it then assign the result back to i) 2)i+=1 : same add 1 to i. 3) i ++ (this is an increment operator) means increment i + 1 after using i current value. (i = 5; i<10; i++) first use i=5 then increment by 1. (i = 6) at 2nd iteration
    
    
    // now lets pritn a square (same as rectangle but equal inner and outer loops)
    for(int rows1 = 0; rows1<5;rows1 = rows1 + 1){
        for(int col1=0;col1<5;col1 = col1 + 1){
            cout<<"*";
        }
        cout<<endl;
    }
}