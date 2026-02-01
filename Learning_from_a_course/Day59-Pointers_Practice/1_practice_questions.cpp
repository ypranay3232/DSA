#include <iostream>
using namespace std;

int main()
{

    // what is the output of the following !

    // float f = 10.5;
    // float p= 9.5;

    // float* ptr = &f;//assigned the address of f to ptr.
    // (*ptr)++;//this *ptr goes to f and increments it. (11.5)
    // *ptr = p; //now assign ptr with p value.  so ptr == p, the ptr points to f so f value gets updated with p (9.5)
    // cout<<*ptr<<" "<<f<<" "<<p;

    // int a = 7;
    // int b = 10;
    // int*c = &b;//c points to b.
    // *c = 1; //so when it is assigned with 1, c overwrites b value (10) with 1.
    // cout<<a<<" "<<b<<endl;

    // int *ptr = 0;//a pointer points to null
    // int a = 10;
    // *ptr = a;//this prints error run time error
    // cout<<a<<endl;

    // char ch = 'a';
    // char *ptr = &ch;
    // ch++;//ASCI value of 'a' is 65 if we do ++ we get 66 which is asci value of 'b'
    // cout<<*ptr<<endl;//prints 'b'

    // int a = 7;
    // int *c = &a;//c points to a.
    // c = c+1;//if we do c+1 ('a' address + 1 it returns some random integer number in memory so : 'a' address + 1 (.i.e. 4 because int tabes 4 bytes))
    // cout<<a<<" "<<*c<<endl;//prints a (7) and *c (address of a+1)

    // int a = 7;
    // int *c = &a;
    // c = c + 3;//here c + 3 (c stores address of a. ex : a address = 400. and we do + 3 to 400, each array = 4 bytes. so : 400 + (3*4) = 412)
    // cout<<c<<endl;//c prints 412 not any garbage or random address unlike last question because we are printing c not *c ! (as per theoretical)

    // double a = 10.54;//double takes 8 bytes.
    // double *d = &a; //*d = address of a
    // d = d + 1;//a address + 1 so : ex : a address = 200 : 200 + (1*8) = 208
    // cout<<d<<endl;

    // int a[5];
    // int *c;
    // cout<<sizeof(a)<<" "<<sizeof(c);//size of int a array = int size (4) and array = 5 so (4*5 = 20)and size of *c is (pointer size is 4 or 8 bytes according to machine)

    // int a[]  = {1,2,3,4,5};
    // cout<<*(a)<<" "<<*(a+1);//*a always points to the base/starting address of an array so index 0 and *a+1 prints 2 so : 1+2

    // // Assume that address of 0th index of array 'a' is : 200, what is the output :
    // int a[3] = {1,2,3};
    // cout<<*(a+2)<<endl;//this points to *a+2 (*a == initial address '0')so 0+2 =2 2nd index and it points to the value not address so we return the value ! as (3)

    // int arr[] = {4,5,6,7};
    // int *p = (arr+1);//stores arr+1 value (4+1 = 5)
    // cout<<*p<<endl;
    // cout<<*arr+9<<endl;//this points to the value of arr + 9 : 4+ 9 = 13
    // return 0;

    // char b[] = "xyz";//char b array with size 2
    // char *c = &b[0];//pointer c points to address of index 0
    // cout<<c<<endl;//now print the it, it prints the whole array until it gets an null pointer.

    // char s[] = "hello";
    // char *p = s;//pointer p points to s (starting address)
    // cout<<s[0]<<" "<<p[0]<<endl;//s[0] prints value 0, and p[0] also points to base address so prints 'h'


    // char arr[20];
    // int i;
    // for (i = 0; i < 10; i++)
    // {                        // loop til 10
    //     *(arr + i) = 65 + i; // point to arr of i (0) starting address then assign it with (65 + i (0)) because its a character array 65 == "A"

    //     // again in another iteration, when i = 1 we get (65 + i(1) for index 1, then 67 for index 2 .... )
    // }
    // // now after finishing the loop at index 9, (i < 10) at index 10 we add this null pointer so the printing could end at index 9, and we dont get any garbage value !
    // *(arr + i) = '\0';
    // cout << arr << endl;
    // return 0;


    // char *ptr;
    // char str[] = "abcdefg";
    // ptr = str;//ptr = str
    // ptr +=5;//ptr + 5 (ptr points to base address so 0 + 5 = 5)
    // cout<<ptr<<endl;//so ptr = 5, so we start from index 5 (fg)
    // return 0;
    

    // int numbers[5];
    // int *p;
    // p = numbers;
    // *p = 10;//*p = 10, p is pointing to initial index(0)
    // p = &numbers[2];//p points to index 2 in array 
    // *p = 20;//now throw 20 in index 2
    // p--;//then do -- (i.e. it go to index 1)
    // *p = 30;//assign 30 there so till now : arr[10,20,30]
    // p = numbers + 3;//now go to index 3, p = numbers(this numbers point to base index) + 3 = 3
    // *p = 40;//index 3 = 40 so : [10,20,30,40]
    // p = numbers;//now point the p with base address so p = numbers(0)
    // *(p+4) = 50; // now go to *(p+4) and assign 50.
    // for(int n = 0;n<5;n++){ //now print the array 
    //     cout<<numbers[n]<< ",";
    // }
    // return 0;


    // char st[] = "ABCD";
    // for(int i  = 0; st[i] != '\0'; i++){
    //     cout<<st[i]<<*(st)+i<<*(i+st)<<i[st];
    //     // A <<65<<A<<A
    // }
    // return 0;


    float arr[5] = {12.5,10.0,13.5,90.5,0.5};
    float *ptr1 = &arr[0];//ptr1 points to index 0 = 12.5
    float *ptr2 = ptr1 + 3;//ptr2 points to ptr1 + 3 = 90.5
    cout<<*ptr2<<endl;//print ptr 2, which points to ptr1+3 = (90.5)
    cout<<ptr2 - ptr1;//print ptr2 - ptr1 = pointer arithmetic returns answer with 4 byte chunks so 3 (3's) = 3
    return 0;


}