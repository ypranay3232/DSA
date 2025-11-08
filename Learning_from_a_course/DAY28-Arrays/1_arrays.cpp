#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Vector initialization :

    // now let's create an array explicitly and fix the values of the array
    vector<int> array(10, -1); // the 2nd argument will set the values to : -1
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }

    // Now lets say we tak dynamic input form user
    int n;
    cout << "Enter the value of n : " << endl;
    cin >> n;
    vector<int> array1(n, -1);

    for (int i = 0; i < array1.size(); i++)
    {
        cout << array1[i] <<" ";
    }
    cout<<endl;

    // we can also predefine the values :
    vector<int> array2{10, 20, 30, 40, 50};
    for (int i = 0; i < array2.size(); i++)
    {
        cout << array2[i] << " ";
    }

    // Check if a vector is empty or not ! we use empty() it returns bool values (0,1)
    cout<<" checking if an vector is empty or not : "<<array2.empty()<<endl;
}