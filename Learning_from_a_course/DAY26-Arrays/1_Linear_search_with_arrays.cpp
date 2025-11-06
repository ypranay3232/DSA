/* Linear search : is one of the simplest searching algorithm used to find the largest number in an array, it checks each element one by one until it finds the target or reaches the end of array

Lets try to implement this !
first we create an array and its size so we can pass it to functions, now we take key input from user
now we create an index variable to find the position and assign it to function.

now we create a function that loops the array and checks if array elements are equal to key or not array[i] == key if found returns the number(i) else returns -1

and we check the condition with an if condition
(if(index !=1) cout<<element found at index<<index; else <<not found)

*/

#include <iostream>
using namespace std;

int find_key(int array[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            return i;
            break;
        }
    }
    return -1;
}

int main()
{
    // first create an array and also its size to pass with functions !

    int array[] = {
        1,
        53,
        4,
        23,
        54,
    };
    int size = 5;

    cout << "Enter the Key element to find : ";
    int key;
    cin >> key;
    int index = find_key(array, size, key);
    if (index != -1)
    {
        cout << "Found at index : " << index << endl;
    }
    else
    {
        cout << "Not found ! " << endl;
    }
}