/*
Painters partition problem : 

You are given:
N boards, each with a certain length

K painters

Each painter:

paints only continuous boards

paints at same speed

A board cannot be split

Goal

Minimize the maximum time taken by any painter.
Example : 

Boards = [10, 20, 30, 40]
Painters = 2
output : 60
Why?

Best partition:

Painter 1 → [10, 20, 30] → total = 60

Painter 2 → [40] → total = 40
Maximum time = 60 (minimum possible)


Approach 1: 
Brute Force (Try All Partitions)

Generate all possible ways to divide boards into K continuous parts

For each partition:

Calculate total time per painter

Take the maximum

Return the minimum of these maximums


Brute Force Idea (Conceptual)

For [10,20,30,40] and K=2:

Possible partitions:

[10] | [20,30,40] → max = 90
[10,20] | [30,40] → max = 70
[10,20,30] | [40] → max = 60  ← best

Time Complexity
Exponential (O(N^K)) – NOT acceptable

Brute Force Code 

 
*/

#include<iostream>
#include<vector>
using namespace std;

// Function to calculate max workload for a given partition
int getMax(vector<int>& arr, vector<int>& cuts) {

    int maxTime = 0;     // This will store the maximum time taken by any painter
    int currSum = 0;     // This stores the total length painted by the current painter
    int index = 0;       // Pointer to track which cut we are currently processing

    // Loop through each board
    for (int i = 0; i < arr.size(); i++) {

        // Add current board length to current painter's workload
        currSum += arr[i];

        /*
            IMPORTANT CONDITION:
            --------------------
            1) index < cuts.size()
               → Ensures we do not access out of bounds

            2) i == cuts[index]
               → Means "this board index is a cut point"
               → So we should end the current painter's work here
        */
        if (index < cuts.size() && i == cuts[index]) {

            // Update maximum time among all painters
            maxTime = max(maxTime, currSum);

            // Reset workload for next painter
            currSum = 0;

            // Move to the next cut
            index++;
        }
    }

    // Handle the last painter (after the final cut)
    maxTime = max(maxTime, currSum);

    return maxTime;
}

int main() {

    // Board lengths
    vector<int> boards = {10, 20, 30, 40};

    // Cut after index 1 → [10,20] | [30,40]
    vector<int> cuts = {2};

    // Call the function
    int result = getMax(boards, cuts);

    // Print the result
    cout << "Maximum time taken by any painter = " << result << endl;

    return 0;
}