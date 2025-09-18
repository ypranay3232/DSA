#include <iostream>
using namespace std;

int main()
{
    // resuming the exercises !

    // exercise : print the factorial of any number.

    // what is factorial its multiplying a number (N) * (N-1) number -1 until the (N) becomes 1
    // (i.e. N = 5 so 5*4, 5*3, 5*2, 5*1) so (n*(n-1), n*(n-2)......)

    // cout << "The factorial of a number is " << endl;

    // int N, fact = 1; // fact is declared to store the result of the factorial

    // cout << "Enter the value of N : " << endl;

    // cin >> N;

    // for (int i = 1; i <= N; i++)
    // {
    //     fact = fact * i;
    // }

    // cout << "The factorial of " << N << " is : " << fact << endl;

    // lets do it again.

    // first lets declare a variable N to take a number input
    // and a Fact = 1 variable (to store output of loopp and assigned it to 1) because if we assign it with 0 anything (0 * anything = 0) so one is  a neutral number.
    int N, fact = 1;
    // now take input of N (what Factorial of number you want)
    cout << "Enter a Number you want the factorial of : " << endl;
    cin >> N;
    // now use a loop to generate N numbers, where i starts with 1, i <= N (if i(which is 1) <= N(ex:5) no)
    // so now increment it to generate N numbers. ex: 5
    for (int i = 1; i <= N; i++)
    {
        fact = fact * i;
        // first fact = fact* i(starts with 1) so
        // fact = fact * i (fact = 1 * 1 = 1) then loop repeats.
        // (fact = 1 so ) fact = 1 * i(which is <= N value) so it is increased, (i+1) = 2
        // so fact = 1 * 2 = 2
        // so now the fact = 2.
        // so now fact = 2 * i(which is 3 because <= N(5) so fact = 2 * 3 = 6
        // now fact = 6
        // so fact = 6 * i(which is 4 because <= N(5) so fact = 6 * 4 = 24
        // so now fact = 24/
        // now fact = 24 * 5  = 120. therefore fact = 120 which stores 120 value
    }
    cout << "The factorial of " << N << " is : " << fact << endl;

    // Exercise : check if a number is prime or not ?
    // what is a prime number (a number which is divisible by 1 and itself(N).
    // so we just write only two conditions 1) if num % 2 ==1 && num % num ==0 that's it.
    // not at all This method =d is Flawed, here we are checking if a number is odd (num % 2 ==1 so odd) but not all odd numbers are prime ex : 9 and we don't counter (numbers which are -ve)

    // cout<<"to check if a number is Prime number ? "<<endl;
    // int Num;
    // cout<<"Enter the Value of N : "<<endl;
    // cin>>Num;

    // if(Num%2==1 && Num%Num ==0){
    //     cout<<"The Entered number : "<<Num<< " is a valid Prime Number "<<endl;
    // }
    // else{
    //     cout<<"Entered number "<<Num<<" is not a prime number "<<endl;
    // }


    
    // so we do as : 
    cout<<"Checking if a number is prime or not "<<endl;

    int num;
    cout<<"Enter a number to check if it is a prime number "<<endl;
    cin>>num;

    // now we create a bool variable to indicate as a flag.
    bool isprime = true;

    if(num<=1){
        isprime = false; //because prime numbers are only positive numbers and greater than 1
    }else{
        // if a number is positive then the it should be greater than 1. and we check a condition (i < num) assume an example : 2 < 9 so, we increment up to Num (2 to 9) to check all possibilities of the number) remember the prime Number rule : no number from (2 to num -1) divide and get == 0. so we check all possibilities of (Num being divided from 2 to num-1 (i.e. num-1 = 8, if entered 9)) 

        //works as first checks condition (i(2)<num(10) so false so it gets incremented and checked each time if the (10 % 2 ==0) then false not prime.   
        for(int i = 2; i < num; i++){
            if(num % i == 0){
                isprime = false;
                break;
            }
        }
        
    }
    // now check if it is a prime number or not, (remember by default bool value is true)
    // cout<<"This always returns true and 0-> true 1 -> false in bool so : "<<isprime<<endl; 
    if(isprime){
        cout<<"The entered number "<<num<<" is a prime number "<<endl;
    }else{
        cout<<"The entered number "<<num<<" is not a prime number "<<endl;
    }


}