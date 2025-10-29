/*
Lets print The following pattern :
1
2 * 3
4 * 5 * 6
7 * 8 * 9 * 10
7 * 8 * 9 * 10
4 * 5 * 6
2 * 3
1

As we can see the order it's Increasing in order for each row but with a star in between and the other Half is just a reverse of first half.

*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter height: "<<endl;
    cin >> n;

    // First we decalre a global Counter (num) that keeps track of the sequence for top half
    int num = 1;

    // Upper half : works as. first we create a row and increment upto (N) and take the global counter as 'start'  and then we print columns and print's both row and cols same. And now we print the (number =1 ) the global number which is 1 and then if check if the cols<row (if yes then print "*") ofc yes (because we print cols as <= row) this prevent extra star at end of each element. then we increment the number we are printing so for next iteration when we print the num we get(2) instead of 1. 
    for (int i = 1; i <= n; i++) {
        int start = num;
        for (int j = 1; j <= i; j++) {
            cout << num;
            if (j < i) cout << " * ";
            num++;
        }
        cout << endl;
    }

    // Lower half (reverse)
    int total = num - 1;  // Here the number became 11 because our last printed digit in upper half was 10 so we decrement it by 1 to make it 10. And here row(i) runs in decrement order so (10 to 1)
    for (int i = n; i >= 1; i--) {
        int start = total - i + 1;
        // Total = last number we printed till now, and i = how many numbers we print in this row. So now we printed up to 10. And we have to print 4 in this row +1 (so : 10-4+1 = 7) so we print from 7,8,9,10
        for (int j = 0; j < i; j++) {
            cout << start + j; // start = 7 and j = 1 so we use a conditon (if j< row-1) = 0 so print a star
            if (j < i - 1) cout << " * ";
        }
        cout << endl;
        total -= i; // This moves the Pointer backwards to end of previous row
    }
}
