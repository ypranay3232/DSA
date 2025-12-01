/*
Find the Odd occuring elements in an array  
assume : {1,1,2,2,3,3,4,4,3,600,600,4,4};

case 1 : here all elements occur even number of times except one (3) 
case 2: all the repeating elements occur in pairs (1,1,2,2 etc) and pairs are not adjacent(not in continuous order) ex : (4,4, .......(4,4)) both are not continuous must have space bewteen both.

Find the element that appears odd number of times.

The pattern that we can find here is by index: 
we can say that : 1st index and 2nd index is positive and negative, and 2,3 index is also positive and negative.

---->assume answer = 3(at index 8)
---->we can say that in a pair -> first index is even index and 2nd index is odd index. (1,1)

---->now at right side of answer(3) (600,600) the first 600 index is 9(odd) and 10(even), 
so now at right side of ans the pattern is odd,even, odd,even

--->answer will always be on a even index : 


approach 1 : we can do Xor for all numbers : (because 1^1 = 0, 1^2 = 1 (return 0 for same and 1 for different element))


Types of Binary search Questions : 

Type 1: Classic Binary Search (Sorted Array Operations)
Includes:

Searching for an element
First/last occurrence
Upper bound / lower bound
Count frequency
Find pivot in rotated array
Find peak element
Square root (integer)

Identifying Pattern : 
If the array itself is sorted, and you are directly searching for something → Type 1.


Type 2: Binary Search on Answer (Search Space / Predicate)

Here the array is NOT necessarily sorted.
You binary search on the possible range of answers, not the array.

Problems:
Aggressive Cows
Painter Partition
Allocate Books
Split Array Largest Sum
Min time to cook parathas
Koko Eating Bananas
Shipping Packages

Identifying Pattern
Question will sound like:
“Minimum possible value of X such that…”
“Smallest number Y that satisfies condition…”
“Can we do this in T time?”
Optimization + checking


Type 3: Index Pattern Observation

Single element in sorted array (this problem)
Find missing element when numbers appear in patterns
Bitonic/mountain-based BS
Find first bad version (pattern break)
Problems with structured pairs/triplets in sorted arrays

How to Identify:
Array is sorted
Standard binary search doesn't directly apply
Search-on-answer doesn’t fit
There is a "structural pattern" in indexes (pairs, monotonicity, pattern flips)


the 3) type of question is now we are solving !


*/

#include<iostream>
#include<vector>
using namespace std;

int find_odd_occuring_ele(vector<int>&arr){
    int start =0; 
    int end = arr.size()-1;

    while(start<end){
        int mid = start+(end-start)/2;
        // If mid is even index
        if(mid % 2 ==0){
            // so we can say that the mid index starts with even number
            if(arr[mid]==arr[mid+1]){
                // mid is even because it is divisible with 2 and its next index will be odd,so we can say that "we found a pair" and the even odd pattern is at left side of target so if we are at left side we need to iterate to right side to find target
                start = mid + 2;//+2 because we already checked mid and mid+1 so we already checked next index so we need to skip to 2nd inedx.
            }else{
                end = mid;//here if the mid is not equal to its next inedx then we can say that it could be the answer or mid -1 is the answer element, so search left. And we make the "e = mid" because mid may be target and target will always be "even"
            }
        }
        else{
            // if mid is odd and equal to its next index then it is in left so move right
            if(arr[mid] == arr[mid-1]){
                start = mid + 1;
            }
            else{
                // if current + next index is not equal then go left 
                end = mid - 1;
            }
        }
    }
    return start;
}

int main(){
    vector<int> arr = {1,1,2,2,3,3,4,4,3,600,600,4,4};
    int ans = find_odd_occuring_ele(arr);
    cout<<"The Index is : "<<ans<<endl;
    cout<<"The Value is : "<<arr[ans]<<endl;
    return 0;
}