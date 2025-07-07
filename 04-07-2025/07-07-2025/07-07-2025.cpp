#include <iostream>
using namespace std;

int main()
{
    // resuming the exercises !

    // exercise : print the factorial of any number.

    // what is factorial its multiplying a number (N) * (N-1) number -1 untill the (N) becomes 1
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
    int N,fact=1;
    // now take input of N (what Factorial of number you want)
    cout<<"Enter a Number you want the factorial of : "<<endl;
    cin>>N;
    // now use a loop to generate N numbers, where i starts with 1, i <= N (if i(which is 1) <= N(ex:5) no)
    // so now increment it to generate N numbers. ex: 5
    for(int i = 1; i<=N;i++){
        fact = fact * i;
        // first fact = fact* i(starts with 1) so
        // fact = fact * i (fact = 1 * 1 = 1) then loop repeats.
        // (fact = 1 so ) fact = 1 * i(which is <= N value) so it is incresed, (i+1) = 2
        // so fact = 1 * 2 = 2
        // so now the fact = 2.
        // so now fact = 2 * i(which is 3 because <= N(5) so fact = 2 * 3 = 6
        // now fact = 6
        // so fact = 6 * i(which is 4 because <= N(5) so fact = 6 * 4 = 24
        // so now fact = 24/
        // now fact = 24 * 5  = 120. therefore fact = 120 which stores 120 value
    }
    cout<<"The factorial of " <<N<< " is : "<<fact<<endl;

    

}