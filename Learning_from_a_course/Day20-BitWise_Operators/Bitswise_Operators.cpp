/*BitWise Operators : 
AND 
OR
NOT
XOR

The computer understands bits (0,1) So the Operators which we can apply on the bits are Bitwise operators

BitWise AND (&) : (.i.e. Both should be true )
-----------------
| A | B | Output|
----------------|
| 0 | 0 |    0  |
| 0 | 1 |    0  |
| 1 | 0 |    0  |
| 1 | 1 |    1  |
-----------------

BitWise OR(|) : (.i.e. Any one should be true)
-----------------
| A | B | Output|
----------------|
| 0 | 0 |    0  |
| 0 | 1 |    1  |
| 1 | 0 |    1  |
| 1 | 1 |    1  |
-----------------

Not (! or ~(negation/tilda)) : It print's the invert value of a given value (0 -> 1 or 1-> 0)
------------
| A  |  ~ A|
------------
| 0   |  1 |   
| 1   |  0 |   
------------

XOR (^): Returns 1 if both values are different and prints 0 if both are same.
-----------------
| A | B | A^B   |
----------------|
| 0 | 0 |    0  |
| 0 | 1 |    1  |
| 1 | 0 |    1  |
| 1 | 1 |    0  |
-----------------


*/
#include<iostream>
using namespace std;

int main(){
    bool a = true;
    bool b = false;

    cout<<(a & b)<<endl;;// Returns false (0) becasue & is true only when both are true. so Make both A,B true.

    // Let's see something interesting : lets do (2&3) it prints 2 ! 
    cout<<(2&3)<<endl;
    /* Because : At Low Level 2--> 10 and 3 --> 11 so :
    1 0
    1 1
    ----
    1 0 --> 0 & 1 --> 0 and 1 & 1 ---> 1 so = 10 which is (2)
    ----
    */

    bool c = true;
    bool d = false;
    cout<<(c | d)<<endl;;//Prints True(1) Because any one value is true then output is true.
    cout<<(~d)<<endl;
    // This prints -1. Because when we print d. which is false dydefault(0) and when we negate (~d) the zero becomes in memory as : 

    /*
        0 : 0 0 0 0 0 0 0 0
        1 : 1 1 1 1 1 1 1 1
        ---------------------
              0 0 0 0 0 0 0
                        + 1
            ----------------
            1 0 0 0 0 0 0 1  = -1
            ----------------        

        // the compiler took the first bit(1) -> signed bit which is (1 == -ve) and then took remaining numbers and did 1's compliment(.i.e. added +1 to it) so : the -ve and the 1 which we got from 1's compliment = -1
    */

    bool e = true;
    bool f = false;
    cout<<(e^f); //(1) because both values are different


}