/*
Assume we have two arays : array1 and array2. union both arrays and store result

create an result array
put elements of array1 into result array
put elements of array2 into result array
end

*/
#include <iostream>
#include <vector>
#include<set>
#include<unordered_set>
using namespace std;

int main()
{
    // // create two arrays with size defined because while working on arrays its necessary to know the size of array 
    // int array1[] = {2, 4, 6, 8};
    // int sizea = 5;
    // int array2[] = {1, 3, 5, 7};
    // int sizeb = 5;

    // // Now create a result array
    // vector<int> res;

    // // push elements of array1 into result
    // for (int i = 0; i < sizea; i++)
    // {
    //     res.push_back(array1[i]);
    // }

    // // push elements of array2 into result 
    // for(int i =0; i<sizeb; i++){
    //     res.push_back(array2[i]);
    // }

    // // now print the array 
    // cout<<"The array elements are : "<<endl;
    // for(int i = 0 ; i<res.size();i++){
    //     cout<<res[i]<<" ";
    // }

    // cout<<" -----------------------------"<<endl;




    // We can have some varaiations in this problem such as sorting the array in ascending order and removing duplicates etc. so lets see them 

    /* 1) sorting and removing duplications  O(n+m) -->space complexity and O(n+m)*log(n+m) time complexity
    To do so we need to use Set (set is a Data Structure that store elements in sorted order without duplicates)    */

    // // creating 2 arrays with duplicate values  
    // vector<int> arr1 = {1,2,5,8,6,8,10};
    // vector<int> arr2 = {3,5,7,4,8,9,10};

    // // create result vector 
    // set<int> res;

    // // insert arr1 values into result
    // for(int i : arr1) res.insert(i);
    // for(int i : arr2) res.insert(i);

    // // now print 
    // cout<<"The union of two arrays are : "<<endl;
    // for(int val: res)cout<<val<<" ";


    // But This is also not an optimal solution O(n): is to use an unordered_set

    vector<int> arr1 = {2, 5, 8, 8, 10};
    vector<int> arr2 = {1, 5, 7, 8, 9};

    unordered_set<int> result;

    for (int i : arr1) result.insert(i);
    for (int i : arr2) result.insert(i);

    cout << "Union (unordered): ";
    for (int val : result) cout << val << " ";

    return 0;
}
