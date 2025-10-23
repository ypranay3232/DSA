// Lets see how to print a solid diamond pattern : 
/*

        *
       * * 
      * * * 
     * * * * 
    * * * * * 
    * * * * *
     * * * * 
      * * * 
       * * 
        * 



*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the length of the pyramid"<<endl;
    cin>>n;

    // we just combined both programs full pyramid and inverted full pyramid.

    // full pyramid
    for(int row=0;row<n;row=row+1){
        // now lets print the spaces in inner loop 
        
        for(int cols=0;cols<n-row-1; cols=cols+1){
            cout<<" ";
        }
        // now lets print stars 
        for(int cols=0;cols<row+1;cols=cols+1){
            cout<<"* ";
        }
        cout<<endl;
    }

    // inverted full pyramid
    for(int row=0;row<n;row=row+1){
        // now lets print the spaces in inner loop 
        
        for(int cols=0;cols<row; cols=cols+1){
            cout<<" ";
        }
        // now lets print stars 
        for(int cols=0;cols<n-row;cols=cols+1){
            cout<<"* ";
        }
        cout<<endl;
    }


}