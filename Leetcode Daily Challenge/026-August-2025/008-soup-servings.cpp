// https://leetcode.com/problems/soup-servings/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> serves {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    vector<vector<double>> dp;

    double probA(double A, double B) {
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0; // since question only asked about A's getting empty first;

        if (dp[A][B] != -1.0) return dp[A][B];

        double totalProb = 0.0;
        for (auto &it : serves) {
            int takenA = it[0];
            int takenB = it[1];

            totalProb += probA(A - takenA, B - takenB);
        }
        return dp[A][B] = ((0.25) * totalProb);
    }
public:
    double soupServings(int n) {
        if (n >= 5000) return 1.0;    // prob. of A being empty first is 1 (because of op1)
        
        dp.resize(n + 1, vector<double>(n + 1, -1.0));
        return probA(n, n);
    }
};