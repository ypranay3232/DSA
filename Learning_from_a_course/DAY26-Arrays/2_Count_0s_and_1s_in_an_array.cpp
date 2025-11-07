/* Assume an array containing 0's and 1's count o's and 1's

*/
#include <iostream>
using namespace std;

int main()
{
    // create an array with 0's and 1's and create array size
    int array[] = {0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0,3,5,2,5,3};
    int size = 20;

    // The starting  count will be zero for both 0's amd 1's
    int starting_zero = 0;
    int starting_one = 0;
    // Now lets traverse the array

    for (int i = 0; i < size; i++)
    {
        // now we check if array current element is 0 we increment the count of 0 else if current element == 1
        if (array[i] == 0)
        {
            starting_zero++;
        }
        else if(array[i]==1){
            starting_one++;
        }
    }

    cout << "Number of zeroes are : " << starting_zero << "\n";
    cout << "Number of ones are : " << starting_one << "\n";
}