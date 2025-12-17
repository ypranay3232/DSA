/*
The IEEE having its annual meeting next week and president wants to serve cheese parata after
the meeting.

The SubCommittee members asked to pack Paratas P(p<=1000)
The food Stall Has L cooks (L<=50)
A cook rank [1 to 8]

A cook with R rank can cook 1 Parata in first R minutes, one more parata in next R minutes

EX: if a cook rank is 2 he can cook a parata in 2 minutes and one more parata in 4 minutes
(.i.e : if a cook rank is 2 he cooks 5 parata then time taken would be : 1 * 2 + 2 * 2 + 3 * 2 + 4 * 2 + 5 * 2 = each parata * minutes to cook)


so the higher the rank a cook has the longer he takes to cook. (inefficient)

The Master wants to know the minimum time to get the Order done. We are searching for the minimum time T such that:
All cooks combined can cook at least P pratas within T minutes.

*/

// 1) Brute Force Approach : we check with a for loop each minute (When the Order get finished )
/*
Cooking Rule

A cook with rank R:

1st prata → R minutes

2nd prata → 2R minutes

3rd prata → 3R minutes

...

Total time to cook k pratas:

𝑅 × (1+2+3+..+𝑘)=𝑅×𝑘(𝑘+1)2

Important constraint
A cook can cook only complete pratas.
If time is insufficient for the next prata, it is not counted.


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 2) Optimised Binary Search : Checks if P pratas can be cooked within "mid" time

bool canCook(int time, vector<int>& rank, int P)
{
    int totalPratas = 0;

    for (int i = 0; i < rank.size(); i++)
    {
        int r = rank[i];
        int currTime = 0;
        int cnt = 0;

        while (true)
        {
            int nextTime = (cnt + 1) * r;
            if (currTime + nextTime > time)
                break;

            currTime += nextTime;
            cnt++;
        }

        totalPratas += cnt;
        if (totalPratas >= P)
            return true;
    }

    return false;
}


int solveBruteForce(int P, vector<int>& rank)
{
    int maxTime = *min_element(rank.begin(), rank.end()) * (P * (P + 1)) / 2;

    for (int time = 0; time <= maxTime; time++)
    {
        if (canCook(time, rank, P))
            return time;
    }
    return -1;
}

int solveBinarySearch(int P, vector<int>& rank)
{
    int low = 0;
    int high = *min_element(rank.begin(), rank.end()) * (P * (P + 1)) / 2;
    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canCook(mid, rank, P))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}


/*
input : 1 (test cases how many inputs we are testing)
10 (Total no of paratas)
4 (total no of cooks)
1 2 3 4  (Cooks rank)
*/
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int P, L;
        cin >> P;
        cin >> L;

        vector<int> rank(L);
        for (int i = 0; i < L; i++)
            cin >> rank[i];

        // Use optimized solution
        cout << solveBinarySearch(P, rank) << endl;

        // For learning/debugging:
        // cout << solveBruteForce(P, rank) << endl;
    }

    return 0;
}