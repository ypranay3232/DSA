#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string largestNumber(vector<int> &nums)
{
    // given a list on integers arrange them in such a way when you concatenate them the result number is as large as possible.

    // intution in simple words : rather than checking each combination we do as : for each a,b pair we check (a +b > b+a) then a must come before b else b comes first before a

    // first convert given integers to strings because concatenation is string operation
    vector<string> arr;
    for (int num : nums)
    {
        arr.push_back(to_string(num));
    }

    // now sort the array and decide the order
    sort(arr.begin(), arr.end(), [](string &a, string &b)
         { return a + b > b + a; });

    // if the given numbers are zero
    if (arr[0] == "0")
        return "0";

    // now return the string
    string result;
    for (string &s : arr)
    {
        result += s;
    }
    return result;
}
int main()
{
    vector<int> nums = {10,2};
    string ans = largestNumber(nums);
    cout<<ans<<endl;
    return 0;

}
