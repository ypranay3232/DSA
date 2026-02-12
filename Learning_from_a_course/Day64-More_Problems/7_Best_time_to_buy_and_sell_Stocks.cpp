/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Note: that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

// 1)Brute Force Approach : The idea is to use nested loops inner for selling and outer for buying, the maximum difference between selling - buying stock will be the answer.

// What does problem say : buy at cheap price and sell at maximum price ! 



/*
ex: given an array of prices of a stock as : 
7,1,5,3,6,4  
0 1 2 3 4 5

if we buy the stock at day 1(at 1 rupee) we can sell it at day 0 for max profit for 7 rupees. 
so rather we need to sell it in future. 

we get a value (Min_price = 1) and then we iterate the array to find next max number and we sell on that day.
*/

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int BestTimeTOBuyAndSell(vector<int>&prices){
    // first find the size and store the maximum price
    int n = prices.size();
    int result = 0;
    // now loop till n-1 til end of array (.i.e buying)
    for(int i =0;i<n-1;i++){
        // now loop the inner loop from i+1 index because we avoid repeating, (i.e selling)
        for(int j = i+1;j<n;j++){
            // result = maximum values and of selling - buying
            result = max(result,prices[j] - prices[i]);
        }
    }
    return result;
}

// Using iterative solution : 
int optimisedsol(vector<int>prices){
    // first create two variables minimum price and maximum profit.
    int minprice = INT_MAX;
    int maxprofit = 0;

    // not loop through the array 
    for(int i =0;i<prices.size();i++){
        // Now updating min price, first get current price and store in minprice and get min()
        minprice = min(minprice,prices[i]);
        // same but using the formula : profit = current price/price[i] - min(price) store it in maxprofit and get the max element.
        maxprofit = max(maxprofit, prices[i] - minprice);
    }
    return maxprofit;
}

// Using Recursion : 
void findmaxprofit(vector<int>&prices, int i, int& minprice,int& maxprofit){
    // Base case : stop if we reach to the end of array
    if(i == prices.size()) return;

    // update the min price till found
    minprice = min(minprice, prices[i]);

    // calculate today profit and update it
    int currentprofit = prices[i] - minprice;
    maxprofit = max(maxprofit, currentprofit);

    // recursion call : 
    findmaxprofit(prices, i + 1, minprice, maxprofit);

}
int solveRecursive(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    
    findmaxprofit(prices, 0, minPrice, maxProfit);
    
    return maxProfit;
}


int main(){
    vector<int> prices = {7,1,5,3,6,4};
    int result1 = BestTimeTOBuyAndSell(prices);
    cout<<"BruteForce best time to buy and sell socks on the day is : "<<result1<<endl;

    int result2 = optimisedsol(prices);
    cout<<"Optimised best time to buy and sell socks on the day is : "<<result2<<endl;

    int result3 = solveRecursive(prices);
    cout << "Recursive max profit : " << result3 << endl;
}