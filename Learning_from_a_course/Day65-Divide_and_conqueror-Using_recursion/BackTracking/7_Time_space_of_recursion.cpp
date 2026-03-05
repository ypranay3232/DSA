/*
-----------------------------------------------------
Finding Time and Space Complexity in Recursion
-----------------------------------------------------

General Rule:

1. Time Complexity
   = Number of recursive calls × work done per call

2. Space Complexity
   = Maximum recursion stack depth

Stack depth depends on how deep the recursion tree goes.

-----------------------------------------------------
1) Counting / Simple Recursion
-----------------------------------------------------

print(n){
    // base case
    if(n == 0) return;

    cout << n;

    print(n-1);
}

Recurrence:
T(n) = T(n-1) + k

Explanation:
Each call does constant work and calls one recursive function.

Time Complexity:
O(n)

Space Complexity:
O(n)
(because recursion stack goes n levels deep)


-----------------------------------------------------
2) Factorial
-----------------------------------------------------

fact(n){
    if(n == 0) return 1;

    return n * fact(n-1);
}

Recurrence:
T(n) = T(n-1) + k

Time Complexity:
O(n)

Space Complexity:
O(n)
(recursion stack depth = n)


-----------------------------------------------------
3) Power Function (2^n or a^n)
-----------------------------------------------------

power(a,n){
    if(n == 0) return 1;

    return a * power(a,n-1);
}

Recurrence:
T(n) = T(n-1) + k

Time Complexity:
O(n)

Space Complexity:
O(n)


-----------------------------------------------------
4) Check if Array is Sorted
-----------------------------------------------------

isSorted(arr, n){
    if(n == 1) return true;

    if(arr[n-1] < arr[n-2])
        return false;

    return isSorted(arr, n-1);
}

Recurrence:
T(n) = T(n-1) + k

Time Complexity:
O(n)

Space Complexity:
O(n)


-----------------------------------------------------
5) Fibonacci (Classic Recursion)
-----------------------------------------------------

fib(n){
    if(n <= 1) return n;

    return fib(n-1) + fib(n-2);
}

Recurrence:
T(n) = T(n-1) + T(n-2)

Time Complexity:
O(2^n)

Explanation:
Every function creates TWO new recursive calls.

Space Complexity:
O(n)
(max recursion depth)


-----------------------------------------------------
6) Binary Recursion Pattern
-----------------------------------------------------

func(n){
    if(n == 0) return;

    func(n-1);
    func(n-1);
}

Recurrence:
T(n) = 2T(n-1) + k

Time Complexity:
O(2^n)

Space Complexity:
O(n)


-----------------------------------------------------
7) Subsets / Power Set
-----------------------------------------------------

subset(i){
    if(i == n){
        print subset
        return;
    }

    // include element
    subset(i+1)

    // exclude element
    subset(i+1)
}

Total subsets:
2^n

Time Complexity:
O(n * 2^n)

Explanation:
2^n subsets
each subset takes O(n) to construct

Space Complexity:
O(n)
(recursion depth)


-----------------------------------------------------
8) Permutations
-----------------------------------------------------

permute(nums){

    if(nums.size() == 1)
        print permutation

    for(i = 0 → n){
        choose element
        permute(remaining)
    }
}

Total permutations:
n!

Time Complexity:
O(n * n!)

Explanation:
n! permutations
each takes O(n) to build

Space Complexity:
O(n)


-----------------------------------------------------
9) N Queens
-----------------------------------------------------

Place queens row by row.

At each row we try n possible columns.

Worst Case:
n choices × n levels

Time Complexity:
O(n!)

Space Complexity:
O(n)
(recursion stack)


-----------------------------------------------------
10) Generate Parentheses
-----------------------------------------------------

At each step we add '(' or ')'

But invalid states are pruned.

Total valid combinations =
Catalan Number

≈ 4^n / √n

Time Complexity:
O(4^n / √n)

Space Complexity:
O(n)


-----------------------------------------------------
11) Combination Sum
-----------------------------------------------------

We try including or excluding numbers.

Worst Case Branching:
2 choices per element

Time Complexity:
O(2^n)

Space Complexity:
O(n)


-----------------------------------------------------
12) Backtracking Template Complexity
-----------------------------------------------------

General Backtracking:

backtrack(level){
    for(choice in choices){
        choose
        backtrack(level+1)
        undo choice
    }
}

Time Complexity:
(branching factor) ^ (depth)

Space Complexity:
O(depth)


Example:

Subsets
branch = 2
depth = n
TC = O(2^n)

Permutations
branch = n
depth = n
TC = O(n!)

-----------------------------------------------------
Quick Summary
-----------------------------------------------------

Problem                Time Complexity      Space

Factorial              O(n)                 O(n)
Sorted Check           O(n)                 O(n)
Power                  O(n)                 O(n)
Fibonacci              O(2^n)               O(n)
Subsets                O(n * 2^n)           O(n)
Permutations           O(n * n!)            O(n)
N Queens               O(n!)                O(n)
Generate Parentheses   O(4^n / √n)          O(n)

-----------------------------------------------------
*/
