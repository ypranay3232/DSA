// OOP is a type of programming paradigm where everything is bind with classes and objects,
// an object contains two things 1) properties and behavior.
// A class is a user defined datatype thats acts as a blueprint for crating objects

#include <iostream>
using namespace std;

// The by default class contains some value its not empty, Because when we create a class we assign it the minimum possible value so that we can identify it in memory.
class demo
{
  // so if we add a datatype here ex : int (which takes 4 bytes)
  int type; // this now returns 4 bytes, but if we add more
  int x;
  char ch; // now after new value we get 12 (why ? int,int,char 4+4+1 = 9 how 12 ? )

  // here comes padding and greedy alignment : when we add different datatypes : int, char = 5 (we expect) but in reality "compiler adds 3 bytes of padding so that both int,char starts on 4 byte boundary"

  // greedy alignment : also know as memory packing which describes the compiler method for arranging data members(types) to minimize the total padding added.
};

class Animal
{
  // properties :
public:
  string name;
  string breed;

  void speak()
  {
    cout << "Bark" << endl;
  }

  void sleep()
  {
    cout << "all day" << endl;
  }
};

// now after creating an class to access it we need to create an obj which access the class

int main()
{
  // 1. Static Allocation (Stack)
  Animal dog;
  dog.name = "Spikey";

  // 2. Dynamic Allocation (Heap)
  // 'ptr' is a pointer stored on the stack, pointing to an Animal on the heap
  Animal *dynamicDog = new Animal();

  // Accessing properties via the arrow operator (->)
  dynamicDog->name = "Snoop";
  dynamicDog->breed = "Golden Retriever";

  cout << "Dynamic Animal Name: " << dynamicDog->name << endl;

  // Calling behaviors
  dynamicDog->speak();

  // 3.Manual Cleanup
  // Unlike 'dog', 'dynamicDog' will NOT be destroyed automatically.
  delete dynamicDog;

  return 0;
}
