// https://leetcode.com/contest/weekly-contest-411/problems/maximum-energy-boost-from-two-drinks/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    int n;
    ll dp[2][2][100001];

    ll solve(vector<int>& A, vector<int>& B, bool takeA, bool takeB, int i) {
        if (i >= A.size() || i >= B.size())
            return 0;

        if (dp[takeA][takeB][i] != -1)
            return dp[takeA][takeB][i];

        ll val_1 = 0, val_2 = 0;

        if (takeA) val_1 = A[i] + solve(A, B, 1, 0, i + 1);
        else       val_1 = 0    + solve(A, B, 1, 0, i + 1);

        if (takeB) val_2 = B[i] + solve(A, B, 0, 1, i + 1);
        else       val_2 = 0    + solve(A, B, 0, 1, i + 1);

        return dp[takeA][takeB][i] = max(val_1, val_2);
    }
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        n = energyDrinkA.size();
        memset(dp, -1, sizeof(dp));
        return solve(energyDrinkA, energyDrinkB, 1, 1, 0);
    }
};