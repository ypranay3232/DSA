#include <iostream>
#include <cstring>
using namespace std;

// Time : O(N) becasue the loop is checking each character from the array so if array is N time would be N.
// Space : (1) constant.
int getlentgh(char name[])
{
    int length = 0;
    int i = 0;
    //   Until the name[i] does not equal to null char we loop
    while (name[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}

// Question 2 : Reverse a string
// Time : O(n) becasue we are using 1 loop to iterate and for N size array we are performing n/2 operations (i,j) (n/2 = linear)
void ReverseString(char name[])
{
    // What do we need to reverse a string in two pointer approach : starting and ending index
    int i = 0; // first index
    int n = getlentgh(name);
    int j = n - 1; // last index

    // The condition is loop til i is less than j if i > j stop (If not we may swap infinitely )then swap both positions and increment i and decrement j

    // while(i<=j){
    //     swap(name[i],name[j]);
    //     i++;
    //     j--;
    // }
    // Same with For loop
    for (; i <= j;)
    {
        swap(name[i], name[j]);
        i++;
        j--;
    }
}

// Question 3 : replace spaces (loop thorough the array until you find a null character)
void ReplaceSpaces(char sentence[])
{
    int i = 0;
    int n = strlen(sentence);
    for (int i = 0; i < n; i++)
    {
        if (sentence[i] == ' ')
        {
            sentence[i] = '#';
        }
    }
}
// Question 4: Palindrome 
// Time space : O(n), O(1) 
bool CheckPalindrome(char palindrome[]){
    int i=0;
    int n= strlen(palindrome);
    int j = n-1;

    // now loop the array til i >j once i>j stop, and check the condition is (I == j)
    while(i<=j){
        if(palindrome[i] != palindrome[j]){
            return false;
        }else{
            // if the i == j then move to next index to check (inc i and dec j)
            i++;
            j--;
        }
    }
    // return true if the entire loop is executed 
    return true;
}
int main()
{
    char name[100];
    cout<<"Enter your name:"<<endl;
    cin >> name;

    cin.ignore(1000,'\n');


    cout << "Length is " << getlentgh(name) << endl;
    // we have a in built function to calculate the length called strlen
    cout << "Length is " << strlen(name) << endl;
    // cout << "Length is " << strlen(name1) << endl;
    // Some inbuilt common functions : strcmp
    // strcmp(name, name1);

    cout << "Initial array : " << name << endl;
    ReverseString(name);
    cout << "After reversing the string " << name << endl;

    char sentence[100];
    cout<<"Enter a sequence with space "<<endl;
    cin.getline(sentence,100);
    // Here we took input from getline because it accepts spaces unlike cin which break after a encountering a space so you can never have input with spaces 
    ReplaceSpaces(sentence);
    cout<<"Printing Sequence : "<<endl<<sentence<<endl;
    
    char palindrome[100] = "BOB";
    cout<<"Palindrome check : "<<CheckPalindrome(palindrome)<<endl;


    return 0;
}