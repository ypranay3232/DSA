/*
Let's print this pattern : Hollow half Pyramid

1 2 3 4 5
2     5
3   5
4 5
5

Let's find the formula first : as we can see first we need to print row ==0,

row     pattern(numbers)
1           1
2           2
3           3
4           4
5           5

so we can say that (row == cols). Now let's find out how to print the (remiaing n-1) pattern !
rows  pattern(Numbers)
1       5
2
3
4
5

*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the Length of the Pattern " << endl;
    cin >> n;

    for(int row = 1; row <= n; row = row + 1){
        // The Pattern stars at 1 so we take row and cols = 1. 
        for(int cols = 1; cols <= n; cols = cols + 1){
            // same Print the cols and rows till they are equal to n. And the condition is : if row ==1 (first row), cols == row(Prints cols according to equal to row) so we get (12345) in both directions at row and cols.

            /*
            rows : 1 2 3 4 5 : but we print cols equal to rows which create a diagonal line
                   2 (prints 2 only when row == cols) (i.e. row2 == cols 2) so we print cols as (2)
                   3
                   4
                   5
            
            */

            // Prints 5 at each last column so we use cols == n (5) so when we print cols we print them as (2 5), (3 5), (4 5) at their respective positions so it looks like a (N-1) decrementing pattern for 5.

            /*
            works as : 
            1 2 3 4 5 
            2'3 4' 5
            3'4'5
            4 5
            5
            
            Here 3,4 and 4,5 are not printed i wrote for my understanding. so that's how we get 5 */
            if(row == 1 || cols == row || cols == n){
                cout << cols << " ";
                // The else if prints two spaces inbetween the diagonals : cols > row == prints spaces after and before diagonal (i.e 5), cols<n prits before diagonal (i.e 5)
            } else if(cols > row && cols < n) {
                cout << "  "; 
            }
        }
        cout << endl;
    }
}