// Printing all prime numbers !

#include <iostream>
using namespace std;

// we just need to check prime numbers are not if true yes false not prime

bool isprime(int n)
{
    int i = 2;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {

        bool checker = isprime(i);
        if (checker)
        {
            cout << i << " ";
        }
    }
}