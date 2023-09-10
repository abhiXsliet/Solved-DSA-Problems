// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/



#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Solution {
public:
    int countOrders(int n) {
        if (n == 1) return 1;

        long long result = 1;

        for (int i = 2; i <= n; i++) {
            int spaces      = (i - 1) * 2 + 1; // 3, 5, 7

            int possibility = spaces * (spaces + 1) / 2;
            
            result = (result * possibility)  % MOD;
        }

        return result;
    }
};