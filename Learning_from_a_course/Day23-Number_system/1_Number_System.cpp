/* What is a number system ?

A number system is a method to represent numeric values using different digits

Types of number systems :

1) decimal numbers system : COntains a Base 10(i.e. it is the no of symbols we use in the system), uses numbers from 0-9

2) Binary Number system : Uses base 2 and Contains only 0 and 1.
Because The computer only uses binary language : ex: the cpu contains some grids : and inside it we define something as (1010111)  --> 0 = power off and 1 == Power on.


Decimal to binary conversion :
Step1 : divide the number by 2
Step2 : Store Reminder (the reminder is a bit for binary number)
Step3: Repeat until Quotient < 2.
Step4: Reverse the Bits

Ex: N = 10

Calculation   Dividend	Divisor	  Remainder   Quotient
10 / 2	        10      	2		0           5
5 / 2	        5       	2		1           2
2 / 2       	2	        2		0           1
1 / 2	        1	        2		1           0

Now we read the reminder from bottom to top : which becomes (1010)2 is the binary representation for 10 in memory
Let's code it !

*/

#include <iostream>
#include <cmath>
using namespace std;

int Decimal_to_Binary(int n)
{
    // Division method, Here we have to divide the number until its < 2
    int binaryno = 0;
    int i = 0;
    while (n > 0)
    {
        int bit = n % 2;

        // cout<<bit<<endl;

        // Now we have to represent the values in reverse ! so to do it we do as : we take the number and
        // 0 --> 0 * 10(power 0) + 0 = 0
        // 1 --> 1 * 10(power 1) + 0 = 10(the 10 values comes to vottom)
        // 0 --> 0 * 10(power 2) + 10 = 10(same so becomes 1010)
        // 1 --> 1 * 10(power 3) + 10 = 1010

        // we do it as first create a variable 'binaryno' then take the current bit(.i.e which is 0) and we multiply it with 10 to power i(0) + i(0) so we get 0. and we incrementit for next iteration

        // Formula = answer = (digit*10 power(i))+answer
        
        binaryno = bit * pow(10, i++) + binaryno;
        n = n / 2;
    }
    return binaryno;
}
int main()
{
    int n;
    cout << "Enther the value of N : " << endl;
    cin >> n;

    int binary_val = Decimal_to_Binary(n);
    cout << "The entered number " << n << " Binary value is : " << binary_val << endl;
}