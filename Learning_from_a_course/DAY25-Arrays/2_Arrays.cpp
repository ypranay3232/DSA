/* Lets do some exercises :

1) Take 5 elements input in array and print their doubles !

We can do it as : first we declare an array with size 5
Then we loop i<5 i++ then we take user input values to array and then we print (i*2) so we get double values

*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // int array[5];
    // cout<<"Enter the array values : "<<endl;
    // for(int i =0 ; i<5;i++){
    //     cin>>array[i];
    //     cout<<array[i]*2<<endl;
    // }

    // // We can also do in this way !
    // int arr[500];
    // int n;
    // // Taking size of array from user
    // cout << "How many numbers you want to add into array : " << endl;
    // cin >> n;

    // // Now take input from user
    // cout << "Enter the values : " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // // now after taking inputs we print them as doubles :

    // for (int i = 0; i < n; i++)
    // {
    //     cout << 2 * arr[i] << " ";
    // }

    // Lets say we have an array : and we want to replace all elements with somevalue :

    int array1[5] = {1, 3, 5, 7, 9};

    // We have two approaches 1) to traverse through array and assign the array values with something(ex: 1)
    // 2) approach is to use a std::fill header file function
    for (int i = 0; i < 5; i++)
    {
        array1[i] = 1;
    }
    // then print the array
    for (int i = 0; i < 5; i++)
    {
        cout << array1[i];
    }

    // trying 2nd approach : use std::fill(std::begin(aray), std::end(array), what number you want to set)
    int array10[5] = {2, 8, 4, 2, 2};
    std::fill(std::begin(array10), std::end(array10), 3);

    // now print the array
    for (int i = 0; i < 5; i++)
    {
        cout << array10[i];
    }

    // What happens when we create an array with size 10 and provide values only 1,2 what happens to remaining 8
    //  it returns 0. because when we start assigning values to an array it fills the empty memory with 0's so we can add values in future But if we don't provide any values just declaration is done then it stores or returns garbage values

    int array2[10] = {1, 2};
    for (int i = 0; i < 10; i++)
    {
        cout << array2[i] << "\n";
    }

    int array3[10];
    for (int i = 0; i < 10; i++)
    {
        cout << array3[i] << "\n";
    }
}
