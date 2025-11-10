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
        for(int j =0;j<arr.size();j++){
            for(int k=0;k<arr.size();k++){
                // now check the condition if arri,j,k == target then print the pairs 
                if(arr[i] + arr[j] + arr[k] == target){
                    cout<<"("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<")"<<endl;
                }
            }
        }
    }
    
}