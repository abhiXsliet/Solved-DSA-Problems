// https://leetcode.com/problems/buy-two-chocolates/



#include <bits/stdc++.h>
using namespace std; 

class Solution {
private:
    // TC : O(N * log(N))
    // SC : O(1)
    int solve_brute(vector<int>& prices, int money) {
        int n = prices.size();
        int initial_amount = money;

        sort(begin(prices), end(prices));

        if (prices[0] > money) 
            return money;

        for (int i = 0; i < 2; i++) {
            money -= prices[i];
        }

        if (money >= 0) 
            return money;
        else 
            return initial_amount; 
    }

    // TC : O(N)
    // SC : O(1)
    int solve_optimal(vector<int>& prices, int money) {
        int minPrice     = INT_MAX;
        int sec_minPrice = INT_MAX;

        for (int price : prices) {
            if (price < minPrice) {
                sec_minPrice = minPrice;
                minPrice     = price;
            }
            else sec_minPrice = min(sec_minPrice, price);
        }

        // if can't be possible to buy 2-chocolates with the given money
        if (minPrice + sec_minPrice > money) 
            return money;
        
        // remaining money after buying 2-chocolates
        return money - (minPrice + sec_minPrice);
    }
public:
    int buyChoco(vector<int>& prices, int money) {
        // return solve_brute(prices, money);

        return solve_optimal(prices, money);
    }
};