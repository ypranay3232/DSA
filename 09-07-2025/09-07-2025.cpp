#include<iostream>
using namespace std;

int main(){
    // Exercise : check if a given triangle is valid or not
    // so the logic here is (as per mathematically a triangle is  valid only if it satisfies the conditon : the any two sides length should be greater than the other side) so (A+B > c, B + C > A, A+C> B)
    cout<<"Checking if a given triangle is valid or not"<<endl;
    int A,B,C;
    cout<<"Enter the first side of the triangle : "<<endl;
    cin>>A;
    cout<<"Enter the Second side of the triangle : "<<endl;
    cin>>B;
    cout<<"Enter the Third side of the triangle : "<<endl;
    cin>>C;

    if(A+B > C && A+C > B && B + C > A){
        cout<<"The given values of each sides makes a valid triangle ! "<<endl;
    }else{
        cout<<"The given values of each sides does not make a valid triangle ! "<<endl;
    }


}