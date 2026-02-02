// When a function calls itself directly or in directly called recursion. In simple terms the logic depends on the smaller problem ex: f(n) = 2^n, if f(n-1) = 2^n-1, f(N) depends on 2^n.
#include <iostream>
using namespace std;

// NOTE : this runs infinitely

// int fact(int n){
//     int ans = n * fact(n-1);
//     return ans;
// }
// int main(){
//     int n;
//     cout<<"Enter a number:"<<endl;
//     cin>>n;
//     int ans = fact(n);
//     cout<<"Answer is "<<ans<<endl;
//     return 0;
// }

// Remember 3 conditions : 1) base condition when to stop, 2) recursive relation, precessing
// int fact(int n){
//     cout<<"function call for "<<n<<endl;
//     // base condition : when to stop
//     if(n==1){
//         return 1;
//     }
//     // 2) recursive relation fact calling itself
//     int smallproblem = fact(n-1);
//     int bigproblem = n * smallproblem;

//     return bigproblem;
// }
// int main(){
//     int n;
//     cout<<"Enter a number to check factorial :"<<endl;
//     cin>>n;

//     int ans = fact(n);
//     cout<<"Factorial of "<<n<<" is "<<ans<<endl;
//     return 0;
// }

// call stack : whenever we call a function a entry is sent to stack. works as : 
/*

|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
| printcounting(4) |
| printcounting(5) |
| int main         |
-----------------
stack

works as : first stores main() then creates int n, reads input n = 5, then passes it to printcounting(5). 

now checks if input n = 0. if yes return 0. no so print value of printcounting(n) : 5, then print recursive logic : printcounting(n-1) prints 4;

this repeats til printcounting becomes 0 and if condition triggers and return 0.

*/

// void printcounting(int n) {
//     // Base condition
//     if (n == 0)
//         return;

//     // To print in DESCENDING order, move cout here. when we process before recursion this is called Tail recursion 
//     // cout << n << endl;

//     // Recursive relation
//     printcounting(n - 1);

//     // This prints in ASCENDING order because it happens after the recursive call, when processing occurs after recursion called Head recursion 
//     cout << n << endl;
// }

// int main() {
//     int n;
//     cout << "Enter a value : ";
//     cin >> n;

//     printcounting(n);
//     return 0;
// }



// lets print a fibonacci 
int fib(int n){
    // base case : 
    // if(n==1){
    //     return 0;
    // }else if(n==2){
    //     return 1;
    // }
    if( n == 0 || n ==1){
        return n;
    }
    
    // recursive relation : 
    int ans = fib(n-1) + fib(n-2);
    return ans;
}

int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;

    int ans = fib(n);
    cout<<n<<"th Term is : "<<ans<<endl;
    return 0;
}