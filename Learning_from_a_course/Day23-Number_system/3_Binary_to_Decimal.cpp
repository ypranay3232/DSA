/* Binary to Decimal : It works as
step1 : Multiply each digit with its place value.
step2 : add up all the space values.
step3 : sum the decimal values.


*/

#include <iostream>
using namespace std;

int BinartoDecimal(int n)
{
    int decimal = 0;
    int i = 0;
    while (n)
    {
        int bit = n % 10;
        decimal = decimal + bit * (1 << i++);// bit * 2^i
        n /= 10;
    }
    return decimal;
}

int main()
{
    int binarynum;
    cout << "Enter the Binary number : " << endl;
    cin >> binarynum;
    cout << BinartoDecimal(binarynum) << endl;
}