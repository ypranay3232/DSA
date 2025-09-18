#include <iostream>
#include<limits>
using namespace std;

int main()
{
    while (true)
    {
        cout << "enter a number" << endl;
        int a; // a variable that stores the input value.
        // Now taking an input from user. (i.e we are taking only integer input from user via a)
        cin >> a;
        // now what we do it lets see if the number is even or odd.

        // Why we need it "first when ever we give an string nput here from cin>>  and that string input will be stored in input buffer (stdin) so that leftout string will trigger cin.fail() again and again."

        // so the cin.fail() checks the last/previously entered input is failed or not. if yes then it asks for valid input data. then after taking that input data it clears the previous input data (string) which is wrong and clears it.


        // cin.ignore() it ignores a certain no.of characters from input buffer until you reach a new line. ANd numeric_limits<streamsize>::max()  this tells to skip all until we find '\n'.

        // so if we dont clean that up we will just read the same string values from buffer again and again.
        if(cin.fail()){
            // if the condition fails here we just print a message to user.
            cout<<"Please enter a valid input" <<endl;
            cin.clear();//here the cin is still in error state so we have to clear it
            cin.ignore(numeric_limits<streamsize>::max(),'\n');//used to ignore un wanted characters from an input buffer. its states cin.ignore(up to where i should ignore,what to ignore); so ignore up to numeric_limits<streamsize>::max() maximum stream size (of a variable capacity) up to '\n'.
            continue;
        }

        if (a == 0)
        {
            // we  use " " to print 1 single space in between a printing statement. \t (tab) is so much of space 
            cout << "Entered number"<<" "<<a<<" "<<"is Zero\n";
        }
        else if (a < 0)
        {
            cout << "Entered numbers"<<" "<<a<<" "<< "is not accepted\n";
        }
        else if (a % 2 == 0)
        {
            cout <<"Entered Number"<<" "<<a<<" "<<"is an even number\n";
        }
        else
        {
            cout <<"Entered Number"<<" "<<a<<" "<<"is an Odd number\n";
        }
    }
    return 0;
}