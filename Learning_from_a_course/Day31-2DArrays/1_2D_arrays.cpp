/* 
As we know when we create an array 
int arr[] = {10,20,30,40};  This creates a sorage in memory and stores 10,20,30,40 and name it as arr

So that is a 1D array (.i.e. an array with size)
1D array = stores data linearly 


when we want to create a gird like rows and cols we can do it by creating a collection of 1D arrays. But as the no of rows and cols increases we can't create N number of 1D arrays so we use 2D arrays

on the Other hand 2D aray stores data in rows and cols Just like a table or matrix.
int arr[3][4]; //means 3 rows and 4 cols = 3*4 = 12 total elements can be fitted here


NOTE : point to be remembered, we can visualize 2D array as table or matrix but in memory it stores as a regular array 
ex: int arr[3][4] = 12 : [0,1,2,3,4,5,6,7,8,9,10,11]; it wont store in table format or matrix/grid rows and cols format in memory.


Formulas to be noted : 
c * i + j ==> columns 
r * i + j ==> rows

i = ith row 
j = jth col 

By using this formula : c*i+j = this finds out on which index the values are stored 

ex: want to find (2) which is at row 1 and col2: so by using formula : 
c = (contains no of cols)* i = (rows = 1) + j = (cols = 2)
3*1+5 = 5. 
so we can say that the value of 2 is stored at index 5.

*/
#include<iostream>
#include<vector>

using namespace std;
int main(){
    // creation of 2d array, Initialization part
    int array[3][3] = {{1,2,3},{4,5,6}, {7,8,9}};

    cout<<array[2][2]<<"\n";//prints 9 because 2nd row and 2nd col includeing 0, they point at 9.

    // if you are creating an array with N -> rows it should alway index between (0- n-1) and if M -> cols it should index between (0-m-1)

    // accessing the elements : 
}