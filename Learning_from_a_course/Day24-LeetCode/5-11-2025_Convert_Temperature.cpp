/*
Problem : 2469 Convert the temperature 
You are given a non negative floating point number rounded to two decimal places celsius, that denotes the temperature in celsius

you should convert the celsius into kelvin and fahrenheit and return it as an array ans = [kelvin, fahrenheit]

return the array as the answer, The answer with 10 to power -5 of the actual answer will be accepted.

Note that:

Kelvin = Celsius + 273.15
Fahrenheit = Celsius * 1.80 + 32.00
 

Example 1:

Input: celsius = 36.50
Output: [309.65000,97.70000]
Explanation: Temperature at 36.50 Celsius converted in Kelvin is 309.65 and converted in Fahrenheit is 97.70.
Example 2:


().i.e. we had given a non negative float as input for celsius and we have to find kelvin

Kelvin = celsius + 273.15 formula
Farhenheit = c * 1.80+ 32 
)
*/

#include <vector>
#include<iostream>
using namespace std;


class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double K = celsius + 273.15;
        double f = celsius * 1.80 + 32.00;

        vector<double> v;
        v.push_back(K);
        v.push_back(f);

        return v;
    }
};

// first we create a function with vector double(vector is similar to a array that holds similar data)
// now we declare the Kelvin = celsius + 274.15; 
// and Fahrenheit f = celsius & 1.80+32.00; 
// and we create a object for vector and, push back the Kelvin and Fahrenheit to vector and we return vector 