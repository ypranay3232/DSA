/* Moving all negative numbers to left side ! irrespective of order.

ex: given an array = {-3,5,-1,10,-2,0,-8,2,7,-7,-1,3}

so the output should be as : {-3,-1,-2,-8,-7,-1,0,5,10,2,7} order can vary

we can solve it in both ways first is to use a sort() from algorithm library
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr;
    int no_of_ele;
    // first lets create a vector and take user input and ask how many elements a user need
    cout << "enter the number of elements you want to insert : " << endl;
    cin >> no_of_ele;

    // taking input elements and pushing back them into array.
    cout << "enter the elements  : " << endl;
    for (int i = 0; i < no_of_ele; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    // now print the array
    cout << "the elements are : " << endl;
    for (int n : arr)
    {
        // use the sort() function and print the array
        sort(arr.begin(), arr.end());
        cout<<n<<" ";
    }
    cout << endl;

    return 0;
}
