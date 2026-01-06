#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
539. Minimum Time Difference
Solved
Medium
Topics
premium lock icon
Companies
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.


Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0


Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".*/
// you are given a clock in 24 hours format (hour and mins), Time is circular after 23:59 --> 00::00
// we have to find the difference between any two time points
int findMinDifference(vector<string> &timePoints)
{
    // Optimised solution: convert str to int, sort, loop, handle midnight case

    // first convert time(string) to minutes and store them, we use stoi()
    vector<int> minutes;
    for (string t : timePoints)
    {
        int hrs = stoi(t.substr(0, 2)); // we take a part of string from time (23::00) and slice 23
        int mins = stoi(t.substr(3, 5));
        // because we already sliced upto index 2 we slice from index 3 -5 to get minutes and store these in minutes vector
        minutes.push_back(hrs * 60 + mins); // ex: 13:20 ==> (hrs*60+mins) = (13*60+20 = 800mins) totalmins
    }
    // sort all pairs
    sort(minutes.begin(), minutes.end());
    int ans = INT_MAX;
    // now find the min difference between both two times (any two side by side)
    // loop the minutes
    for (int i = 1; i < minutes.size(); i++)
    {
        ans = min(ans, minutes[i] - minutes[i - 1]);
        // this line checks : minutes[1] - minutes[0] and minutes[2] - minutes[1] so on....
        // we do this because smallest difference can only exist between neighbour  in sorted order.
    }

    // To handle Mid night time when clock reaches: 23: 59 --> 00:00 (1439 - 0 = 1439) but we should have one minute instead of 1439 as whole day minutes, so to handle we use circular difference

    int circulardifference = 1440 - (minutes.back() - minutes.front());
    ans = min(ans, circulardifference);
    // minutes.back == largest time, minutes.front == smallest time
    return ans;
}

int main()
{
    vector<string> timePoints = {"21:59", "00:00"};
    int result = findMinDifference(timePoints);
    cout << "Minimum difference is : " << result << " Minutes" << endl;
    return 0;
}