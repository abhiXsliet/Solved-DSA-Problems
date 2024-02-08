// https://leetcode.com/problems/perfect-squares/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int t[10001];
    // TC : O(N * sqrt(N))
    // SC : O(N)
    int mem(int n) {
        if (n <= 0) return 0;
        if (t[n] != -1) return t[n];

        int minCount = INT_MAX;
        for (int num = 1; num*num <= n; num++) {
            minCount = min(minCount, 1 + mem(n - num*num));
        }
        return t[n] = minCount;
    }

    // TC : O(N * sqrt(N))
    // SC : O(N)
    int tab(int n) {
        vector<int> t(n+1, 0);

        for (int i = 1; i <= n; i++) {

            int minCount = INT_MAX;
            for (int num = 1; num*num <= i; num++) {

                minCount = min(minCount, 1 + t[i - num*num]);
            }
            t[i] = minCount;
        }
        return t[n];
    }
public:
    int numSquares(int n) {
        // memset(t, -1, sizeof(t));
        // return mem(n);

        return tab(n);
    }
};