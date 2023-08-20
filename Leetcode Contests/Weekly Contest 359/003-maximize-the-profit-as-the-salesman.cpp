// https://leetcode.com/contest/weekly-contest-359/problems/maximize-the-profit-as-the-salesman/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> maxProfit(n + 1, 0);

        sort(offers.begin(), offers.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int offerIdx = 0; 

        for (int house = 1; house <= n; ++house) {
            maxProfit[house] = maxProfit[house - 1];

            while (offerIdx < offers.size() && offers[offerIdx][1] == house - 1) {
                maxProfit[house] = max(maxProfit[house], maxProfit[offers[offerIdx][0]] + offers[offerIdx][2]);
                ++offerIdx;
            }
        }

        return maxProfit[n];
    }
};