// you have planned for a vacation one year in advance,the days of year in which you will travel will be given as an integer array, each day is represented from 1 to 365

// Train tickets are sold as : 1 day pass = cost[0], 7 days cost [1] 30 days cost[2]

// ex: if you take 7days pass on day 2 you can travel 7 days (2nd on the day itself,3,4,5,6,7,8)

// return the minimum no of cost you need to travel every day given in list of days

// ex: if you want to travel tomorrow and next week (2days) whats the ideal choice you make ? ofc take daily pass (on tomorrow and on the day itself for next week) we wont take 7days pass nor 30days

// ex: we want to travel  on days [1,4,6,7,8,20] so : on day 1 you buy 1 day pass (cost $2) then on day3 you buy 7 days pass which covers from (3,4,5,6,7,8,9) cost[$7] and again on day 20 you take one day pass $2, in total (11$)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    // create an array that stores min cost up to day i
    int min_cost_to_travel[366] = {0};

    // now get look up the travel days using boolean array
    bool isTravelDay[366] = {false};
    for (int x : days)
        isTravelDay[x] = true;

    for (int i = 1; i <= 365; i++)
    {
        // if we dont travel today the travel cost should be same as
        // yesterday
        if (!isTravelDay[i])
        {
            min_cost_to_travel[i] = min_cost_to_travel[i - 1];
            continue;
        }

        // else : find the option of 3 tickets
        int cost1 = min_cost_to_travel[i - 1] + costs[0];
        int cost7 = min_cost_to_travel[max(0, i - 7)] + costs[1];
        int cost30 = min_cost_to_travel[max(0, i - 30)] + costs[2];

        min_cost_to_travel[i] = min({cost1, cost7, cost30});

        if (i == days.back())
            return min_cost_to_travel[i];
    }
    return min_cost_to_travel[days.back()];
}


int main(){
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
    cout<<"The Min cost to travel on days "<<mincostTickets(days,costs);
    return 0;
}