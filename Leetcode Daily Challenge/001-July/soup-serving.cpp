// https://leetcode.com/problems/soup-servings/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    double solveRec(double A, double B) {
        vector<pair<int, int>> operations = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
        
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;

        double prob = 0.0;
        for(auto& i: operations) {
            double take_A = i.first;
            double take_B = i.second;
            prob += solveRec(A - take_A, B - take_B);
        }
        return 0.25 * prob;
    }

    double solveRec_Mem(double A, double B, vector<vector<double>>& dp) {
        vector<pair<int, int>> operations = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
        
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;

        if (dp[A][B] != -1) return dp[A][B];

        double prob = 0.0;
        for(auto& i: operations) {
            double take_A = i.first;
            double take_B = i.second;
            prob += solveRec_Mem(A - take_A, B - take_B, dp);
        }
        return dp[A][B] = 0.25 * prob;
    }

public:
    double soupServings(int n) {
        // // Recursion -> TLE
        // return solveRec(n, n);


        // Probability of A is increasing as N increase and it will become 1 for large N.
        // We have to reduce value of N until we get p=0.999995 or N where our solution works fine. 
        if(n >= 5000) return 1.0; 
        // Recursion + Memoization -> Memory Limit Exceeded
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1));
        return solveRec_Mem(n, n, dp);
    }
};