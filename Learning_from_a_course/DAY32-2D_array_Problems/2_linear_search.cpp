/*
Create a 2d array with size and ask user to enter input to search the key.

*/
#include <iostream>
using namespace std;


// Now create a function findkey and check for the key either via each row or col both return same output
bool findkey(int array[3][4],int row,int cols,int ip){
    // now loop through the array to check 
    for(int i =0;i<row;i++){
        for(int j=0;j<cols;j++){
            if(array[i][j] == ip){
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int array[3][4];
    int row = 3;
    int cols = 4;

    // Taking User input
    cout << "enter the array values : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> array[i][j];
        }
    }

    // now print the key 
    int ip;
    cout<<"Enter The to search : "<<endl;
    cin>>ip;
    cout<<findkey(array,3,3,ip);
}