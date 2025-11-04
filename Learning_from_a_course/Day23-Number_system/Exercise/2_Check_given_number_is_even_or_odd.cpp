#include <iostream>
using namespace std;

bool is_even_or_odd(int n)
{
    // if(n % 2 ==0){
    // There is another method to do this : we use bitwise operators : as we know 5 --> 0000101 and 4 --> 100 so in memory even numbers are stored ending with 0's and odd numbers stored with 1. so we compare both (n & 1) it checks bits of n and 1 if (n ==1 and 1 ) both are equal then we can say that 1. so 1 is even and 0 is false.

    // we use this method because its fast and (Modulous opeartor %) takes so much processing power so try to avoid using it as much as possible
    if ((n && 1) == 0)
    {

        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cout << "Enter a number to check if it is even or odd : " << endl;
    cin >> n;

    bool checker = is_even_or_odd(n);

    if (is_even_or_odd)
    {
        cout << "Entered Number is even" << endl;
    }
    else
    {
        cout << "Entered Numbere is odd number" << endl;
    }
}