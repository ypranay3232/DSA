// Lets revise the patterns 1. Full triangle 

// TO print a full triangle we have to first observe the pattern and now as we can see that we need to first print space and a star

// 1. for outer loop (i == rows) runs 6 times so that we can get the triangle.
/*
  I = 0             *
  I = 1            * * 
  I = 2           * * * 
  I = 3          * * * * 
  I = 4         * * * * *
  I = 5        * * * * * *
  I = 6       * * * * * * * 

*/

// This States how many times a loop runs to print the pattern. now lets go to inner loop 
// Here first we print the spaces then we print a star.

// At i/row = 0 we have 5 spaces and 1 star 
// At i/row = 1 we have 4 spaces and 2 stars 
// At i/row = 2 we have 3 spaces and 3 stars
// At i/row = 3 we have 2 spaces and 4 stars
// At i/row = 4 we have 1 spaces and 5 stars
// At i/row = 5 we have 0 spaces and 6 stars


/*lets assume a pattern here if we are having a pyramid and we are having 5 spaces and
the last one is a star (Assume that we are having 6 cols in a row) so we are having stars as :

0. When i = 0 we print spaces and at nth position we are printing a star
1. for 2nd row/i=1 here we are printing n-2 stars at n-2
2. for i = 2 we are printing 3 stars at n-3 position. 
3. for i = 3 we are printing 4 stars at n-4 position.
4. for i = 4 we are printing 5 stars at n-5 position.
5. for i = 5 we are printing 6 stars at n-6 position.
*/

// now we have a formula (N - row -1) this tells how many spaces to print before printing a star.

/*

N = Length of pyramid = 5 (because we are having 5 rows total) and we compare that with each row so ( n-row-1) to get spaces. 

when row = 0, we need 4 spaces if total rows = 5
so ( n - row - 1 == 5 - 0 - 1 = 4)

when row = 1, we need 3 spaces if total rows = 5
so (5-1-1=3) we have to print 3 spaces

row = 2, we need 2 spaces if total rows = 5
so ( 5 - 2 - 1 = 2) so we need 2 spaces

row = 3, we need 1 space if total rows = 5
so ( 5 - 3 -1 = 1) so we print 1 space 

row = 4, we need 0 spaces 
so ( 5 - 4 - 1) so we print 0 spaces 


SO this is the logic to print spaces. (n-row-1)
*/

// now to print stars assume : row = 0 we need 1 star. so to get 1 at 0th row position
// we add +1 (.i.e. row + 1 == 0+1=1)

#include<iostream>
using namespace std;

int main(){
    // first take input from user : 
    int n;
    cout<<"Enter the number of length you want for triangle : "<<endl;
    cin>>n;
    // first we create a outer loop to get the length of the triangle
    for(int row=0;row<n;row=row+1){
        // now first we need to print the spaces. to print spaces we have a formula !
        for(int cols=0; cols<n-row-1;cols=cols+1){
            cout<<" ";
        }
        // now lets print the stars ! 

        for(int cols=0; cols<row+1;cols=cols+1){
            cout<<"* ";
        }
        cout<<endl;
    }
}