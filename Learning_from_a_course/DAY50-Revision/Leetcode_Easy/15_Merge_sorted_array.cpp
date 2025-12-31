#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    // given an array nums1 and size = M+N (m are valid and sorted) (N are zeroes)
    // nums2 size = N, Merge both nums1 and nums2 in sorted order without using extra space

    // Without using extra space so where to store the largest elements (at the end of nums1)
    // we have empty spac (0's) so merge from back

    // // 1)Brute force:
    // // first copy the nums2 elments into nums1
    // for(int i =0;i<n;i++){
    //     nums1[m+i] =  nums2[i];
    // }
    // // now sort the nums1
    // sort(nums1.begin(),nums1.end());

    // 2)Optimised using two pointers: we compare two arrays and store the largest at the end
    // ex : nums1 = {1,2,3,0,0,0} m = 3
    //      nums2 = {2,5,6} n = 3 and goal = {1,2,2,3,5,6}

    // s1: initialize pointers for both arrays
    int i = m - 1; // here i points to the last elementin nums1, becasue first m are valid elements
    // ex: {1,2,3,0,0,0} i points to 3(m-1)
    int j = n - 1;     // j points to the last of nums2, j points to 6(2,5,6)
    int k = m + n - 1; // k points to the last element of nums1 {1,2,3,0,0,0} points to 0

    // While both arrays having elements
    while (i >= 0 && j >= 0)
    {
        // compare the largest element of both, if nums1 is greater than nums2
        if (nums1[i] > nums2[j])
        {
            // then assign nums[k] to nums[i] (assign biggest element to k)
            nums1[k] = nums1[i];
            // and now move the i pointer to left/ next index
            i--;
        }
        else
        {
            // if nums1[i] is not greater than nums2[j]then assign nums1[k] = nums2[j]
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Handling edge case if nums2 has any elements left they are moved into nums1
    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    merge(nums1, m, nums2, n);
    cout << "Merged array " << endl;
    for (int x : nums1)
    {
        cout << x << " ";
    }
    return 0;
}