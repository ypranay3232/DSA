#include <iostream>
#include <vector>

using namespace std;
int thirdMax(vector<int> &nums)
{
    // Given an integer array nums from that return distinct values only (no duplicates allowed)
    // and return the 3rd largest and unique value.
    // if there are fewer than 3 numbers return the max largest number
    // : Find the 3rd unique maximum value
    /*
    Example :  nums = [2,2,3,1]

    Distinct values → {3,2,1}
    3rd maximum → 1

    Duplicates are collapsed.

    Approach 1: using a Set but Time : O(nlogn) in question asked to find solution in O(N)
    */
    // Approach 2 : intution maintain 3 variables first -->largest,second--->second largest ,
    // third--> 3rd largest
    long long first, second, third;
    bool hasFirst = false, hasSecond = false, hasThird = false;
    // why long because look at the edge cases constraints :  nums[i] <= 231 - 1
    //  so using Integer.MIN_VALUE causes comparison ambiguity.

    // now loop through the array and store current elemtn(x) in num
    for (int x : nums)
    {
        long num = x;

        // if hasfirst and num(current element) == first (itself of first) we found duplicates so
        // skip them and repeat for all
        if ((hasFirst && num == first) ||
            (hasSecond && num == second) ||
            (hasThird && num == third))
        {
            // found duplicates so skip
            continue;
        }
        // case 2 : if !hasfirst or num(current element > first) swap thrid = second,
        // second = first and first = num (current element)
        if (!hasFirst || num > first)
        {
            third = second;
            hasThird = hasSecond;
            second = first;
            hasSecond = hasFirst;
            first = num;
            hasFirst = true;
        }
        // Same repeat for second and third
        else if (!hasSecond || num > second)
        {
            third = second;
            hasThird = hasSecond;
            second = num;
            hasSecond = true;
        }
        else if (!hasThird || num > third)
        {
            third = num;
            hasThird = true;
        }
    }
    if (hasThird)
    {
        return (int)third;
    }
    else
    {
        return (int)first;
    }
}
int main()
{
    vector<int> nums = {2, 2, 3, 1};
    int result = thirdMax(nums);
    cout << "The Values are : " << result;
    return 0;
}

/*
Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
*/