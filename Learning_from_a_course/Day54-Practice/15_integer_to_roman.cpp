/*
Leetcode : 12
1. The Basic Building Blocks
The Romans had symbols for specific values. Think of these like the only "coins" you have in your pocket:
Value,Symbol
1,I
5,V
10,X
50,L
100,C
500,D
1000,M

2. The Main Rule: "Add Them Up"
Usually, you just put the biggest symbols first and add them together.
2000 is 1000 + 1000 -->MM
150 is 100 + 50 -->CL
7 is 5 + 1 + 1 --> VII

3. The "Subtractive" Rule (The tricky part)
The Romans didn't like repeating the same symbol more than 3 times. Instead of writing IIII for 4, they wrote IV.
This is like saying "One before Five."
There are only 6 specific cases where this happens:

4: IV (1 before 5)

9: IX (1 before 10)

40: XL (10 before 50)

90: XC (10 before 100)

400: CD (100 before 500)

900: CM (100 before 1000)


Let’s break down a hard number: 1994
To solve this, you break the number down by its decimal places (Thousands, Hundreds, Tens, Ones):

1000: Look at your list. We have a symbol for 1000. It's M.

900: Look at your list. 900 is a "subtractive" case. It's CM.

90: Look at your list. 90 is a "subtractive" case. It's XC.

4: Look at your list. 4 is a "subtractive" case. It's IV.
Now, glue them together: M + CM + XC + IV = MCMXCIV.

If you have 58:

Can I fit 1000? No.

Can I fit 500? No.

Can I fit 50? Yes (L). (Remaining: 8)

Can I fit 10? No.

Can I fit 5? Yes (V). (Remaining: 3)

Can I fit 1? Yes (I). (Remaining: 2)

Can I fit 1? Yes (I). (Remaining: 1)

Can I fit 1? Yes (I). (Remaining: 0)

Result: LVIII

*/

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
using namespace std;

string intToRoman(int num)
{
    // Given different symbols that represent numeric values, 2 is written as II, 23 is written as XXIII and so on.
    // And this is written in highest to lowest (XXIII) XX is highest and II is lowest. so always add biggest number first and then smallest
    // we have two cases positive addition roman numbers which has highest values first and subtractive roman numbers which have lower numbers first there are only 6 speciic cases here :
    // 4 --> IV (smallest first then largest (I - V = 4))
    // 9 --> IX ( I - X = 9)
    // 40 --> L(X - L = 10 - 50 = 40)
    // 90 -->XC(10 - 100 = 90)
    // 400 --CD (100 and 500 = 400)
    // 900 -->CM (100 - 1000 = 900)

    // Intution : assume this as you are a cashier yuu are giving the change to customers when a customer has to get 3700 we try to given max possible number and avoid any pending balance

    // so ex: 3700 --> 1000(M) * 3 = MMM (3000), then remaining 700 so (D) = 500, reamining = 200 so we use (CC) = 200 : Total = MMMDCC

    // first create a map that contains symbols and values a cash register(where money is)
    vector<pair<int, string>> CashRegister = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    // now store the result and to optimize the sol we use reserve
    string result = "";
    result.reserve(15);

    // now loop the map
    for (const auto &[value, symbol] : CashRegister)
    {
        // check if num is > value if yes then remove that amount from total, giving cash from cashregister
        while (num >= value)
        {
            // now as we give cash we remove the amount from total and add symbols to result
            num -= value;
            result += symbol;
        }
        // if we hit 0 then no need to pay extra amount so stop
        if (num == 0)
        {
            break;
        }
    }
    return result;
}
int main(){
    int testinput;
    cout<<"Enter an integer "<<endl;
    if(!(cin>>testinput)){
        cout<<"invalid input "<<endl;
        return 1;
    }

    if(testinput > 3999 || testinput < 1){
        cout<<"Value out of range (1-3999)"<<endl;
    }else{
        string Int_To_String = intToRoman(testinput);
        cout<<"Roman Number of entered input is : "<<Int_To_String<<endl;
    }
    return 0;
}
