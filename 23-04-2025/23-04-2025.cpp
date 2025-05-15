// Lets see how to print things on new line. We use endl for that

#include<iostream>
using namespace std;
int main(){
    cout<<"hello world!" << endl;
    cout<<endl;//if we dont use it here the both printing statements wil ve mixed together
    cout<<"this is something different\n";
    cout<<"this is the next different thing";//now to give space we can also use \n this works same
    return 0;
}

/* it works as : Hello world\n; --> Hello world and "move to next line"; 
So what's the difference between \n and endl (\n) is a new line character it adds a newline character to output.

(endl) "hello world" endl; ---> its says to compiler that print hello world and move to next line and force the output to screen right now. 


C++ usually waits and collects multiple outputs and then it will display them together(called buffering) helps in performance. 

so what's the usecase, (\n --> faster, endl ---> flushes output to screen, ex: when we want to show output instantly after an error then we use endl.)
*/
