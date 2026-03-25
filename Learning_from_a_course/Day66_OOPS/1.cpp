// OOP is a type of programming paradigm where everything is bind with classes and objects,
// an object contains two things 1) properties and behavior.
// A class is a user defined datatype thats acts as a blueprint for crating objects

#include <iostream>
#include <string> 
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
private:
  string gender;

public:
  string name;
  string breed;
  int weight;

  // 1. DEFAULT CONSTRUCTOR
  // If you don't write this, the compiler creates a hidden one for you.
  Animal() {
    cout << "Default Constructor Called!" << endl;
    name = "Unknown";
  }

  // 2. PARAMETERIZED CONSTRUCTOR
  // Used to set values right at the moment of creation.
  Animal(string name, string breed) {
    cout << "Parameterized Constructor Called!" << endl;
    this->name = name;
    this->breed = breed;
  }

  // 3. COPY CONSTRUCTOR
  // Pass by reference (&) is mandatory here to avoid infinite recursion.
  Animal(Animal& temp) {
    cout << "Copy Constructor Called!" << endl;
    this->name = temp.name;
    this->breed = temp.breed;
    this->weight = temp.weight;
  }

  // 4. DESTRUCTOR
  // Indicated by the tilde (~) sign. It takes no parameters.
  ~Animal() {
    cout << "Destructor Called for: " << name << endl;
  }

  string getter() {
    return gender;
  }

  void setter(string g) {
    gender = g;
  }

  void speak()
  {
    cout << "Bark" << endl;
  }

  void sleep()
  {
    cout << "all day" << endl;
  }

  void setweight(int weight){
    this->weight = weight;
  }
};

int main()
{
  // --- STATIC ALLOCATION ---
  cout << "--- Creating Static Dog ---" << endl;
  Animal dog; // Calls Default Constructor
  dog.name = "Spikey";

  // Using Parameterized Constructor
  Animal bulldog("Butch", "Bulldog");

  // Using Copy Constructor
  Animal dogCopy(bulldog); // Copies Butch's data into dogCopy

  // --- DYNAMIC ALLOCATION ---
  cout << "\n--- Creating Dynamic Dog ---" << endl;
  // 'ptr' is a pointer stored on the stack, pointing to an Animal on the heap
  Animal *dynamicDog = new Animal("Snoop", "Golden Retriever"); 

  cout << "Dynamic Animal Name: " << dynamicDog->name << endl;

  // first set the gender
  dog.setter("male");
  cout << "getting gender: " << dog.getter() << endl; 

  // Calling behaviors
  dynamicDog->speak();

  // --- CLEANUP ---
  cout << "\n--- Deleting Dynamic Dog ---" << endl;
  // For dynamic memory, we MUST call delete to trigger the Destructor.
  delete dynamicDog;

  cout << "\n--- End of Main (Static objects will be destroyed now) ---" << endl;
  // Static objects (dog, bulldog, dogCopy) are destroyed automatically 
  // in reverse order of creation when main() ends.
  
  return 0;
}