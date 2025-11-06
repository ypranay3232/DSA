/* Lets see how to use functions with arrays ! 

Let's check pass by value and refernce ! if the value of original array gets updated its pass by refernce if 
the copy gets updated its pass by value (.i.e. making copy) 


*/

#include<iostream>
using namespace std;

// Always remember while passing an array to a function always pass its size, so that we can print exact values and avoid garbage values or zeroes.
void printarr(int arr[], int size){
    for(int i =0;i<size;i++){
        cout<<arr[i]<<" "; 
    }
    cout<<endl;
}

void inc(int arr[], int size){
    arr[0] = arr[0] + 10;
    printarr(arr, size);
}

int main(){
    // made an array with values 5,6 then called a function inc(passed an array and its size)
    int arr[] = {5,6};
    int size = 2;
    inc(arr,size);//now it increments array index 0 + 10 = 15 and returns the value so (15,6)

    printarr(arr, size);//but the printarr which prints the array also returning (15,6) it should return (5,6) so the original value got updated.

    // Remember : In c++ everything is pass by value but what you pass can be a value or an address(pointer) when you pass an array to a function, you are passing the address of arrays first index address not a copy of array. so the function dont get a copy of array it gets address so it makes changes to it and returns the same address which is passed down to it.
}