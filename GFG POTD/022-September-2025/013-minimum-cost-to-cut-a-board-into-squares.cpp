// https://www.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N*log(N) + M*log(M))
    // SC : O(1)
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        // Sort descending
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());

        int i = 0, j = 0;
        int hz = 1, vt = 1; // segments count
        long long cost = 0;

        while (i < (int)x.size() && j < (int)y.size()) {
            if (x[i] > y[j]) {
                cost += 1LL * x[i] * hz;
                vt++;
                i++;
            } else {
                cost += 1LL * y[j] * vt;
                hz++;
                j++;
            }
        }

        // Remaining vertical cuts
        while (i < (int)x.size()) {
            cost += 1LL * x[i] * hz;
            vt++;
            i++;
        }

        // Remaining horizontal cuts
        while (j < (int)y.size()) {
            cost += 1LL * y[j] * vt;
            hz++;
            j++;
        }

        return (int)cost;
    }
};