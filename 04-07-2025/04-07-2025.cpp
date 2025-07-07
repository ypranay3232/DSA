// just want to practice the learnings.
#include <iostream>
using namespace std;

int main()
{
    // lets see how to calculate a product of two numbers
    int First_number, Second_number;
    int product;
    cout << "The sum of three numbers are : " << endl;
    cout << "Enter 'First_number' value : " << endl;
    cin >> First_number;
    cout << "Enter 'Second_number' Value" << endl;
    cin >> Second_number;

    product = First_number * Second_number;

    cout << "The product of both First and second numbers are : " << product << endl;

    // exercise : find and print the perimeter of a triangle

    int first_side, second_side, third_side, perimeter;
    cout << "The perimeter of a triangle is "<<endl;
    cout << "Enter the first side of the triangle : ";
    cin >> first_side;

    cout << "Enter the Second side of the triangle : ";
    cin >> second_side;

    cout << "Enter the Third side of the triangle : ";
    cin >> third_side;

    perimeter = first_side + second_side + third_side;
    cout << "The perimeter of a triangle is : " << perimeter << endl;
    

    // exercise : find the simple interest.
    // To find simple interest (SI) = Principle * Rate of Interest * Time Period/100

    cout << "To Find Simple Interest :  " << endl;
    int Principle_amt, Time_period, simple_interest;
    float Rate_of_interest;
    cout << "Enter The principle amount : " << endl;
    cin >> Principle_amt;
    cout << "Enter the Rate of Interest : " << endl;
    cin >> Rate_of_interest;
    cout << "Enter the time period : " << endl;
    cin >> Time_period;

    simple_interest = Principle_amt * Rate_of_interest * Time_period / 100;

    cout << "The Simple Interest is : " << simple_interest << endl;

    // exercise : to print N to 1.
    cout<<"Printing from N to 1"<<endl;
    int N;
    cout<<"Enter the value of N : "<<endl;
    cin>>N;
    for(int i=N;i>=1;i=i-1){
        cout<<i<<endl;
    }   

}