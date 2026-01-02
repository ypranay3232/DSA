#include<iostream>
#include<string>

using namespace std;

int main(){
    // create a string 
    string str;
    cout<<"Enter input with space "<<endl;
    // cin>>str;//if input is hello world but we can only see hello because of cin property it only detects upto a delimiter(such as " " or "\0" or ) cin ends.
    // to fix we use
    
    getline(cin,str);

    cout<<str;
    // To find the length of a string we use length()
    cout<<"The Length of entered string is : "<<str.length()<<endl;
    // check if a string is empty or not returns bool values 0 or 1
    cout<<"Is the string empty : "<<str.empty()<<endl;
    // another Function that adds a new character at the end of the string 
    str.push_back('y');
    cout<<str<<endl;
    // But adds only a single character if i want to add more than 1 character i can use += operator
    str += "This is gonna add at the end ";
    cout<<str<<endl;
    // same as push back we can also remove a single element at end of character 
    str.pop_back();
    cout<<"removed a letter at end "<<endl;
    // to make a substring we use substr(start,end) returns the starting and ending substring 
    cout<<"The substring is : "<<str.substr(0,10);

}