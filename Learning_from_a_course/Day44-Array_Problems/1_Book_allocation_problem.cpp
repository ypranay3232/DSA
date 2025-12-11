/*
One of the most important Topic (book allocation problem)
*/

#include<iostream>
#include<vector>      // defines LLONG_MAX
#include<climits>
using namespace std;     // simplify names (std::)

 // compute sum of pages from index l to r (inclusive)
long long rangeSum(const vector<int>& pages, int l, int r) {
    long long sum = 0;                       // accumulator for the sum
    for (int i = l; i <= r; ++i) {           // iterate from l to r
        sum += pages[i];                     // add each pages[i] to sum
    }
    return sum;                              // return the computed sum
}

// try all ways to split books[start..n-1] into 'studentsLeft' contiguous parts
// returns the minimum possible maximum pages among the students for those books
long long bruteForceRec(const vector<int>& pages, int start, int studentsLeft) {
    int n = static_cast<int>(pages.size());  // number of books

    if (studentsLeft == 1) {                 // base case: only one student left
        return rangeSum(pages, start, n - 1); // that student takes all remaining books
    }

    long long best = LLONG_MAX;              // best (minimum) maximum found so far

    // we must leave at least (studentsLeft -1) books for the remaining students
    // therefore the splitEnd can go at most to n - studentsLeft
    for (int splitEnd = start; splitEnd <= n - studentsLeft; ++splitEnd) {
        long long currentSum = rangeSum(pages, start, splitEnd); // sum for current student
        long long nextMax = bruteForceRec(pages, splitEnd + 1, studentsLeft - 1); // best for rest
        long long allocationMax = max(currentSum, nextMax);      // maximum load for this allocation

        if (allocationMax < best) {        // if this allocation improves the best
            best = allocationMax;          // update best
        }
    }

    return best;                            // return best found for this subproblem
}

// public API: returns minimum possible maximum pages when dividing pages among m students
// returns -1 if impossible (more students than books)
long long bookAllocationBruteForce(const vector<int>& pages, int m) {
    int n = static_cast<int>(pages.size()); // number of books
    if (m > n) return -1;                   // impossible: not enough books
    return bruteForceRec(pages, 0, m);      // start recursion from index 0 with m students
}

int main() {
    ios::sync_with_stdio(false);            // fast IO: untie C and C++ IO
    cin.tie(nullptr);                       // fast IO: untie cin from cout

    // example input - change these values to test other cases
    vector<int> pages = {10, 20, 30, 40};   // pages in each book
    int m = 2;                              // number of students

    long long ans = bookAllocationBruteForce(pages, m); // compute answer

    if (ans == -1) {                        // handle impossible case
        cout << "Not possible (more students than books)\n"; // inform user
    } else {
        cout << "Minimum possible maximum pages = " << ans << '\n'; // print result
    }

    return 0;                               // exit program
}
