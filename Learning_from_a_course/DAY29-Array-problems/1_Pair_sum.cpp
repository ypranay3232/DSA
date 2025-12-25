/* Most commonly asked in interviews :
Given two arrays array1 = {1,3,5,7}, array2 = {2,4,6} and given a sum = 9.
Now find a pair that upon addition gives values equal to sum


For now lets understand the pattern then we jump into solving this with n arrays.

ex: we have an array = {10,20,30,40,60,70}

The brute force approach is : we take an element (and check it with every other element) (.i.e. make pairs)
so it will be as
(10,20), (10,30), (10,40), (10,60), (10,70)
(20,30),(20,40),(20,60),(20,70)
(30,40),(30,60),(30,70)
(40,60),(40,70)
(60,70)

*/
#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;

int main()
{
    // first create an array
    vector<int> array1 = {1, 3, 5, 7};
    vector<int> array2 = {2, 4, 6};
    int sum = 9;

    // now print all pairs so : create an outer loop that takes an element and traverse through each element of array : Time complexity is : O(n*m)

    for (int i = 0; i < array1.size(); i++)
    {
        // now inner loop that will traverse through the array from array element+1, so we get that pairs
        for (int j =0; j < array2.size(); j++)
        {
            if (array1[i] + array2[j] == sum)
            {
                cout << "(" << array1[i] << "," << array2[j] << ")" << endl;
            }
        }
    }

    cout<<"=======================================";

    // Now let's see the optimized solution : 
    // We don't want to check every possible element it takes a lot of time, so we want to know instantly whether a number exists in second array can form target sum with first array. so we use hashing because lookingup into a hash table is O(1)--> 

    // first we load the array2 into the set 's' --> set ? because searching is very fast

    unordered_set<int> s(array2.begin(), array2.end());
    // now take each element from array1 and calculate "what number we need from array2 to reach sum"
    for(int a : array1){
        int b = sum -a;
        // ex: a = 1, so int b = sum -a checks as : b = 9-1 = 8. we need 8 at array2. and move to next if 9-3 = 6 is present in arr2 so print that 6 and 3 as output.
        // now we check that the 'b value (8)' is present in hashset or not ? 
        if(s.find(b) != s.end()){
            // if present 
            cout<<"("<<a<<","<<b<<")"<<endl;
        }
        
    }



}