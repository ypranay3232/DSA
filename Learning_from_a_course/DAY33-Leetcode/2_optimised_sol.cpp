/* The optimised solution for sorting moving all negative numbers to positive : we use (Dutch National flag)

It is called as dutch algorithm because its named after the Dutch flag (3 horizontal lines) which is of three way partitioning. (.i.e. using 3 pointers commonly used to seperate 0's,1's,2's)

so we use the same here. what we do is : we use a pointer 'j' and initialise it starting with 0. and all elements which are less than 'j' are negative so we can sort them as negative and we use 'i' to iterate through the array and we check if the condition is (arr[i]<0) then we swap the numbers with 'j' and we increment 
*/
#include<iostream>
#include<vector>

using namespace std;

// here we pass a vector and array to the function 
void mov_to_neg(vector<int>&arr){
    int j=0; //to initiate if all elements are <j (.i.e. negative numbers shall be placed here)
    for(int i =0;i<arr.size();i++){
        // now check the condition if (arrays current element which is arr[i] <0) means -ve nums so swap them with arr[j] and increment j. so it can move to next index.
        if(arr[i]<0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main(){
    vector<int> arr = {-3,5,-1,10,-2,0,-8,2,7,-7,-1,3};

    // create a function that move all negative nums to left. And print the array
    for(int x: arr) cout<<x<<" ";
    cout<<"\n";
    return 0;
}