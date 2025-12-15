/*
PRoblem :
jack need to chop down m meters of wood. It's an easy job for him because he has a new wood cutting machine that can take forest like wildfire, But jack is allowed to cut a single row of trees


Jack machine works as :
Jack set a height (H)in meters , then machine raises the sawblade of that height and cut the trees higher than the sawblade height.

jack takes the cut of parts.


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
#include<algorithm>
using namespace std;

int ekoBruteForce(vector<int> &trees, int M)
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

int main()
{

    vector<int> trees = {20, 15, 10, 17};
    int M = 7;

    cout << "Maximum cutting height = "
         << ekoBruteForce(trees, M) << endl;

    return 0;
}
