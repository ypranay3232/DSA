Find the length of string ? we loop thorough it  


Question 2: Reverse a string 

ex: HELLO output would be : OLLEH
we can say that : the H is swapped with O and E with L ? 
we can use two pointer approach 

Question 3 : Replace all spaces 
ip = "Hello World"
we have one space between hello and world 

Now replace the spaces with "#"

expected ok : Hello#World

Question 4 : Palindrome 

A Palindrome is a string which results in same while reading from left - right and right - left
ex: dad, noon, racecar, LOL

How to code ? Approach 1) find reverse string and compare if both are equal 
Time and space = O(n)

Approach 2) using two pointers 
Noon 
i  j 
 ij
check if i ==j if yes then its a palindrome 