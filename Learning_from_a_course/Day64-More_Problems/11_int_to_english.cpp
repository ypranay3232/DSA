// Leetcode hard problem : 
#include <iostream>
#include <vector>
using namespace std;

vector<string> below20 = {
    "", "One", "Two", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
    "Thirteen", "Fourteen", "Fifteen", "Sixteen",
    "Seventeen", "Eighteen", "Nineteen"
};

vector<string> tens = {
    "", "", "Twenty", "Thirty", "Forty",
    "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

// function to convert number < 1000
string convertBelowThousand(int num)
{
    string result = "";

    // hundreds place
    if (num >= 100)
    {
        result += below20[num / 100] + " Hundred ";
        num %= 100;
    }

    // tens place
    if (num >= 20)
    {
        result += tens[num / 10] + " ";
        num %= 10;
    }

    // ones place
    if (num > 0)
    {
        result += below20[num] + " ";
    }

    return result;
}

string numberToWordsBrute(int num)
{
    if (num == 0)
        return "Zero";

    string result = "";

    if (num >= 1000000000)
    {
        result += convertBelowThousand(num / 1000000000) + "Billion ";
        num %= 1000000000;
    }

    if (num >= 1000000)
    {
        result += convertBelowThousand(num / 1000000) + "Million ";
        num %= 1000000;
    }

    if (num >= 1000)
    {
        result += convertBelowThousand(num / 1000) + "Thousand ";
        num %= 1000;
    }

    if (num > 0)
    {
        result += convertBelowThousand(num);
    }

    // remove trailing space
    if (!result.empty())
        result.pop_back();

    return result;
}

int main()
{
    int num = 1234567891;
    cout << numberToWordsBrute(num);
    return 0;
}