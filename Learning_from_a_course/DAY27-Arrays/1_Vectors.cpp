/* A vector is a dynamic array whose size is not fixed !

How to create a vector :

vector<type> name_of_vectior

Ex: vector<int> arr;

As the elements gets filled vector doubles it's size

initialize vector : vector<int> arr(10,20,40);


vector<int>arr(10,-1); --> this creates a vector of 10 and fills all with -1.

creatomg a dynamic array amd to imsert elements we use arr.push_back(); and to remove arr.pop_back();
we have a lot of functions that can ge applied here : .empty(); .size();
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // array craetiom
    vector<int> arr;

    cout << arr.size() << endl;     // returns size of array (.i.e. Total elements we stored till now in memory)
    cout << arr.capacity() << endl; // returns no of elements that can be held in currently allocated storage(.i.e. Total storage of an array )

    // The size is showing zero but that is not ture right ?
    int ans = (sizeof(arr) / sizeof(int));
    cout << ans << endl;

    // inserting elements into array
    arr.push_back(5);
    arr.push_back(15);

    // Now lets print it !
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // To remove elements we use pop_back() it removes recently inserted elements
    arr.pop_back();

    // Now lets print it !
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    // Now lets try to declare an vetor array values explicitly
    vector<int> arr1(10);
    // now lets check its values !
    cout<<"size of array is : "<<arr1.size()<<endl;
    cout<<"Capacity of array is : "<<arr1.capacity()<<endl;

    // Both are 10. becasue once we explicitly mention size of a vector that size is fixed.
    
    // lets try to print the 10 size values 
    for(int i =0;i<arr1.size();i++){
        cout<<arr1[i]<<" ";

    }
    
    return 0;
}