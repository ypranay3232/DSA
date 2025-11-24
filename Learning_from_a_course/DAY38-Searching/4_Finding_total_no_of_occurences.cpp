/* Assume an array = {2,4,4,4,4,4,4,6,8,10}
target = 4

now to find total no of occurences we can do as :
starting occurence + last occurence - 1
(1)                 + ( 6) -1 = 6.
*/
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int total_no_of_Occurences(const vector<int> &v, int target)
{
// if we code first occurence + last occurence functions it is a brute force approach ! 
auto first = lower_bound(v.begin(), v.end(),target);
auto last = upper_bound(v.begin(), v.end(),target);

// now we check if the first is pointing at end or it is not equal to target then target does not exist.
if(first == v.end() || *first != target){
    return 0;
}
return last - first;
}

int main()
{
    vector<int> v = {2,4,4,4,4,4,4,8,10};
    int target = 4;

    cout<<"total no of occurences are : "<<total_no_of_Occurences(v,target)<<endl;
    return 0;
}