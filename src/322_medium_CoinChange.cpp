/*
    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
    Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
    You may assume that you have an infinite number of each kind of coin.

    Example 1:
        Input: coins = [1,2,5], amount = 11
        Output: 3
        Explanation: 11 = 5 + 5 + 1
*/

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

int calcCoinChange(vector<int>& coin, int amount, vector<int>& cache)
{
    if(amount==0) return 0;
    if(amount<0)  return INT_MAX;
    
    if(cache[amount]!=-1) return cache[amount];
    
    int min_count=INT_MAX;
    for(int i=0;i<coin.size();i++)
    {
        int tmp_count = calcCoinChange(coin, amount-coin[i], cache);
        if (tmp_count == INT_MAX) continue;
        if( tmp_count < min_count) min_count = tmp_count;
    }
    
    // Must also record the "Impossible" amount-s
    cache[amount] = (min_count == INT_MAX ? INT_MAX : (min_count+1));
    return cache[amount];
}

int coinChange(vector<int>& coins, int amount) 
{
    vector<int> cache(amount+1, -1);
    int result = calcCoinChange(coins,amount,cache);
    return (result == INT_MAX ? -1 : result); 
}

int main()
{
    vector<int> coins = {1,2,5};
    int amount = 11;
    int result = coinChange(coins, amount);
    cout << "result: " << result << endl;
    
    coins = {1, 2, 5};
    amount = 100;
    result = coinChange(coins, amount);
    cout << "result: " << result << endl;
    
    coins = {186, 419, 83, 408};
    amount = 6249;
    result = coinChange(coins, amount);
    cout << "result: " << result << endl;
    
    return 0;
}