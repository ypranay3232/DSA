#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    // This problem can be solved in two ways 1) using a Bit wise operator and 2) using a map
    // we use Bitwise operator : because it finds unique elements in linear time O(n)

    // First create and initialize zero (because any number xor with returns same number)
    int result = 0;
    // now loop the array with num
    for (int num : nums)
    {
        // This compares the bits of result and num, if the bits are same returns 0 else 1
        result ^= num;
    }
    return result;
    /*Working :

    Imagine the input is: [4, 1, 2, 1, 2]
    Start: result = 0
    Next is 4: 0 ^ 4 = 4 (Current: 4)
    Next is 1: 4 ^ 1 = 5 (Binary 100 ^ 001 = 101. Current: 5)
    Next is 2: 5 ^ 2 = 7 (Binary 101 ^ 010 = 111. Current: 7)
    Next is 1 (Repeat!): 7 ^ 1 = 6 (Binary 111 ^ 001 = 110. The previous '1' bit is now canceled).
    Next is 2 (Repeat!): 6 ^ 2 = 4 (Binary 110 ^ 010 = 100. The previous '2' bit is canceled).
    Final Result: 4 (The only number that wasn't canceled out).

    */
}
int main(){
    vector<int> nums = {4,1,2,1,2};
    int result = singleNumber(nums);
    cout<<"The Single Unique number is : "<<result<<endl;
}