/* We have a better way to convert the Decimal number system to Binary !

*/

#include <iostream>
#include <cmath>
using namespace std;

int DecimaltoBinary(int n)
{
    // Division method, Here we have to divide the number until its < 2
    int binaryno = 0;
    // here we remove i and add 'Place variable' and we multiply that with our current bits + binaryno. Then we move its position til 10
    int place = 1;
    while (n > 0)
    {
        int bit = (n &1);//to get last bit in order

        // It's same as division method the only change is instead of divison we add &1 to the N. and then we shift one bit to right hand side.
        binaryno = bit*place + binaryno;
        place *= 10;//moves to next decimal place
        n = n >> 1; // right shift
    }
    return binaryno;
}
int main()
{
    int n;
    cout << "Enther the value of N : " << endl;
    cin >> n;

    int binary_val = DecimaltoBinary(n);
    cout << "The entered number " << n << " Binary value is : " << binary_val << endl;
}