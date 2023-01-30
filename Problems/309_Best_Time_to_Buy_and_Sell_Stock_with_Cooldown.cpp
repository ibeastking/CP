//* Difficulty -> Medium

//? You are given an array prices where prices[i] is the price of a given stock on the ith day.
// ?Find the maximum profit you can achieve. You may complete as many transactions as you like
//? (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
//? After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
//? Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

//! Question Tags -> Array, Dynamic Programming

#include <bits\stdc++.h>
using namespace std;

class buysellonce
{
public:
    int maxProfit(vector<int> &stocks)
    {

        //* to make highest profit you need to buy the stock at lowest price, mini stores lowest price
        int mini = stocks[0];
        int profit = 0;

        for (int i = 1; i < stocks.size(); i++)
        {
            profit = max(profit, stocks[i] - mini);
            mini = min(mini, stocks[i]);
        }

        return profit;
    }
};

class buysellmulti
{
public:
    int maxProfit(vector<int> &stocks)
    {
        int n = stocks.size();
        vector<vector<long>> vt(n + 1, vector<long>(2, 0));

        vt[n][0] = vt[n][1] = 0;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                long profit = 0;

                //* buy 0 means sell and buy 1 means buy the stock
                if (buy)
                {
                    //* you find what is more profitable buying the stock at current value or if you sell
                    profit = max(-stocks[idx] + vt[idx + 1][0], 0 + vt[idx + 1][1]);
                }
                else
                {
                    //* you find what is more profitable selling the stock at current value or if you buy
                    profit = max(stocks[idx] + vt[idx + 1][1], 0 + vt[idx + 1][0]);
                }

                vt[idx][buy] = profit;
            }
        }

        return vt[0][1];
    }
};