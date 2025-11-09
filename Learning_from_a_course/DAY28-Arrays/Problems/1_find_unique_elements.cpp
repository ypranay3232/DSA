// important question for companies : Find unique elements from an array.

// The core funda of the pattern is : To find the element which occurs only once (.i.e. element which is least repeated)

#include <iostream>
#include <vector>
using namespace std;

int findUnique(vector<int> array)
{
    int ans = 0;
    for (int i = 0; i < array.size(); i++)
    {
        ans = ans ^ array[i];
    } 
    return ans;
}

int main()
{
    // Observe the pattern most elements are repeating except 3. so how to find and print it ! we have an operator called Xor(^) --> it returns 0 if different else 1. so : ex :     vector<int> array1{1, 2, 4, 2, 1, 3, 6, 5, 5, 6, 4};

    // finding unique elmenet
    int n;
    cout << "enter the Array size : " << endl;
    cin >> n;

    vector<int> array(n);
    cout << "enter the array elements : " << endl;
    for (int i = 0; i < array.size(); i++)
    {
        cin >> array[i];
    }

    // now lets create a function named indUnique()
    int unique_elements = findUnique(array);
    cout << "The unique id element is : " << unique_elements << endl;

    return 0;
}