#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums)
{
    // Here given an array nums and asked to find a majority element that appears more than n/2 times

    // core idea to find the max repeating number : take two elements 1)memory and 2) count
    // memory remembers which value we keep tracking, count the count of values

    int memory = 0;
    int count = 0;
    // loop the array and check if count is 0 if yes then memory has no element stored init so we track the first element in array
    for (int num : nums)
    {
        if (count == 0)
        {
            memory = num;
        }
        // now update the count, if same number appears again else decrement
        if (num == memory)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    // here verification is optional because problem guarantees the majority element exist.
    return memory;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int result = majorityElement(nums);

    cout << "Majority Element is: " << result << endl;

    return 0;
}
