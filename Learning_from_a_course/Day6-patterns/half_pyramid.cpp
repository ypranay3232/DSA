#include <iostream>
using namespace std;

int main()
{
    // lets see how to print a half pyramid ?
    /*

    *
    * *
    * * *
    * * * *
    * * * * *
    * * * * * *

    (as we can see we have 6 rows and each row has stars which are in increasing order) so we can say it as : each row is printing (row+1) stars
    */

    for (int rows = 0; rows <= 6; rows += 1)
    {
        for (int cols = 0; cols < rows; cols += 1)
        {
            // here we have a problem (cols<rows) this skips the first line while printing the pattern because on the 1st iteration (where rows=0 and cols=0 both are equal so nothing prings) and (first outer loop goes to inner loop with value '0' inner loop cols =0. and condition == cols<rows (cols=0,rows=0) so it works as 0<0 FALSE so the condition became false so skips and in next iterating prints *) so we have to write "<=6"
            cout << "*";
        }
        cout << endl;
    }

    // now lets modify it as where user has control over the pattern:

    int No_Of_Rows;
    cout << "Enter the no of row you want : ";
    cin >> No_Of_Rows;

    for (int rows = 0; rows < No_Of_Rows; rows += 1)
    {
        for (int cols = 0; cols < rows + 1; cols += 1)
        {
            // first outer loop goes to inner loop with value '0' inner loop cols =0. and condition == cols<rows+1 (cols=0,rows=rows+1) so it works as 0<1 yes so the condition became true so the * prints)
            cout << "*";
        }
        cout << endl;
    }

    // now lets print the inverted half pyramid.

    int No_Of_Stars;
    cout<<"Enter the no of stars you want : ";
    cin>>No_Of_Stars;

    for(int rows=0; rows<No_Of_Stars;rows+=1){ //first lets create rows
        for(int cols=0; cols<No_Of_Stars-rows;cols+=1){//now here check the condition if cols<input-rows the logic is (input-rows) so it prints a descending order.
            cout<<"*";
        }
        cout<<endl;
    }

    // Therefore half pyramid formula : rows+1 or n+1 and inverted half pyramid formula : n-rows


    // now lets do the same with numbers instead of printing stars : numeric half pyramid

    int input;
    cout<<"Enter number up to you want to print : ";
    cin>>input;

    for(int rows=0;rows<input;rows+=1){//step1: create rows 
        for(int cols=0; cols<rows+1;cols+=1){//s2: break cols logic we want rows+1 for each next row //here by this it starts printing from '0' because outer loop =0, so the inner loop = 0+1   so (0<1 True) so  print '0'. That's how it prints from '0' 
            cout<<cols+1;//in order to change it we increment it by 1 so now (while printing 0 we add +1)
        }
        cout<<endl;
    }


    // now invert it a numeric invert half pyramid
    int input1;
    cout<<"Enter Number up to you want to print : ";
    cin>>input1;

    for(int rows=0;rows<input1;rows+=1){//s1: create rows
        for(int cols=0;cols<input1-rows;cols+=1){//s2: here the condition is input-rows(5-1,5-4....)
            cout<<cols+1;
        }
        cout<<endl;
    }

}
