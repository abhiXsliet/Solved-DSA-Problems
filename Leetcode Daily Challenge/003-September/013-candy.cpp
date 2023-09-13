// https://leetcode.com/problems/candy/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N)
    // SC = O(N)
    int solve_better(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy_distribution(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1] && candy_distribution[i] <= candy_distribution[i-1]) 
                candy_distribution[i] = candy_distribution[i-1] + 1;
        }

        for (int i = n - 1; i > 0; i--) {
            if (ratings[i] < ratings[i-1] && candy_distribution[i-1] <= candy_distribution[i]) 
                candy_distribution[i-1] = candy_distribution[i] + 1;
        }

        int totalCandies = 0;
        for(int &i : candy_distribution) {
            totalCandies += i;
        }

        return totalCandies;
    }

    // TC = O(N)
    // SC = O(1)
    int solve_optimal(vector<int>& ratings) {
        int n = ratings.size();
        int candy_cnt = n; // 1-candy for each

        int i = 1;
        while (i < n) {
            if (ratings[i] == ratings[i-1]) {
                i++;
                continue;
            }

            int peak = 0;
            // increasing slope - peak
            while (ratings[i] > ratings[i-1]) {
                peak++;
                candy_cnt += peak;
                i++;

                if (i == n) return candy_cnt;
            }

            int dip = 0;
            // decreasing slope - dip
            while (i < n && ratings[i] < ratings[i-1]) {
                dip++;
                candy_cnt += dip;
                i++;
            }
            candy_cnt -= min(peak, dip);
        }
        return candy_cnt;
    }

public:
    int candy(vector<int>& ratings) {

        // return solve_better(ratings);

        return solve_optimal(ratings);
    }
};