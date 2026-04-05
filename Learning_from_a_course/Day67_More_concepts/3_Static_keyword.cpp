#include<iostream>
using namespace std;

// first what happens without a static keyword ? when we create objects as obj1 and 2 each gets its own copy of memory. And this pointer tells which object data to use.

// Static : means "This belongs to the class not to individual objects" so instead of having a copy per obj we get a shared copy for all objects 
class Demo{
    public:
    int x;
};

// Example for static : this works as "count is not inside each objects rather in memory every object updates same variable  
class Demo1{
    public:
    static int count; // this count is shared by all objects
    Demo1(){
        count ++;
    }
};

// Static member functions: 
class Demo2{
    public:
    static int count;
    static void showcount(){
        cout<<count<<endl;
    }
};
int Demo2::count = 0;//for Demo2

int Demo1::count = 0;//This is defined outside the class and functions from Demo1

int main(){
    Demo obj1, obj2;
    obj1.x = 10;
    obj2.x = 20;
    cout<<obj1.x<<" "<<obj2.x<<endl;

    // static ex : 
    Demo1 obj13;
    Demo1 obj4;
    Demo1 obj5;

    cout<<Demo1::count<<endl;//prints 3

    // Demo 2 class static function ex: 
    Demo2 obj6;
    cout<<Demo2::count<<endl; 

}
