#include<iostream>
using namespace std;

// 1) shallow copy (Default): A shallow copy copies the values as is including the memory address.

// (.i.e. When we have a obj which contains a pointer which points to a memory location if we use shallow copy now both obj points to same memory location)

// The problem is when we modify one object both the original and copy gets effected. 

class DemoShallow{
    public:
    int* data;

    // Constructor 
    DemoShallow(int val){
        data = new int(val);
    }

    void show(){
        cout<<"Value "<<*data<<" Address "<<data<<endl;
    }

    // No copy constructor → shallow copy happens

    // Destructor
    ~DemoShallow(){
        delete data;
    }
};


// Deep copy : each obj get new memory location and copies actual values so each obj has its own memory
class DemoDeep{
    public:
    int* data;

    // Constructor
    DemoDeep(int val){
        data = new int(val);
    }

    // Deep copy constructor
    DemoDeep(const DemoDeep &obj){
        data = new int(*obj.data);
    }

    void show(){
        cout<<"Value "<<*data<<" Address "<<data<<endl;
    }

    // Destroyer
    ~DemoDeep(){
        delete data;
    }
};

int main(){

    cout<<" Shallow Copy "<<endl;

    DemoShallow obj1(10);
    // shallow copy
    DemoShallow obj2 = obj1;
    
    obj1.show();
    obj2.show();

    // now we modify the obj 2 (because both objects points to same memory both gets updated with new values)
    *obj2.data = 50;

    cout<<"After modifying"<<endl;
    obj1.show();
    obj2.show();


    cout<<"\n Deep Copy "<<endl;

    DemoDeep obj3(10);

    // Deep copy
    DemoDeep obj4 = obj3;

    obj3.show();
    obj4.show();

    // Modify obj2
    *obj4.data = 50;

    cout << "\nAfter modification:\n";
    obj3.show();  // NOT affected
    obj4.show();
}