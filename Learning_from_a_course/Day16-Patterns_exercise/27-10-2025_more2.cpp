/*
Let's print the following patterns !

* * * * * * *
* * * * * * *
* * * * * * *
* * * * * * *
* * * * * * *
* * * * * * *
* * * * * * *
* * * * * * *

just make the rows and cols equal to the size(N) thats it!


now Print the Hollow full square !

* * * * * * *
*           *
*           *
*           *
*           *
*           *
*           *
* * * * * * *

we just need to print star at position at first and last rows and first and last cols and everything else is space !


Let's try to print a inverted hollow half pyramid

* * * *
*   *
* *
*

Now let's print the Hollow Full Pyramid
        *
       * *
      *   *
     *     *
     * * * *

     First we print spaces and then we print the first star and spaces again and repeat (stars only at first and last position)

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the Lenght of the Pattern : " << endl;
    cin >> n;

    // for(int row=0;row<n;row=row+1){
    //     // now inner loop the formula is row<size, col<size thats it
    //     for(int col=0;col<n;col=col+1){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    // for(int row=0;row<n;row=row+1){

    //     for(int col=0;col<n;col=col+1){
    //         if(col == 0 || col == n-1 || row == 0 || row == n-1){
    //             cout<<"*";
    //         }
    //         else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // for (int row = 0; row < n; row = row + 1)
    // {
    //     for (int cols = 0; cols < n; cols = cols + 1)
    //     {

    //         /*
    //         * * * *
    //         *   *
    //         * *
    //         *

    //         The row ==0 and cols ==0 prints :

    //         * * * *
    //         *
    //         *
    //         *

    //         so to print the n-1 stars we use a formula as :

    //         rows stars(characters)  (N = 4)
    //         0       4
    //         1       3(including a space in between)
    //         2       2
    //         3       1

    //         so the formula is ( n- row ) = 4-0 = 4, 4-1=3, 4-2 = 2; 4-3=1.

    //         */
    //         if (row == 0 || cols == 0 || cols == n - row)
    //         {
    //             cout << "*";
    //         }
    //         else
    //         {
    //             cout << " ";
    //         }
    //     }
    //     cout<<endl;
    // }


    for (int row = 0; row < n; row = row + 1)
    {
        // first let's print spaces: 
        /*  so we use the formula as : n - row (4-0-1 = 3, 4-1-1=2, 4-2-1=1, 4-3-1 = 0 because the last row shall be full of stars)

        space space space space 
        space space space
        space space 
        space


        Now lets print the stars with space in between ! before that we can observe a pattern which is the spaces between both stars are odd as (1,3,5,7...) so we can do it as 

        2*row+1 = (2 * 0) + 1 = 1
        2*row+1 = (2 * 1) + 1 = 3
        2*row+1 = (2 * 2) + 1 = 5
        2*row+1 = (2 * 3) + 1 = 7


        the spaces are 
                    *       1 character 
                   *_*      3 character
                  *___*     5 character
                 *_____*    7 character
                *_______*   9 character
                
                
        now we print stars at position (cols ==0 )
                                        *
                                       *
                                      *
                                     *  

        and at position last which is (2 * row) because when we sue 2*row + 1 then the last (n-1) digit will be obviosuly (2*row) which is nth digit
                        *
                         *
                          *
                           *  

        now lets print the last stars (row == n-1) last row so print all stars 
        * * * * * 


        */
        for (int space = 0; space < n - row -1; space = space + 1)
        {
            cout << " ";
        }

        // now lets print the triangle stars ! to print
        for (int cols = 0; cols <2* row + 1; cols = cols + 1)
        {
            if (cols == 0 || cols == 2*row || row == n-1)
            {
                cout << "*";
            }else{
                cout<<" ";
            }
        }
        cout << endl;
    }
}