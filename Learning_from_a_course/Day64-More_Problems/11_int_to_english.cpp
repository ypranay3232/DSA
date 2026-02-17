// // Leetcode hard problem :
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<string> below20 = {
//     "", "One", "Two", "Three", "Four", "Five", "Six",
//     "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
//     "Thirteen", "Fourteen", "Fifteen", "Sixteen",
//     "Seventeen", "Eighteen", "Nineteen"
// };

// vector<string> tens = {
//     "", "", "Twenty", "Thirty", "Forty",
//     "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
// };

// // function to convert number < 1000
// string convertBelowThousand(int num)
// {
//     string result = "";

//     // hundreds place
//     if (num >= 100)
//     {
//         result += below20[num / 100] + " Hundred ";
//         num %= 100;
//     }

//     // tens place
//     if (num >= 20)
//     {
//         result += tens[num / 10] + " ";
//         num %= 10;
//     }

//     // ones place
//     if (num > 0)
//     {
//         result += below20[num] + " ";
//     }

//     return result;
// }

// string numberToWordsBrute(int num)
// {
//     if (num == 0)
//         return "Zero";

//     string result = "";

//     if (num >= 1000000000)
//     {
//         result += convertBelowThousand(num / 1000000000) + "Billion ";
//         num %= 1000000000;
//     }

//     if (num >= 1000000)
//     {
//         result += convertBelowThousand(num / 1000000) + "Million ";
//         num %= 1000000;
//     }

//     if (num >= 1000)
//     {
//         result += convertBelowThousand(num / 1000) + "Thousand ";
//         num %= 1000;
//     }

//     if (num > 0)
//     {
//         result += convertBelowThousand(num);
//     }

//     // remove trailing space
//     if (!result.empty())
//         result.pop_back();

//     return result;
// }

// int main()
// {
//     int num = 1234567891;
//     cout << numberToWordsBrute(num);
//     return 0;
// }

// Optimised code :
#include <iostream>
#include <vector>
using namespace std;


// First get the positions below 19
vector<string> below20 = {
    "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
    "Seventeen", "Eighteen", "Nineteen"};

    // Then get twenty, thirty ... til 90,
vector<string> tens = {
    "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
// then add thousands and millions and billion
vector<string> thousands = {"", "Thousand", "Million", "Billion"};

// helper function to check if number == 0, return none if < 20 return index of below20[num] ex: 18 points to index 18 value.
string helper(int num)
{
    if (num == 0)
        return "";
    else if (num < 20)
        return below20[num];
    else if (num < 100)
        return tens[num / 10] + (num % 10 ? " " + helper(num % 10) : "");
    else
        return below20[num / 100] + " Hundred" + (num % 100 ? " " + helper(num % 100) : "");
}

string numberToWords(int num)
{
    if (num == 0)
        return "Zero";

    string result = "";
    int i = 0;

    while (num > 0)
    {
        if (num % 1000 != 0)
        {
            string chunkResult = helper(num % 1000);
            if (!thousands[i].empty())
            {
                chunkResult += " " + thousands[i];
            }
            result = chunkResult + (result.empty() ? "" : " ") + result;
        }
        num /= 1000;
        i++;
    }

    return result;
}

int main()
{
    int num = 1234567891;
    cout << numberToWords(num);
}