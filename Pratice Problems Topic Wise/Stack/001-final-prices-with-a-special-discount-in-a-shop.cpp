// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N) 
    vector<int> solve_optimal(vector<int>& prices, int n) {
        vector<int> result(n);
        stack<int> stk;

        for (int i = n - 1; i >= 0; i--) {
            while(!stk.empty() && !(stk.top() <= prices[i])) {
                stk.pop();
            }

            if (stk.empty()) result[i] = prices[i];
            else result[i] = prices[i] - stk.top();

            stk.push(prices[i]);
        }
        return result;
    }
public:
    vector<int> finalPrices(vector<int>& prices) {
        return solve_optimal(prices, prices.size());
    }
};