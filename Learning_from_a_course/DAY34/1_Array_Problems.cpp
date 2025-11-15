/* Move all negative elements to left side of an array  

we have two ways 1) use the sort() Time : O(n log) space : o(n)
2)use DNF algorithm : Time : O(n) space : O(1)

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> arr = {0,29,-10,12,16,4,-3,-12,-19,24,32,13,5,-3,-7};
    sort(arr.begin(), arr.end());//This is a navie brute force approach ! 

    for(int x : arr) cout<<x<<" ";
    cout<<endl;

    // we use DNF algorithm (Dutch national flag) Two pointer approach ! 
    // The idea is very simple we maintain two pointers (left and right) both point to start and ending of an array and we Left until it becomes positive (>0), if right > 0 we decrement and go to next index.  so we leave positive on right side. (.i.e. if not a -ve number on left and not a +ve number on right) then we swap left and right so Both get their desired values. (so left get -ve and right get +ve)

    vector<int> arr1 = {1,2,-3,4,-5,6};
    int left =0;
    int right = arr1.size()-1;

    // Tranverse through the array until left becomes less than or equal to right 
    while(left<=right){
        // check condition if left < 0 increment  until you find a positive number
        if(arr1[left]<0){
            left++;//so we keep all negative numbers a side
        }
        // second case : if right side is greater than or equal to 0 then decrement it until it becomes 0 
        else if (arr1[right]>=0){
            right --;
        }
        // Third condition : if left is not less than 0 (means positive num) and right is not greater than 0 means (-ve number ) we swap both so left gets its negative number and right gets its positive number. 
        else{
            swap(arr1[left], arr1[right]);
            left ++; // so left can move to next index
            right --; // so right can decrement to next index
        }
    }
    for(int x : arr1) cout<<x<<" ";
}