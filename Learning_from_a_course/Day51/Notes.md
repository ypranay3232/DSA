Character datatype takes 1 byte storage and to create a character array we do it as : 
char ah[10]; this create a array of 10 used to store char values

signed chart range = -2^7 - 2^7-1 = -128 - 127
unsigned char = 0- 2^8-1

How to take input in a character array 
we can take it in two ways 

1> input for entire array look at the code  (sequence input ex: name)
rather than having input of each character one by one we can take it as sequence 

2> take input for a specific index 


We have an issue with method 1 : 
when we take input as whole : such as "cin>>ch;" -->"demo" at the end of the name (demo_) a null character
is stored. Null character represents the string termination 

to fix we use getline()