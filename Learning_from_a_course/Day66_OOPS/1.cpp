// OOP is a type of programming paradigm where everything is bind with classes and objects, 
// an object contains two things 1) properties and behavior. 
// A class is a user defined datatype thats acts as a blueprint for crating objects

#include <iostream>
#include <string>
using namespace std;

class MyClass {       
  public:            
    int myNum;        
    string myString; 
};

int main() {
  MyClass myObj; 

  myObj.myNum = 15;
  myObj.myString = "Some text";

  cout << myObj.myNum << "\n"; 
  cout << myObj.myString; 
  return 0;
}
