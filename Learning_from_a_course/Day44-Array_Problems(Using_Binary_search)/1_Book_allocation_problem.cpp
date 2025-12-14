/*
One of the most important Topic (book allocation problem)

The problem is :
Each book will be allocated to exactly one student, and each student will have exactly one book

NOTE: The book allocation must be contiguous.

given an array(array of books) : Contains no of pages so (a[i] shows the no of pages in the book)

arr = [12,34,67,90]
        0  1  2  3
12,34,67,90 are pages of each book

we have m students (2)
SO, how many possible combinations can we do with 4 books and 2 students of

(12) for student 1
(34,67,90) for student 2

or

(12,34) for sequent 1
(67,90) for student 2

or

(12,34,67) for student 1
(90) for student 2

NOTE: the condition is when we allocate books to student we have to allocate num of pages

ex:
approach 1 : student 1 (12)  pages so sum = 12
and student 2 = (34,67,90) total no of pages(sum) = (191)

approach 2 : student 1 (12,34) sum = 46
 and student 2(67,90) total no of pages(sum) = (157)

approach 3 : student 1 (12,34,67) sum = 113
and student 2 (90) sum = 90

so we have to take approach 3 because we have to take the minimum of average from all permutations


ASSUME : if no of students > no of books, so return -1.

The solution can be coded as :
1) brute force
2) Define a search Space
start from 0 to 203 (total no of pages)

so our all approaches mum is in between (the 0- 203) so we search in this search space
Use binary search !


*/

#include <iostream>
#include <numeric>
#include<algorithm>
#include<climits>
#include <vector>
using namespace std;

bool ispossiblesolution(const int a[], int books,int students,long long maxpagesalllowed){
  long long pagesum = 0;
  long long requiredstudents = 1;

  for(int i =0;i<books;i++){
    // if current book contains more pages than solution (mid) then the book cant be allocated
    if(a[i]>maxpagesalllowed){
        return false;
    }
    // if pagesum + current book sum (dent allocate )
    if(pagesum + a[i]>maxpagesalllowed){
        ++requiredstudents;
        pagesum = a[i];
        // if allocations is done more than books 
        if(requiredstudents>students){
            return false;
        }
    }
    else{
        pagesum += a[i];
    }
  }  
  return true;
}


long long findPages(int a[], int books, int students)
{
    if (students > books)
    {
        return -1;
    }

    // We use binary search
    long long start = *max_element(a, a + books);
    // To get sum for end : we use accumulate c++ template it takes starting arr, ending, initial
    // array smart = 0, end = arr - books (because books are stored array )
    long long end = accumulate(a, a + books, 0LL);//0LL to take results in long
    long long ans = -1;

    while(start<=end){
        long long mid = start + (end - start)/2;
        // check if current mid is possible solution 
        if(ispossiblesolution(a,books,students,mid)){
            // if yes store result 
            ans = mid;
            end = mid -1;
        }
        else{
            // if its not the possible solution the we find result at right side
            start = mid + 1;
        }
    }
    return ans;
}


// brute force recursion: compute minimal possible maximum pages for allocating
// books[i..n-1] among remainingStudents students
long long bruteRec(const vector<int>& a, int i, int remainingStudents) {
    // if we're at last student, they get all remaining books -> return their sum
    if (remainingStudents == 1) {
        long long s = 0;                              // accumulator for sum
        for (int k = i; k < (int)a.size(); ++k) s += a[k]; // sum all remaining books
        return s;                                     // that is the max for this partition
    }

    long long best = LLONG_MAX;                       // best (minimum) among options
    long long currSum = 0;                            // running sum for current student

    // place a cut after position j (i <= j < n - remainingStudents + 1)
    // ensure there are enough books left for remainingStudents-1 students
    for (int j = i; j <= (int)a.size() - remainingStudents; ++j) {
        currSum += a[j];                              // accumulate pages for current student
        long long next = bruteRec(a, j + 1, remainingStudents - 1); // solve rest
        long long candidate = max(currSum, next);    // maximum pages among students in this partition
        best = min(best, candidate);                 // keep the best (minimum) max
    }
    return best;                                      // return minimal possible maximum
}

long long bruteForce(const vector<int>& a, int students) {
    int n = a.size();                                 // number of books
    if (students > n) return -1;                      // impossible
    return bruteRec(a, 0, students);                  // start recursion
}



int main(){
    int books = 4;
    int students = 2;
    int a[] = {12,34,67,90};
    vector<int> a1 = {12, 34, 67, 90};

    long long result = findPages(a,books,students);
    cout<<"The Book allocation for each student is : "<<result<<endl;

   long long result1 = bruteForce(a1, students);
    cout<<"The Book allocation for each student is : "<<result1<<endl;

    return 0;
}