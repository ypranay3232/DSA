#include<iostream>
using namespace std;

int main(){
    // Implicit type conversion/casting
    char ch = 97;
    cout<<ch<<endl;

    // we can also do it as :
    int num = 'a';
    cout<<num<<endl;
    //The compiler returned the ASCII value of the character(American standard code for information interchange)

    // Lets see how to do explicit type casting.

    double values = 5.21;
    // works as we declared a double variable and we created a int variable and converted double variable to int.
    int values1 = (int)values + 20;
    cout<<values1<<endl;
    
    // Operators in C++
    // 1. Arithmetic operators:

    int First_number = 5;
    int Second_Number = 3;

    cout<<"The Addition of two numbers is : "<<First_number + Second_Number<<endl;
    cout<<"The Subtraction of two numbers is : "<<First_number - Second_Number<<endl;
    cout<<"The Multiplication of two numbers is : "<<First_number * Second_Number<<endl;
    cout<<"The Division of two numbers is : "<<First_number / Second_Number<<endl;
    // We have an interesting part here when we divide the  integer with an integer we get integer as output so when we do as 5%3 --> 1.66. so compiler ignored the decimal value because we get integer value. and when we divide float with int we get float and when we do int with double we get double. (i.e the biggest datatype dominates the output) 

    cout<<"The Modulus or absolute value of two numbers is : "<<First_number % Second_Number<<endl;
    // so if we do it as like this : 
    cout<<(5.0)/3<<endl;//Now we get output value in decimal so the biggest datatype dominates result.

    // we can also do some typecasting here.
    cout<<((float)5)/3<<endl;



    // Relational Operators.

    int fd = 5;
    int sd = 3;
    cout<<"Relational Operators"<<endl;
    cout<<(fd<sd)<<endl;//0 --> False and 1 --> True.
    cout<<(fd>sd)<<endl;//0 --> False and 1 --> True.
    cout<<(fd==sd)<<endl;//0 --> False and 1 --> True.
    cout<<(fd!=sd)<<endl;//0 --> False and 1 --> True.
    cout<<(fd<=sd)<<endl;//0 --> False and 1 --> True.
    cout<<(fd>=sd)<<endl;//0 --> False and 1 --> True.

    // Assignment Operators.

    cout<<"Assignment Operators"<<endl;
    cout<<(fd+=sd)<<endl;//Add's fd + sd and stores result in fd. so fd == 8;
    cout<<"The fd value is : "<<fd<<endl;
    cout<<(fd-=sd)<<endl;//prints 5 because we just updated the fd as 5+3 = 8 so now fd(8)-3(sd) = 5; 


    // Logical operators.
    cout<<"Logical operators"<<endl;
    string citizen = "indian";
    int age = 18;
    bool Phonepe = 0;//Bool 0 --> false and 1--->true;
    bool Gpay = 0;//Bool 0 --> false and 1--->true;
    if (age>= 18 && citizen == "indian"){
        cout<<"You can vote"<<endl;
    }
    if(Phonepe || Gpay == 1){
        cout<<"you can buy things"<<endl;
    }else{
        cout<<"No money in Bank"<<endl;
    }

    // // ! --> not operator it works opposite on a condition so : if not phone : no such app in phone else link acc
    // bool Phonepe1 = 1;
    // if(!Phonepe1){
    //     cout<<"No Such app installed in your phone"<<endl;
    // }else{
    //     cout<<"link bank Account"<<endl;
    // }
    return 0;
}