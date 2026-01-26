// First create an array and access the value by index then get the index address
#include<iostream>
using namespace std;

int main(){
    int arr[] = {10,20,30,4,4,32,132,64};
    cout<<"The Index 3 value is : "<<arr[2]<<endl;
    cout<<"The address of index 3 is "<<&arr[2]<<endl;
    
    // Task : what will be the address of the array ? 
    cout<<"The address of array is : "<<&arr<<endl;
    // It's the base address (.i.e the first index address will be pointed and returned)
    cout<<"The first index address is : "<<&arr[0]<<endl;

    // internal working : when we create an array named arr[10] inside symbol table : arr --> pointing to some address called base address. 


    // In simple terms * prints value and & prints address 
    cout<<*arr<<endl;//Prints the first value 
    cout<<*arr+1<<endl;//Prints value (10) + 1 = 11. To print the next index we have to add braces 
    cout<<*(arr + 1)<<endl; 

    // we have an operator called sizeof() which returns memory occupied by array in bytes : array contains 8 elements and int = 4 bytes (4 * 8 = 32) 
    cout<<sizeof(arr)<<endl;//Total Size = no of elements * sizeof(int)
    cout<<"--------------------------------------------------";
    // printing an array with for loop 
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
    
}