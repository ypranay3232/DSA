// check if a given number is prime or not ! A prime number has two factors 1) it is divided by 1 and 2) it is divided by N(.i.e. itself)

#include <iostream>
using namespace std;

// Works as : first we create a function that takes an parameter 'n' and we start from 2, because a prime number is a number greater than 1 and that is divisible by 1. so we start from 2. and increment til <n. if any number(n) %i == 0 return false. not prime. if % i ==1 then return true. lllllll


// The loop doesn’t need to run till n−1.
// It’s enough to check till √n, because:
/*
If a number has a divisor larger than √n, then the corresponding smaller divisor would have been found.

The i*i means square root, as per maths : once you reach square root, then you have checked every possible divisior pair. ex: n = 36 so 
1 * 36
2 * 18
3 * 12
4 * 9
6 * 6 
9 * 4
12 * 3
18 * 2
36 * 1

so the pairs after 6 * 6 repeat (9,12,18,36) repeat 



*/ 
bool checkprime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i*i <=n; i++)
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
    cout << "Enter a number : " << endl;
    cin >> n;

    bool isprime = checkprime(n);
    if (isprime)
    {
        cout << "prime\n";
    }
    else
    {
        cout << "not prime \n"
             << endl;
    }
}