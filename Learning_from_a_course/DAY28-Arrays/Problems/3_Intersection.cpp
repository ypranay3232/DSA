/*
the intersection of two elements : It returns the common elements between two arrays.

So the logic is : we create 2 arrays and first array traverse through 2nd array searching for matching element. If found return them to result array. This is a brute force approach
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    // creating arays
    vector<int> array1 = {1, 2, 3, 3, 4, 6, 8};
    vector<int> array2 = {3, 3, 4, 10};

    vector<int> result;

    // now traverse through arr2 with arr1 checking if any element matches current element
    for (int i = 0; i < array1.size(); i++)
    {
        int element = array1[i]; // element represents array1 current value
        for (int j = 0; j < array2.size(); j++)
        {
            // now add the condition if : array1 current element == array2[current element]
            if (element == array2[j])
            {
                // if yes then push that element to result. But we have an issue here if we have duplicate elements n, then we print the same elements again and again, and we just need to know what are the common elements between 2 arrays not the count of all elements., in this case we can use a flag to mark. so if we find the same element in array1 and array2 we mark that elemetn as -1, so we wont repeat it with other element
                array2[j] = -1;
                result.push_back(element);
            }
        }
    }

    // now print it
    for (auto val : result)
    {
        cout << val <<" ";
    }
    cout<<endl;

    // We can use another appraoch which removes all duplicates and sort in order. yes we use sets and the complexity is : Time --> O(n log n) space --> O(n+m)

    // first we create 2 arrays which are unsorted and contains duplicate values, so we convert the vectors into sets because sets wont allow duplicates and sorts automatically
    vector<int> arr1 = {1, 2, 3, 3, 4, 6, 8};
    vector<int> arr2 = {3, 3, 4, 10};

    // This takes all elements of arrays from starting to end and insert them in a set(s1)
    set<int> s1(arr1.begin(), arr1.end());//gives a non duplicate set(1,2,3,4,6,8)
    set<int> s2(arr2.begin(), arr2.end());//gives a non duplicate set(3,4,10)
    vector<int> res;

    // Now we loop through the first set and check if the vale of s1 exist in s2
    for (int val : s1)
    {
        if (s2.count(val)) // check if val exists in second set, if yes we push it to res vector
            res.push_back(val);
    }
    // now print it. 
    cout << "Unique Intersection: ";
    for (int val : res)
        cout << val << " ";
    
    // we have another best approach instead of set we use Unordered_set that works fast but returns elements in unorder the complexity is O(n+m) for both time and space complexity

    

    return 0;
}