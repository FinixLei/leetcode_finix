/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
    Input: prices = [3,3,5,0,0,3,1,4]
    Output: 6
    Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
    Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// -------------- Way-1 begin -------------------

int maxProfitInSection(vector<int>& vec, int beg, int end)
{
    int size = vec.size();
    
    if (beg == end) return 0;
    if (beg >= size || end >= size) return 0;
    if (beg < 0 || end < 0) return 0;
    
    int profit = 0;
    int minValue = INT_MAX;
    
    for (int i=beg; i<=end; i++) {
        if (vec[i] < minValue) minValue = vec[i];
        if (vec[i] - minValue > profit) profit = vec[i] - minValue;
    }
    return profit;
}

int maxProfit_1(vector<int>& prices) 
{
    int size = prices.size();
    int profit = 0;
    
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            int result_1 = maxProfitInSection(prices, i, j);
            int result_2 = maxProfitInSection(prices, j+1, size-1);
            if (result_1 + result_2 > profit) profit = result_1 + result_2; 
        }
    }
    return profit; 
}

// -------------- Way-1 end -------------------

// -------------- Way-2 begin -----------------
int maxProfit_2(vector<int>& prices) {
    if(prices.empty()) return 0;
 
    int buy1 = INT_MAX, buy2 = INT_MAX;
    int profit1 = INT_MIN, profit2 = INT_MIN;
    
    for(int i=0; i<prices.size(); i++) {
        buy1 = min(buy1, prices[i]);
        profit1 = max(profit1, prices[i] - buy1);
        
        // 将 profit1 的信息带入当前价格 prices[i] 作为 buy2
        // 再用当前价格 prices[i] - buy2 , 则可得到第2次的 profit + 第1次的 profit 
        buy2 = min(buy2, prices[i] - profit1);
        profit2 = max(profit2, prices[i] - buy2);
    }
    return profit2;
}
// --------------- Way-2 end -------------------

int main()
{
    vector<int> vec{7, 1, 5, 3, 6, 4};
    int result = maxProfitInSection(vec, 0, vec.size()-1);
    cout << "result = " << result << endl;
    
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int profit = maxProfit_1(prices);
    cout << "MaxProfit = " << profit << endl;
    
    profit = maxProfit_2(prices);
    cout << "MaxProfit = " << profit << endl;
    
    return 0;
}