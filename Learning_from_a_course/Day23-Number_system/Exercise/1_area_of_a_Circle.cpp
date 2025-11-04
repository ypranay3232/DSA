#include <iostream>
using namespace std;

int area_of_a_circle(int r)
{
    // The formula to print area of a circle is pi r square

    int area = 3.14 * r * r;

    return area;
}

int main()
{
    float radius;
    cout << "Enter the radius : " << endl;
    cin >> radius;

    // Now call the function
    int result = area_of_a_circle(radius);
    cout << "The area of a circle is : " << result << endl;

    return 0;
}