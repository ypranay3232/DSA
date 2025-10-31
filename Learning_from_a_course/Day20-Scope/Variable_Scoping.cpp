/*
    Lets see what are variable scopings : 
*/
#include<iostream>
using namespace std;
int global = 100;

int main(){
    int a; //declaration
    int b = 10;// inititalization 
    b = 20;//modification/upadtion
    // But we can't re-declare a variable : ex : 

    // int b = 30;// Throws error because we can update a declared variable, cant re declare it. 
    // But we re-declared the same inside if condition right ? so how did that worked ? because it is inside if condition scope (.i.e. it is inside another scope not under main() scope) and if we re declare the (B) it throws error. 

    cout<<b<<endl;
    // But if i write the same here  as: 
    if(true){
        // so the B inside if conditon is valid until its inside the if, once exitted from it the value is destroyed, so the (B) inside if is local variable and (B) in main program is Main method var
        int b = 10;
        cout<<b<<endl;

        // int b =30;
        // cout<<b<<endl;

        cout<<global<<endl;//Prints the same value each time no matter the scope
    }

    cout<<b<<endl;//This prints value of main method
    cout<<global<<endl;;//Prints the same value each time no matter the scope
}