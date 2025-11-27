/*
The square root of an a element lies between its range from (0-n)
ex: 12 = the square root of 12 lies between (0-12)this is called search space
*/
#include <iostream>
#include <vector>
using namespace std;

int BRuteforce(int num)
{
    // take an input from user, and check if num is 0 or 1, then return itself
    if (num == 0 || num == 1)
    {
        return num;
    }

    int ans = 1; // to store answer
    for (int i = 0; i <= num; i++)
    {
        // now check if i * i is less than num(use long long to avoid overflow)
        if ((long long)i * i <= num)
        {
            // then store ans
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;//returns ans if num = 5 then op = 2 (because 2*2 = 4 ...something closest to 5)
}

// optimized solution
int optimizedsol(int num)
{
    if (num == 0 || num == 1)
    {
        return num;
    }

    int low = 0;
    int high = num;
    int ans = 1;

    // now loop until low <= high
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // check condition if mid * mid < = num ; but this statement can cause overflow for large numbers so we use 
        if(mid <=num/mid){
            // Then store mid value and increment the low next to mid
            ans = mid;
            low = mid +1;
        }else{
            // if mid is greater than num we decrement high, to reduce mid
            high = mid -1;
        }
    }
    return ans;//returns ans if num = 5 then op = 2 (because 2*2 = 4 ...something closest to 5)
}

int main(){

    int num;
    cout<<"Enter a Non Negative number : "<<endl;
    cin>>num;

    cout<<"The Brute force approach is "<<BRuteforce(num)<<" \n";
    cout<<"The Brute force approach is "<<optimizedsol(num)<<" \n";
    return 0;
}