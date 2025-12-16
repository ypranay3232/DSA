/*
PRoblem :
jack need to chop down m meters of wood. It's an easy job for him because he has a new wood cutting machine that can take forest like wildfire, But jack is allowed to cut a single row of trees


Jack machine works as :
Jack set a height (H)in meters , then machine raises the sawblade of that height and cut the trees higher than the sawblade height.

jack takes the chopped wood ex: A Tree row contains [20,15,10,17] sawblade raised to 15meters
so chopped wood will be 20,15,17. Because sawblade can cut more than 15 meters.


Jack cares about environment so he wont cut more wood than necessary

so Find maximum height of sawblade that allows jack to cut atleast m meter of wood(how much he need)

ASSUME :

Jack needs wood (M) = 7 meters
He raised sawblade to (H) = 15  meters

Trees are = 20,15,10,17

since he cuts trees with a 15m height blade he gets wood as :
(20-15) + (15-15) + (17-15) (ignore 10 became tree 10 is less than sawblade range (15))
5+0+2 = 7meters

jack got his wood of 7meters and saved environment without cutting whole tree



1. Problem Statement :

You are given:

N trees

Each tree has a height arr[i]

You need at least M units of wood

You cut all trees at the same height H.

Rule

If a tree height is x and x > H
→ you collect (x - H) wood

If x ≤ H
→ you collect 0 wood

Goal : Find the maximum height H such that total collected wood ≥ M



Example
N = 4
M = 7
trees = [20, 15, 10, 17]

Try some heights
Cut Height (H)	Wood Collected
15	(20-15)+(17-15)=7
16	(20-16)+(17-16)=5
14	(20-14)+(15-14)+(17-14)=10

Best possible height = 15

Brute Force Idea :

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ekoBruteForce(vector<long long> &trees, int M)
{

    int maxHeight = *max_element(trees.begin(), trees.end());
    int bestHeight = 0;

    // Try every possible cutting height
    for (int H = 0; H <= maxHeight; H++)
    {

        long long woodCollected = 0;

        // Calculate wood collected at height H
        for (int i = 0; i < trees.size(); i++)
        {
            // check if current tree is greater than height if yes cut else don't

            if (trees[i] > H)
            {
                woodCollected += (trees[i] - H);
            }
        }

        // If enough wood is collected, update answer
        if (woodCollected >= M)
        {
            bestHeight = H;
        }
    }

    return bestHeight;
}

// Optimised solution using Binary search :
bool isoptimisedSolution(vector<long long> &inputTrees, long long int m, long long int mid)
{
    long long int woodcollected = 0;
    for (int i = 0; i < inputTrees.size(); i++)
    {
        if (inputTrees[i] > mid)
        {
            woodcollected += inputTrees[i] - mid;
        }
    }
    return woodcollected >= m;
}

long long int MaxSawBladeHeight(vector<long long> &inputTrees, long long int m)
{
    long long int start = 0, end, mid, ans = -1;
    end = *max_element(inputTrees.begin(), inputTrees.end());

    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        if (isoptimisedSolution(inputTrees, m, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{

    vector<long long> trees = {20, 15, 10, 17};
    long long M = 7;

    cout << "Brute Force Result:" << endl;
    cout << "Maximum cutting height = "
         << ekoBruteForce(trees, M) << endl;

    // Binary search solution :
      long long n, m;

    cout << "Enter number of trees (N): ";
    cin >> n;

    cout << "minimum wood Jack required (M): ";
    cin >> m;

    vector<long long> inputTrees;

    for (int i = 0; i < n; i++)
    {
        long long height;
        cout << "Enter height of tree " << i + 1 << ": ";
        cin >> height;
        inputTrees.push_back(height);
    }

    cout << endl;
    cout << "Optimized (Binary Search) Result:" << endl;
    cout << "Maximum cutting height = "
         << MaxSawBladeHeight(inputTrees, m) << endl;

// No of trees = 4
// minimum wood jack need is = 7
// enter tree1,2,3,4 size = 20,15,10,17
    return 0;
}
