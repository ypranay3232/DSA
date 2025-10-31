/*
Shifting bits Position Gives you a different value :

Ex: 5 -> 00000101

Now we do one left Shift  : so the bits are shifted from left to right :
00000101'0' : 1010 = 10 (8421 rule)

We can say that by doing one left shift the value of a number will be Multipled by 2
ex: a = 1 --> 00000001
Left shift(<<) --> 00000010 -> 10 = '2'
Now if we do another left shift will it become 4 ?
2 --> 00000010 --> 00000100 --> 100 = '4'

Let's Try it :

Now let's see About Right shift : here we shift bits from right to left. 
ex; 8 --> 000010000 --> 00000100 = 4
so we can say that the value became half.
*/

#include <iostream>
using namespace std;

int main()
{
    int a = 12;
    a = a << 2; // left shifting a to 1 bit. 
    // 12 --> 24, so if we do another left shift we get 48 ?  But if we do shift for a negative value we get garbage value.
    cout << a << endl;

    int b = 8;
    b = b>>1;//the value got half
    /*
        Works as : 8 -> 00001000 - > 00000100 = 4. but lets say what if we do it with a -ve number :
        here -8 -> (first digit for -ve number is sign but so :) 1 0 0 0 0 1 0 0 0 
        when we shift a bit to right side the 1 becomes 0 : 0 1 0 0 0 0 1 0 0 = it returns a high value positve number.  
    */
    cout<<b<<endl;

    
}