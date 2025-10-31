/*
Let's see about Break and continue keywords !
Break Keyword breaks the loop/condition when it hits a certain condition or it hits when you use it

Continue Keyword skips the printing statement when it hits a certain condtion
ex:
*/
#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    for (int i = 0; i < n; i++)//Prints Hello world 5 times
    {
        cout << "Hello world" << endl;
        // But if i add a break statement then it stops after just one iteration. (.i.e Break the conditon immediately after encountering Break keyword)
        // break;

        // Or you can also use the break and continue with if statement so it becomes more accurate and makes sense

        if(i == 3){
            break;
        }
    }


    // Now lets see about continue keyword : 
    for(int i =0;i<5;i++){
        continue;//Skips the bottom of the code after it and skips back to top. so this loop prints nothing
        cout<<i<<endl;
    }
}