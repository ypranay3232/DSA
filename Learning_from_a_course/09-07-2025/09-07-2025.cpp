#include<iostream>
using namespace std;

int main(){
    // Exercise : check if a given triangle is valid or not
    // so the logic here is (as per mathematically a triangle is  valid only if it satisfies the condition : the any two sides length should be greater than the other side) so (A+B > c, B + C > A, A+C> B)
    cout<<"Checking if a given triangle is valid or not"<<endl;
    int A,B,C;
    cout<<"Enter the first side of the triangle : "<<endl;
    cin>>A;
    cout<<"Enter the Second side of the triangle : "<<endl;
    cin>>B;
    cout<<"Enter the Third side of the triangle : "<<endl;
    cin>>C;

    if(A+B > C && A+C > B && B + C > A){
        cout<<"The given values of each sides makes a valid triangle ! \n"<<endl;
    }else{
        cout<<"The given values of each sides does not make a valid triangle ! \n"<<endl;
    }

    // exercise : print even numbers from 1 to N. so here first we read input from N. and run a loop and start checking the N from 2(bcz even numbers start from 2) and if N =5( loops starts with 2 and prints it and then increment i = i +2, until i < = N) else stop.
    cout<<"Printing even number from 1 to N !"<<endl;
    int Num;
    cout<<"Enter any number you want even numbers up to."<<endl;
    cin>>Num;
    for(int i =2; i<= Num; i =i+2){
        cout<<"The Even numbers are : "<<i<<endl;
    }
    // to print odd numbers we start the i with 1.

    // exercise : print the maximum of three numbers.
    cout<<"\nChecking The maximum numbers from three"<<endl;
    int A1,B1,C1;
    cout<<"Enter the Value of A : "<<endl;
    cin>>A1;
    
    cout<<"Enter the Value of B : "<<endl;
    cin>>B1;

    cout<<"Enter the Value of C : "<<endl;
    cin>>C1;

    // now check the condition
    if(A1 == B1 && B1 == C1){
        cout<<"All numbers are equal ! "<<A1<<B1<<C1<<endl;
    }

    if(A1 > B1 && A1 > C1){
        cout<<"A is the Maximum number ! "<<A1<<endl;
    }else if (B1 > A1 && B1 > C1){
        cout<<"B is Maximum "<<B1<<endl;
    }else{
        cout<<"C is the Maximum "<<C1<<endl;
    }       
}