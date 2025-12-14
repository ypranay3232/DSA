#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int answer = 0;   // Stores the best (maximum) minimum distance

// Compute minimum distance between consecutive cows
int getMinDistance(vector<int>& placement) {
    int minDist = INT_MAX;

    for (int i = 1; i < placement.size(); i++) {
        minDist = min(minDist, placement[i] - placement[i - 1]);
    }

    return minDist;
}

// Recursive function to generate all combinations
void placeCowsBruteForce(vector<int>& stalls, int k,
                         int index, vector<int>& current) {

    // If we placed all k cows
    if (current.size() == k) {
        int minDist = getMinDistance(current);
        answer = max(answer, minDist);
        return;
    }

    // If we exhausted stalls
    if (index >= stalls.size())
        return;

    // Choice 1: Place cow in current stall
    current.push_back(stalls[index]);
    placeCowsBruteForce(stalls, k, index + 1, current);
    current.pop_back();   // backtrack

    // Choice 2: Skip current stall
    placeCowsBruteForce(stalls, k, index + 1, current);
}

int aggressiveCowsBruteForce(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());

    vector<int> current;
    placeCowsBruteForce(stalls, k, 0, current);

    return answer;
}

int main() {

    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;

    cout << "Maximum minimum distance = "
         << aggressiveCowsBruteForce(stalls, k) << endl;

    return 0;
}
