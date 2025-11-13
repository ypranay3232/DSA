/*
Findind the maximum number from an array ! first we create a variable that is initialised to a INT_MIN
and we check that variable with array. if array value is greater than variable then we store the value into the variable.
*/

#include<iostream>
#include <climits>

using namespace std;

int find_max(int array[3][4], int row, int cols){
    int maximum = INT_MIN;
    for(int i =0;i<row;i++){
        for(int j=0;j<cols;j++){
            if(array[i][j] > maximum){
                maximum = array[i][j]; //if array current element if > max then assign that to max
            }
        }
    }
    return maximum;
}

int find_min(int array[3][4], int row, int cols){
    int mini = INT_MAX;
    for(int i =0;i<row;i++){
        for(int j=0;j<cols;j++){
            if(array[i][j] < mini){
                mini = array[i][j]; //if array current element if > max then assign that to max
            }
        }
    }
    return mini;
}

int main(){
    int array[3][4];
    int row =3;
    int cols = 4;

    // Take user input to create the array.
    cout<<"Enter the array elements : "<<endl;
    for(int i =0;i<row;i++){
        for(int j=0;j<cols;j++){
            cin>>array[i][j];
        }
    }

    // Just call the function 
    cout<<"The maximum number from an array is : "<<find_max(array,3,4)<<endl;
    cout<<"The minimum number from an array is : "<<find_min(array,3,4)<<endl;
}