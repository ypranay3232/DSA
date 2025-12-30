#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    // Given two arrays nums1,nums2 and you have to return common elements & duplicates
    // Instead of using a hashset which avoids duplicates we use Hashmap,

    // Create a Hashmap (contains key value pairs) :
    // key -> tracks number, value ->tracks how many times it appears
    unordered_map<int, int> freq;
    // Now count elements of nums1
    for (int num : nums1)
    {
        freq[num]++;
    }
    // This results as : nums1 = [1,2,2,1] ===> {1:1}, {1:1,2:1},{1:1,2:2},{1:2,2:2}
    // so we can say that 1 is available two times and 2 is available 2 times

    // Create a result array to store the values
    vector<int> result;

    // Now count the nums2
    for (int num : nums2)
    {
        // Now check if nums2 elements match with nums1, we use a condition to check
        // Does num exist in nums1 ? and if there are any unused occurence left ?
        if (freq[num] > 0)
        {
            // if true add num to result because there exist common elements
            result.push_back(num);
            // now decrease the freq
            freq[num]--;
        }
    }
    return result;
}
int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> ans = intersect(nums1, nums2);
    cout << "Intersection: ";
    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}