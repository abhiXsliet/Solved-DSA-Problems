// https://www.geeksforgeeks.org/problems/buy-stock-2/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int mini = prices[0];
        for (int &price : prices) {
            profit = max(profit, price - mini);
            mini = min(mini, price);
        }
        return profit;
    }
};
