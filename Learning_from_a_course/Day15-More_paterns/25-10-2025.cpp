// LEts see how to print the pattern Flipped SOlid Diamond ! 

/*

                    * * * * * * * * * * 
                    * * * *     * * * *
                    * * *         * * * 
                    * *             * *
                    *                 *
                    *                 *
                    * *             * *
                    * * *         * * *
                    * * * *     * * * *
                    * * * * * * * * * *
                    
First we break the pattern into 3 parts (a left and right half pyramid and a empty spaces of a full pyramid) same for bottom. 

Then we can see it's nothing more than a two half pyramids and a full pyramid of sapces

Lets see how we gonna print it ! (As we can see the pattern ..! )

rows   stars
0       4
1       3
2       2
3       1
4       0


// Now lets see the formula as we can observe (Assume : N =4) so N-row
double check if it satisfy all the conditions ! 

4-0 = 4
4-1 = 3
4-2 = 2
4-3 = 1
4-4 = 0


*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the height of the Pyramid : "<<endl;
    cin>>n;
    // First half pyramid 
    for(int row=0;row<n;row=row+1){
        // Half pyramid
        for(int cols=0;cols<n-row;cols=cols+1){
            cout<<"*";
        }

        // spaces 
        for(int cols=0;cols<2*row;cols=cols+1){
            cout<<" ";
        }

        // half pyramid
        for(int cols=0;cols<n-row;cols=cols+1){
            cout<<"*";
        }
        cout<<endl;
    }//end of first half pyramid

    // seond half pyrmaid
    for(int row=0;row<n;row=row+1){
        // first lets print the first half

        /* so lets see how to get the pyramid as */

        for(int cols=0;cols<2*row+1;cols=cols+1){
            cout<<"*";
        }
        cout<<endl;
    }
}