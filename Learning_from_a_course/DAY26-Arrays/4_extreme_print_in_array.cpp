/* This approach is also called as two pointers !
here we have an array and we print the first element and we print last element and we print 2nd element and we print last 2nd element.


So the raw idea i have is we create two variables and we ++ and -- them by assiging array[0] = first and array-1 and we -- it

*/

#include <iostream>
using namespace std;

int main()
{
    // create an array
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
    int size = 11;

    // Create two variables start and end, where start point to starting index and end point to last index

    int start = 0;
    int end = size - 1;

    // add the condition if start > end break because they both has surpassed each other and can print duplicates
    while (true)
    {
        if (start > end)
        {
            break;
        }
        // here we have a catch if the size of array is odd we get the last value printed twice, because both start and end point to same number at end, so lets add a condition, where if start == end we print only start, (so we get only one value printed)
        if (start == end)
        {
            cout << array[start] << " ";
        }
        else
        {
            // now print the starting and ending values and increment and decrement them.
            cout << array[start] << " ";
            cout << array[end] << " ";
        }

        start++;
        end--;
    }
}
