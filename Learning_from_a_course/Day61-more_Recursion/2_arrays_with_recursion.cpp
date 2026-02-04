#include <iostream>
using namespace std;

void recursion_printer(int arr[],int n, int i){
    // base case : if i >= n (out of index)  
    if(i >=n){
        return;
    }

    // print condition : 
    cout<<arr[i]<<" ";

    // recursion case : 
    recursion_printer(arr, n , i+1);
}


int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int i =0;
    int n = 5;
    // we usually print an array with for loop as :

    // // for (int i = 0; i < 5; i++){
    // for (int i = 0; i < size(arr); i++){
    // {
    //     cout << arr[i]<<" ";
    // }

    // printing with recursion 
    recursion_printer(arr,n,i);
    return 0;
}
