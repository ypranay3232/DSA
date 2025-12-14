/*
you are given an array containing N integers,
which denotes the position of a stall(stall where cow resides)
you are also given k integers which denotes no of aggressive cows


you are given the task of assigning stall to k cows, such that minimum distance between any two is maximum possible. (keep maximum possible distance between any two cows) 

ex: 
N = 5
k = 3
stalls =  [1,2,4,8,9]
output : 
first cow can be placed in stall[0]
second cow can be placed in stall[2]
Third cow can be placed in stall[3]

so minimum distance between cows is (3) which is largest among all possible ways

(.i.e : in simple terms the cows are aggressive so they have to keep in distant to each other otherwise the start to fight with each other so : we have 
stalls = 1,2,4,8,9 
and 3 cows 
stalls size = 5(N)

keep cows in distance with each other )


Now : create a number line : 

-|--|--|--|--|--|--|--|--|--|----
 0  1  2  3  4  5  6  7  8  9 

from this number line we have (from stall) 1,2,4,8,9

Now try to arrange the cows in the stall with having minimum distance

1     2    4    8    9
----------------------
c1   c2   c3           = c1 = 1, c2 = 2, c3 = 4, c2 - c1 = 1, c3 - c2= 2 (min distance = 1)
c1        c2        c3 = now changed arrangement, c2 - c1 = 2, c3 - c2 = 5 (min dist = 3)
c1              c2  c3 = now c2 - c1 = 7, c3 - c2 = 1. minimum distance = 1.
     c1   c2        c3 = c2 - c1 = 2, c3 - c2 = 5, minimum distance = 2
c1        c2    c3     = c2 - c1 = 3, c3 - c2 = 4, min distance = 3
          c1    c2  c3 =  c2 - c1 = 4, c3 - c2 = 1, min distance = 1

now from all the minimum distances : 1,3,1,2,3,1 
get the maximum one : 3. so that is the answer ! 



explanation : 
(the distance between both c1,c2 is (2-1 =1) and 3rd cow is at 4) so (c3,c2 distance is 4-2 = 2)


NOTE : to solve the problem, we are using an array that need to be sorted 

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool ispossibleSolution(vector<int>&stalls, int k, int mid){
    // placing k cows with atleast minimum distance between both 
    int cow = 1;
    // placed first cow at index 1
    int position = stalls[0];
    // now we iterate all other cows
    for(int i =0; i<stalls.size();i++){
        if(stalls[i] - position >= mid){
            cow++;
            position = stalls[i];//2ad cow is placed
        }
        if(cow == k ){
            return true;
        }
    }
    return false;
}

int solve(int n, int k, vector<int>& stalls){
    sort(stalls.begin(), stalls.end());
    int start = 0;
    int end = stalls[stalls.size()-1] - stalls[0];
    int ans = -1;

    while(start<=end){
        int mid = start + (end - start)/2;
        if(ispossibleSolution(stalls,k,mid)){
            // if we found possible solution 
            ans = mid; // and move start + 1 
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;

}

int main(){
    int n = 5;
    int k =3;
    vector<int> stalls = {1,2,4,8,9};

    int result = solve(n,k,stalls);
    cout<<"The Result is : "<<result<<endl;

    return 0;
}