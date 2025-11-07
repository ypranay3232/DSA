/* Finding maximum number of an array ! To find max number we do the same linear search

After finding max now find minimum number too 

*/
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int array[] = {2, 1, 423, 34, 22, 323, 654, 1, 5234, 12, 42, 534, 7798, 5, 676};
    int size = 15;

    // NOW initialize max number to = INT_MIN (because its a best practise rather than assiging 0)
    int Max_num = INT_MIN;
    int min_num = INT_MAX;
    // Now make a for loop to traverse thorugh the array and if array first element is greater than maxnum(which is minimum int) yes so now assign the max_num with array first element then compare with 2nd if greater exchange and repeat.
    for (int i = 0; i < size; i++)
    {

        if (array[i] > Max_num)
        {
            Max_num = array[i];
        }
                if(array[i]< min_num){
            min_num = array[i];
        }
    }

    cout << "The Maximum number is : " << Max_num << "\n";
    cout << "The Minimum number is : " << min_num << "\n";
}