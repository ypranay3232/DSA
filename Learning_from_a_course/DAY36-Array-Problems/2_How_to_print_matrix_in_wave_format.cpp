/* Let's see how to print a matrix in wave format.

    0  1  2  3
  ----------------
0 | 1  2  3  4
1 | 5  6  7  8
2 | 9 10 11 12

we print it as a wave form : 1 5 9 10 6 2 3 7 11 12 8 4

|  _   _
| | | | | |
|_| |_| |_|

NOTE : when col 0 : direction Top to bottom
            col 1 : Bottom to Top
            col 2 : Top to Botton
            col 3 : Bottom to Top

we can say that if even no of cols we go Top to bottom, if Odd number of cols we go from Bottom to top.
*/

#include<iostream>
#include<vector>

using namespace std;

void wavematrix(vector<vector<int>>v){
    // first find the rows and cols
    int row = v.size();
    int col = v[0].size();
    //now loop through cols 
    for(int startcol =0;startcol<col;startcol++){
        // if even no of cols --> Top to Bottom
        if((startcol & 1)==0){
            for(int i=0;i<row;i++){
                cout<<v[i][startcol]<<" ";//printing element which is at row and col, because its a 2D array
            }
        }
        else{
            // If odd print Bottom to top, The bottom starts from : row - 1
            for(int i=row-1;i>=0;i--){
                // then we print row 
                cout<<v[i][startcol]<<" ";
            }
        }
    } 
}


int main(){
    vector<vector<int>> v{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };

    wavematrix(v);
    return 0;
}