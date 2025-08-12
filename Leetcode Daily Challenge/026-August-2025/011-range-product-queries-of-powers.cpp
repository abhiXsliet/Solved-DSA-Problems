// https://leetcode.com/problems/range-product-queries-of-powers/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int M = 1e9 + 7;
    
    // TC : O(q)
    // SC : O(1)
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for (int i = 0; i <= 31; i ++) {
            if (n & (1 << i)) {
                powers.push_back(1 << i);
            }
        }

        vector<int> result;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long val = 1;
            for (int i = l; i <= r; i ++) {
                val = (val * powers[i]) % M;
            }
            result.push_back(val);
        }
        return result;
    }
};