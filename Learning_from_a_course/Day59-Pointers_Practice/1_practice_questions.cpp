#include<iostream>
using namespace std;

int main(){

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

    int a[]  = {1,2,3,4,5};
    cout<<*(a)<<" "<<*(a+1);//*a always points to the base/starting address of an array so index 0 and *a+1 prints 2 so : 1+2
}