/*
What if you were asked to solve a pair sum with given a single array ! 
it's easy we can do it as : we create two loops and we check condition

Complexity : O(n*m) or O(n+m) because used two loops

*/
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main(){
    vector<int> array = {10,20,30,40,60,70};
    int Target = 100;

    // now we loop through it 

    // for(int i =0; i<array.size();i++){
    //     for(int j =0;j<array.size();j++){
    //         // now check the condition 
    //         if(array[i] + array[j] == Target){
    //             cout<<"("<<array[i]<<","<<array[j]<<")"<<endl;
    //         } 
    //     }
    // }

    // Now lets see the optimal solution using a hashmap lets create a set
    unordered_set<int> s;
    // now we loop through the array 
    for(int num : array){
        // the B value checks Target - current ele from array so what element we might need to get the Target
        int b = Target - num;
        // now chek condition if(set.find(b) != s.end()) is not in array then we print that number and b
        if(s.find(b) != s.end()){
            cout<<"("<<num<<","<<b<<")"<<endl;
        }
        s.insert(num);
        // output will be as (60,40) and (70,30) not 30,70 and 40,60 because while using sets it removes duplicates
    }
}