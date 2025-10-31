/*
The operator Precedence(priority) == in what order a operators should evaluate.(+,-,* which should go first)
The Operator associativity -- In what order a operation should be elavuated (right or left)

-----------------------------------------------------
category         |    Operators    |   Associativity| 
-----------------------------------------------------
|Bracket         |(),[],->,++,--   |  Left to right | High priority
|   Unary        |!. ~,++,--,&,+,- |  right to Left |
|Multiplicative  |      *,/,%      |  Left to right |
|Additive        |       +,-       |  Left to right |
|Bitwise shift   |   >>,<<         |  Left to right |
|Relational      |  <,>,<=,>=      |  Left to right |
| Equality       |   ==, !=        |  Left to right |
| Bitwise And    |     %           |  Left to right |
| Bitwise Xor    |     ^           |  Left to right | Low Priority


Ex: a = a+b*c/d-a
        2+3*1/3-1
Here if we do addition we get different value and if i do Muliplication first we get another value.

*/
#include<iostream>
using namespace std;
int main(){
    int a= 5,b=10,c=6,d=2;
    cout<<a+((b*c)/d)-a;
    // we have a hack instead of learning the whole table just apply braces to the expression as we know that the braces have highest priority so we can evaluate and we get the right answer.

}