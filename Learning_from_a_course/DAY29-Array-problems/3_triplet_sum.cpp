/* here we need to find the Target number/sum using 3 numbers
simple use 3 loops for brute force approach ! Complexity is O(n^3) because we are using 3 loops
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    int target = 100;

    for(int i =0;i<arr.size();i++){
        for(int j =i+1;j<arr.size();j++){
            for(int k=j+1;k<arr.size();k++){
                // now check the condition if arri,j,k == target then print the pairs 
                if(arr[i] + arr[j] + arr[k] == target){
                    cout<<"("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<")"<<endl;//prints every possible pair But if we want only in order not to repeat any then we can do it as : j = i+1, k = j+1 so we dont repeat the array and we skip to i+1 th position. But if you want all the possible pairs you can use i=0,j=0,k=0
                }
            }
        }
    }
    
}