/* ex : 7 factorial = 1*2*3*4*5*6*7 = 5040
now we store the result one digit by one in array.

carry =0;
int x = ans[j] * i+carry;
ans[j] = x%10;
carry = x/10;

It works as : on first iteration
ans.size = 1, j=0;
x = 1*2+0;
a[j] = 2%1 = 2
carry = 2/10 = 0;
---- and if carry enciunters oush it
*/

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> factorial(int n)
{
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            int x = ans[j] * i + carry;
            ans[j] = x % 10;
            carry = x / 10;
        }
        while(carry)
        {
            ans.push_back(carry%10);
            carry/=10;
        }
        
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number to get factorial : "<<endl;
    cin>>n;

    vector<int> res = factorial(n);
    for(int x : res){
        cout<<x<<" ";
    }
}