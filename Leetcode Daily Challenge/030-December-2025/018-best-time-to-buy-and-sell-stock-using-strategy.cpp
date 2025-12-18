// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    ll maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        ll actualProfit = 0;
        vector<ll> profit(n); //original Profit of each day

        for (int i = 0; i < n; i++) {
            profit[i] = (ll)strategy[i] * prices[i];
            actualProfit += profit[i];
        }

        ll originalWindowProfit = 0;
        ll modifiedWindowProfit = 0;
        ll maxGain = 0; //modifiedWindowProfit - originalWindowProfit

        int i = 0, j = 0;

        //Khandani sliding window technique
        while (j < n) {

            originalWindowProfit += profit[j];

            // Second half of the window contributes to modifiedWindowProfit
            if (j - i + 1 > k/2) {
                modifiedWindowProfit += prices[j];
            }

            if (j - i + 1 > k) {
                originalWindowProfit -= profit[i];
                modifiedWindowProfit -= prices[i + k/2];
                i++;
            }

            // Evaluate window of size k
            if (j - i + 1 == k) {
                maxGain = max(maxGain, modifiedWindowProfit - originalWindowProfit);
            }

            j++;
        }

        return actualProfit + maxGain;
    }
};