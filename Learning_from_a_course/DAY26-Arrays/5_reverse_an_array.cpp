/*Reverse an array : Create two variables start and end swap both vales and increment

*/
#include<iostream>
using namespace std;

int main(){
    int array[] = {10,20,30,40,50,60,70,80,90,100};
    int size = 10;

    int start = 0;
    int end = size-1;

    while (start<=end)
    {
        // use swap funcntion and swap start with end and increment start and decrement end
        swap(array[start], array[end]);
        start++;
        end--;

    }
    // now print the array
    for(int i =0; i<size;i++){
        cout<<array[i]<<" ";
    }
}