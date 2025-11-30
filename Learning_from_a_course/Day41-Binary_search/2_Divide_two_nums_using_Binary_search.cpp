/*
Assume Divident = 10, divisior = 2, find quotient 

We can use a formula (quotient * divisior = divident) we dont have quptient so we replace it with mid

so we check that (quotient * divisior <= divident)
ex : 10/2 (10 divident, 7 is divisior)
so start = 0, mid = 5 because(start+(end-start)/2), end = 10, and by using formula : ( 5*2<=10) true

ex: 22/7 (22 = divident, 7 = divisior)
start = 0, mid = 11, end = 22.
by using formula (mid * divisior ) ( 11 * 7 ) = 77, is >= divident(22) so we check left side. 
so end = mid -1; so 

start = 0, mid = 5, end = 10
(mid * divisior = 5*7 = 35) >= 22 so go left
end = mid -1.
start = 0, mid =2 , end = 4 (mid*divisior = 2*7 = 14) <= 22 so this can be answer so store it and check right side of the answer.
start = mid + 1
start = 3, mid =3, end = 4 ( 3* 7 = 21) <= 22, so store this and check right side 
start = mid + 1.
start = 4,end=4,mid=4.
(4*7 = 28) >= 22 so stop, and print result (as 21)

*/

#include<iostream>
#include<vector>
using namespace std;

int div_by_Two_nums(int divident, int divisior){
    int start = 0;
    int ans =0;//to store the values when we encounter nearest value to divident
    int end = divident;
    int mid = start + (end-start)/2;

    while(start<=end){
        if(mid*divisior == divident){
            return mid;
        }else if(mid*divisior > divident){
            end = mid -1;
        }else{
            // here we store the answer and move right 
            ans = mid;
            start = mid + 1;
        }
        // now update the mid
        mid = start + (end-start)/2;
    }
    return ans;

}

int main(){
    int divident;
    cout<<"Enter the divident : "<<endl;
    cin>>divident;

    int divisior;
    cout<<"Enter the divisior : "<<endl;
    cin>>divisior;

    int ans = div_by_Two_nums(divident, divisior);
    cout<<"The answer is : "<<ans;
}