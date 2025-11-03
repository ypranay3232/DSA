/* The students and grade problem is, where we assign different grades to different students

So to do this we have to remember something : the marks are in integer format and the A,B,C stduents are in character foramt so we create a character and store the values in it.

NOTE : we can't store more than 1 character inside the variable.

*/

#include <iostream>
using namespace std;

// char GetGrade(int marks)
// {
//     if (marks >= 90)
//     {
//         return 'A';
//     }
//     else if (marks >= 80)
//     {
//         return 'B';
//     }
//     else if (marks >= 70)
//     {
//         return 'C';
//     }
//     else if (marks >= 50)
//     {
//         return 'D';
//     }
//     else if (marks >= 40)
//     {
//         return 'C';
//     }
//     else
//     {
//         return 'F';
//     }
// }


// Lets try it using switch case statement ! here the logic works as : we divide the marks with 10 (i.e. ex : marks = 100/10 = 10 so 'A' and if marks == 81/10 == 8 so "B")

char GetGrade(int marks)
{
    switch (marks / 10)
    {
    case 10:
        return 'A';
        break;
    case 9:
        return 'A';
        break;
    case 8:
        return 'B';
        break;
    case 7:
        return 'C';
        break;
    case 6:
        return 'D';
        break;
    default:
        return 'F';
        break;
    }
}

int main()
{
    int marks;
    cout << "Enter the marks : " << endl;
    cin >> marks;

    char final_grade = GetGrade(marks);
    cout << "Final grade is : " << final_grade << endl;
}