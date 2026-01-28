// Greatest common divisior/ Highest common factor. (.i.e. HCF is a number which divides both a,b and returns 0)

// FOrmula : To find GCD(a,b) = gcd(a-b,b) when a>b if a<b gcd(b-a,a)
// we do GCD until we get a 0. we follow it as : ex: (72,,24) ==> a>b so (a-b,b) formula
// (72,42) ==> (72-24,24) = (48,24) ==> (48-24,24) ==>(24,24) --> (0,24)

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }

    return (a == 0) ? b : a;
}

int main()
{
    int a = 72;
    int b = 24;

    cout << "GCD is: " << gcd(a, b) << endl;
    return 0;
}