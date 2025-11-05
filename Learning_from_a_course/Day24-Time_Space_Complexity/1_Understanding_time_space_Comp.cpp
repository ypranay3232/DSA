/*
What is Time Complexity ? 
The Amount of Time taken by an algorithm to run as a function of length of input(.i.e. Cpu time utilization ) 

The lenght of input : ex: we write a for loop and input is dynamically given by user 
so the cpu runs the code N times as per input.


so we can say that Function(that cpu works) is directly proportional to N(input)
because as the N(input number increases) the function work also increases

So the Time Complexity is Big O (N): O(N)

What is Big O : Big O is a Mathematical Notation used to describe an algorithm space and time complexity indicating how the performance changes with size of input.

Why we use Big O : Because Cpus runs at different speed and we care about growth rate not exact time
So Big O gives us a worst case upper bound  " In Worst case my program takes this much time relative to n"


What is Space Complexity ? 
The amount of spcae taken by an Algorithm to run as a function of length of input
(.i.e. As  we increase the input size how much extra space it will take)


Time Complexity is a Metrics on What happens in the worst case " IN worst Case my program runs in this much time relative to n"

How to represent Complexity : we use some Units to represent a complexity

1) Big O : Upper Bound
2)Theta 0: Average Bound
3) Omega : Lower Bound

ex: we have an array [1,2,3,4,5,6] if we want to access [1] it would be Lower bound and Complexity is [O(1)] because we got number in least time, 

But if we want to access [6] Then our array go from [1,2,3,4,5] then finds [6] covers all possible values so It becomes worst case scenario [O(N)]  (.i.e. Upper Bound)

Average Bound : we want to access 3 from array so we can do as [n/2] so we can get to middle so the algorithm takes not too much time and not too less. (.i.e. it can take O(1) to O(N) time to run) 


Common Time Complexities : 

Complexity      	Shortcut Word	Meaning	                Real World Example
O(1)	            ConstantTime    Same time always	    Accessing an array element
O(log n)	        Log	Grows       slowly               	Binary search
O(n)	            Linear	        Proportional	        Loop through an array
O(n log n)	        nLog        	Moderate	            Merge sort, Quick sort (avg)
O(n²)	            Quad        	Grows fast          	Nested loops
O(2ⁿ)	            Exp         	Explodes fast	        Recursion in Fibonacci
O(n!)	            Fact        	Unusable for large n	Traveling salesman problem




1) Constant Time : O(1) : means algorithm is not depending on input and it runs at same time, for every time we run

2) Linear Time : O(N) : As we increase input size the Time increases Linearly 
ex: for(int i=0;i<n;i++) => here as N = 10 or N = 20 then the space and time also increases slowly with each iteration

3)Quadratic Time : O(n^2) and 4)Cubic Time O(n^3) : we use quadratic or cubic time: Everytime we use a nested loop (.i.e. We are running a input twice or thrice for every iteration )

ex: for(i=0;i<n;i++)
         for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                cout<<k;



-------------------------------------------
Examples on how to find complexities : 

F(n) = 2n^2 + 3n 

(The Big O representation of this is : first we check both parts : 2n^2 + 3n) 2n^2 is biggest so we take that as UpperBound : so 
2n^2 --> O(2n^2) --> O(n^2) (removed 2 which is constant)

N^2 + Log N : N^2 is greater so ==> O(N^2)

F(200) ==> O(200) ==> O(1) which is constant time because the input is static

F(n), F(M) ==> O(N+M) (if both loops are not nested we plus/add the complexities)


*/