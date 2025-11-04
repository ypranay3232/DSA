/*
Given a number N and a value K from the right, set the Kth bit in binary representaion of N. The Position of
LSB = 0, and 2nd last bit = 1 and so on.

EX : N = 10 => 1 0 1 0
                 2 1 0
K = 2

Number after chaning the 2nd bit = > 1 1 1 0 => 14

ex: 15 == 1 1 1 1
K = 3

we take 3rd bit from 15(1) and do shift 3 times we get (1000) This is called a mask.

Now we do bitwise or for both mask and N. so we get
1 1 1 1
1 0 0 0
--------
1 1 1 1
--------

*/

// class Solution
// {
// public:
//     int setKBit(int N, int K)
//     {
//         int mask = 1 << K;
//         int ans = N | mask;
//         return ans;
//     }
// };

// we can also write it in short as : 

class Solution
{
public:
    int setKBit(int N, int K)
    {
        return N | (1<<K);
    }
};