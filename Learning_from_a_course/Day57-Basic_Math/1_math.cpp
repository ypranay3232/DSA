/* Basic mathematics for DSA : 

1) Prime number : we have multiple approaches to solve this question 

--> a prime number is a number which returns 0 its not a prime else its a prime ! prime == has only 2 factors, (.i.e. can be divisible by 1 and itself (1,n) but one is not a prime number because it's not divisible with other numbers, so the smallest prime number is 2.)

1) Naive Approach : we do as we do a for loop : to check 0-10  if(n%i) ==0 not prime else prime

-->LeetCode 204 : count primes : given n numbers return primes that are less than N ! 
    bool isprime(int n){
        if(n<=1) return false;
        for(int i = 2;i<n;i++){
            if(n%i ==0){
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        int c =0;
        for(int i =0;i<n;i++){
            if(isprime(i)){
                ++c;
            }
        }
        return c;
    }
This breaks because of time complexity : 
normal prime calculation TC = O(N) --> we are looping till N numbers and
we are using 2 loops : 1 inside count prime() another inside isprime(), O(n) 

Overall TC = O(n^2)

2) Approach : sqrt N : The core idea is The factor (N) always comes in pairs 
ex: 36 (6 *6) a pair and Sqrt(N) 
--> instead of running the code upto i<n we make make it as : i * i <= N

        bool isprime(int n){
        if(n<=1) return false;
        for(int i = 2;i*i <=n ;i++){
            if(n%i ==0){
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        int c =0;
        for(int i =0;i<n;i++){
            if(isprime(i)){
                ++c;
            }
        }
        return c;
    }


Time Complexity : O(Sqrt N) better than approach 1 


3) sieve of Eratosthemes : Used this method to count prime numbers between 0 - N
Approach : s1) mark all numbers as prime(true) and remove 1, Nth element because 1 is non prime and we have to return n-1 element.
if we check any prime number the number Table returns non prime numbers ex: 2 
2,4,6,8 --> all are non prime numbers ! so mark these numbers as False  

Algorithm : 
start from 2 to n-1, mark all array numbers as prime.
from 2 to end, mark all numbers which occurs in table of 2 as non prime repeat til n-1
we get prime numbers 
count the prime numbers.

int countPrimes(int n) {
        if(n == 0) return false;

        vector<bool>isprime(n,true);//marking all numbers as prime

        isprime[0] = isprime[1] = false;//0 and 1 are not prime so false

        int ans = 0;
        for(int i = 2;i*i<n;i++){
            // if p is still marked true, its a prime
            if(isprime[i]){
                // mark the multiples of p. (2) from i*i as false
                for(int j = i*i;j<n;j+=i){
                    isprime[j] = false;
                } 
            }
        }

        int count = 0;//to count the remaining trues in array
        for(int i = 2; i<n;i++){
            if(isprime[i]) count++;
        }
        return count;
    }
TC = O(N log log N)

4) segmented sieve: If you want to find primes up to $10^{10}$, a vector<bool> would require roughly 1.25 GB of RAM. If you go higher, your computer will simply run out of memory. so we use Segmented sieve

The Segmented Sieve solves this by breaking the range $[0, n]$ into small blocks (segments).
-->this is the same TC as sieve of Eratosthemes, but space complexity is O(Sqrt N)


*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void segmentedSieve(long long n) {
    // 1. Find the square root of n
    int limit = floor(sqrt(n)) + 1;
    vector<int> basePrimes;
    
    // 2. Standard Sieve to find primes up to sqrt(n)
    vector<bool> mark(limit + 1, true);
    for (int p = 2; p * p <= limit; p++) {
        if (mark[p]) {
            for (int i = p * p; i <= limit; i += p)
                mark[i] = false;
        }
    }
    
    cout << "Primes in the first segment: ";
    for (int p = 2; p <= limit; p++) {
        if (mark[p]) {
            basePrimes.push_back(p);
            if(p < n) cout << p << " "; // Print initial primes
        }
    }

    // 3. Define segments
    long long low = limit;
    long long high = 2 * limit;

    while (low < n) {
        if (high > n) high = n;

        // isPrime[i] represents (low + i)
        vector<bool> isPrime(high - low + 1, true);

        for (int p : basePrimes) {
            // Find the smallest multiple of p in [low, high]
            long long start = (low / p) * p;
            if (start < low) start += p;
            
            // If start is the prime itself, move to the next multiple
            if (start == p) start += p;

            for (long long j = start; j < high; j += p) {
                isPrime[j - low] = false;
            }
        }

        // Print primes in current segment
        for (long long i = low; i < high; i++) {
            if (isPrime[i - low]) cout << i << " ";
        }

        // Move to the next segment
        low = low + limit;
        high = high + limit;
    }
    cout << endl;
}

int main() {
    long long n;
    cout << "Enter the limit to find primes up to: ";
    cin >> n;

    if (n < 2) {
        cout << "No primes below 2." << endl;
    } else {
        segmentedSieve(n);
    }

    return 0;
}