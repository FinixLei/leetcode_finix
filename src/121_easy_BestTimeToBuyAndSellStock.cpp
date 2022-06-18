/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

#include <stack>
#include <climits>

// way-1
int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int maxValue = 0;
    
    stack<int> mystack;
    mystack.push(prices[0]);
    
    for(int i=1; i<prices.size(); i++) {
        int top = mystack.top();
        if (top <= prices[i]) {
            int diff = prices[i] - top;
            if (diff > maxValue) maxValue = diff;
        }
        else {
            mystack.push(prices[i]);
        }
    }
    
    return maxValue;
}

// way-2
int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    
    int minPrice = INT_MAX;
    int profit = 0;
    
    for (int v : prices) {
        if (v < minPrice) minPrice = v;
        if (v - minPrice > profit) profit = v - minPrice;
    }
    
    return maxValue;
}