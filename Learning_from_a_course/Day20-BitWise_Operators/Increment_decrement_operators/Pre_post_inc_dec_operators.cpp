/* Pre Increment operators : ++a

ex: a =5;
    ++a;

    Preincrement => increment the value before using. so on second line (++a) the value became (6)

The Opposite of this is Post increment operator : first use the value then print it.
ex: a =5;
    a++;
    so here it prints 5 then after printing it increments to 6.



Now Let's see about Post decrement Operators :
pre decrement => First decrement the value then use it.
Ex: int a = 5;
    --a
    this prints 4.

Post decrement => first use the value then decrement it.
ex: int b =5;
    a--;
    prints 5 and Then decrement will be applied
*/
#include <iostream>
using namespace std;

int main()
{
    // lets see with examples : pre increment
    int a = 5;
    ++a;
    cout << a << endl;

    // post increment :
    int b = 5;
    cout << b++ << endl;
    cout << b << endl;

    cout << "---------------------------" << endl;
    // Pre decrement operator : First decrement the value and use it
    int dec = 5;
    --dec;
    cout << dec << endl;

    // Post decrement : first use the vlaue then decrement it
    int dec1 = 10;
    dec1--;
    cout << dec1 << endl; // Prints 9 because we are giving time to decrement. if we use it directly inside Cout "the cout flushed the context to output screen so it wont have time to decrement so we get decremented value in next print"

    cout<<"------------------"<<endl;
    // But if we use it like this :
    int dec2 = 10;
    cout << dec2-- << endl; // This prints 10 becaue it matters where we are using the post increment or decrement operators. if we use it inside cout it prints value. but if we use it before cout it gets decremented. 

    // Lets see this example :
    int Exp = 5;
    cout << (++Exp) * (++Exp) << endl;//pritns 49 because it's compiler dependent, most compilers evaluate from right to left, so (++exp); ==> 6 and (++Exp) * => 7. so now the compiler checks (Exp) value = 7 so (7*7=49)
}