// Can constructor (cotr) and destructor (dtor) made private ? yes
#include <iostream>
using namespace std;

// throws error if we directly make a ctor private

// Class A{
//     private:
//     A(){//private ctor
//         cout<<"Constructor is private"<<endl;
//     }
// };
// int main(){
//     A obj;//error
// }

// so how do we do this ? we have some ways  1) singleton : is a special type of class in oops that have only one object.

#include <iostream>
using namespace std;

class Logger {
private:
    // Private constructor → cannot create object directly
    Logger() {
        cout << "Constructor called: Logger created\n";
    }

    // Private destructor → cannot destroy object directly
    ~Logger() {
        cout << "Destructor called: Logger destroyed\n";
    }

    // Static instance pointer
    static Logger* instance;

public:
    // Delete copy constructor & assignment (important for Singleton)
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Static method to create/access object
    static Logger* getInstance() {
        if (instance == nullptr) {
            instance = new Logger(); // allowed (inside class)
        }
        return instance;
    }

    // Controlled deletion
    static void destroyInstance() {
        if (instance != nullptr) {
            delete instance;  // allowed (inside class)
            instance = nullptr;
        }
    }

    // Normal member function
    void log(string msg) {
        cout << "Log: " << msg << endl;
    }
};

// Initialize static member
Logger* Logger::instance = nullptr;

int main() {
    // controlled creation 
    Logger* logger1 = Logger::getInstance();
    logger1->log("First message");

    // Same instance (Singleton behavior)
    Logger* logger2 = Logger::getInstance();
    logger2->log("Second message");

    // Check if both pointers are same
    if (logger1 == logger2) {
        cout << "Both pointers refer to same instance\n";
    }

    //  Not allowed:
    // delete logger1;  // ERROR (destructor is private)

    // Controlled deletion
    Logger::destroyInstance();

    return 0;
}

// so why we need it this is to prevent object creation from outside and provide control access via a static function  