/**
09. Best Time to Buy and Sell Stock with Cooldown
Medium

4511

150

Add to List

Share
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0


Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000

**/


//top down approach
class Solution {
public:
    int dp[5002][2];
    int solve(vector<int>& prices, int i, bool bag){
        if(i>=prices.size()) return 0;
        if(dp[i][bag]!=-1) return dp[i][bag];

        if(!bag){
            int buy = solve(prices,i+1,true)-prices[i];
            int cool = solve(prices,i+1,false);
            return dp[i][bag] = max(buy,cool);
        }else{
             int sell = solve(prices,i+2,false)+prices[i];
             int cool = solve(prices,i+1,true);
            return dp[i][bag] = max(sell,cool);
        }
    }

    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,false);
    }
};


