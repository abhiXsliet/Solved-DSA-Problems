// https://leetcode.com/problems/candy/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> leftToRight(n, 1), rightToLeft(n, 1);

        for (int i = 1; i < n; i ++) {
            if (ratings[i] > ratings[i - 1]) {
                leftToRight[i] = leftToRight[i - 1] + 1;
            }
            if (ratings[n - i - 1] > ratings[n - i]) {
                rightToLeft[n - i - 1] = rightToLeft[n - i] + 1;
            }
        }

        int candies = 0;
        for (int i = 0; i < n; i ++) {
            candies += max(leftToRight[i], rightToLeft[i]);
        }
        return candies;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int>& ratings) {
        int n = ratings.size();
        
        int i = 1;
        int candies = n;

        while(i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i ++;
                continue;
            }
            
            int peak = 0;
            // peak : increasing slope
            while (ratings[i] > ratings[i - 1]) {
                peak ++;
                candies += peak;
                i ++;

                if (i == n) return candies;
            }

            int dip = 0;
            // dip : decreasing slope 
            while (i < n && ratings[i] < ratings[i - 1]) {
                dip ++;
                candies += dip;
                i ++;
            }

            // subtract from candies 
            candies -= min(peak, dip);
        }

        return candies;
    }
public:
    int candy(vector<int>& ratings) {
        // return approach_1(ratings); // Traverse L2R & R2L

        return approach_2(ratings);
    }
};