// OOP is a type of programming paradigm where everything is bind with classes and objects, 
// an object contains two things 1) properties and behavior. 
// A class is a user defined datatype thats acts as a blueprint for crating objects

#include<iostream>
using namespace std;

// The by default class contains some value its not empty, Because when we create a class we assign it the minimum possible value so that we can identify it in memory.
class demo{
  // so if we add a datatype here ex : int (which takes 4 bytes)
  int type;//this now returns 4 bytes, but if we add more 
  int x;
  char ch;//now after new value we get 12 (why ? int,int,char 4+4+1 = 9 how 12 ? )

  // here comes padding and greedy alignment : when we add different datatypes : int, char = 5 (we expect) but in reality "compiler adds 3 bytes of padding so that both int,char starts on 4 byte boundary" 
  
  // greedy alignment : also know as memory packing which describes the compiler method for arranging data members(types) to minimize the total padding added. 
};

class Animal{
  // properties : 
  public:
    string name;
    string breed;

  void speak(){

  }

  void sleep(){

  }
};

// now after creating an class to access it we need to create an obj which access the class

int main(){
  cout<<"The size of the class is : "<<sizeof(demo)<<endl;

  // obj creation can be done in 2 ways static and dynamic
  Animal dog;

  dog.name = "spikey";
  dog.breed = "husky";
  cout<<"Animal breed is "<<dog.breed<<endl;
  cout<<"Animal name is "<<dog.name<<endl;//we cant access this default because its private, so we make the class properties public
  // dynamic obj

  return 0;
}