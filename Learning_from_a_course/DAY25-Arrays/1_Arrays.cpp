/* What is  an array ?
An Array is a Linear Data Structure that contains a continious Memory it Holds similar data elements

How does it store in Memory : array = [1,2,3,4,5]
Integer size = 4 Bytes so it takes 4*5 = 20 bytes, And it stores in continous memory order

Why we need Arrays ?

Assume that we want to find the maximum of 3 numbers we declare and do a if else condition but what 
// about 300,3000,30,000 etc. (.i.e. as the input numbers increases we need a way to store so we use arrays)

Ex: int array[30000];
This creates a memory space of 30,000(we made 30,000 memory space without declaring the variables)

how to create an array ?
int array[20];

now in symbol table the variable is assigned to a X address and then that address is assigned to the value
(.i.e. array is assigned to 102, so the Value of array which is 20 is kept inside 102)

when we print it the compiler checks for the variable then goes thorugh the address and find the value

*/

#include <iostream>
using namespace std;

int main()
{
    // Declaration of arrays
    int array[5];
    cout << "The array is : " << array << endl;

    int arr1[53];
    cout << "The integer array is : " << arr1 << endl;

    // Why this Doesn't print anything is because for character : Cout has a special overload (char*)
    // it assumes it's a c-string. It assumes to print every character in memory until it finds a
    //  null terminator('\0') Because the array is uninitialized (not assigned any values)
    //  it contains garbage values (so garbage value may be found out as 0X3491 so it stopped printing)

    // (.i.e. when a char aray is passed it points to char* pointer the ostream overload 
    // for char* treats it as a null terminated ('\0') c-string. since array is uninitialized 
    // it contains garbage values so it prints nothing)
    char array2[166] = {};
    // for verification we see the address if its starting with 0 then it's not going to print
    cout << "The address of char is : " << &array2 << "Because its starting with 0, not going to print" << endl;
    cout << "The character array is : " << array2 << endl;

    bool array3[23] = {};
    cout << "The Boolean array is : " << array3 << endl;

    // Array initializatin : can be done in two ways 1)create an array and dynamically add values to it
    //  2)define an array ize and add values according to the size.
    int Arr_ini[] = {1, 2, 3, 4, 5, 6, 7};
    cout << "Array initialized " << Arr_ini << endl;

    int arr_ini1[5] = {2, 34, 56, 32, 4};
    cout << arr_ini1 << endl;

    // Index and acessing array using index :
    int size[5] = {1, 2, 3, 4, 5};
    cout << size; // returns only address of the aray to access arrays we use indexing

    /* indexing : The indexing always starts with 0. ex: [1,2,3,4,5]
    so they aRe stored in continous memory location starting from 200

    1 = 200 ==>  the address 200 holds the value of 1
    2 = 204 ==>  the address 204 holds the value of 2
    3 = 208 ==>  the address 208 holds the value of 3
    4 = 212 ==>  the address 212 holds the value of 4
    5 = 216 ==>  the address 216 holds the value of 5

    So the formula becomes :
    Arr + index * datatype size
    200 + 0*4 = 200
    200 + 1*4 = 204
    200 + 2*4 = 208
    200 + 3*4 = 212
    200 + 4*4 = 216

    This is how the address is calculated in memory.    */

    int arr_init[] = {1, 2, 3};
    cout << "The array value is : " << arr_init[0] << endl;
    // Now printing all values from an array we use loop
    for (int i = 0; i < 3; i++)
    {
        cout << arr_init[i] << " ";
    }

    return 0;
}