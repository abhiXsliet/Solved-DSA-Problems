// https://leetcode.com/problems/lexicographical-numbers/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(vector<int> &result, long val, int n) {
        for (int i = 0; i <= 9; i ++) {
            int next = val * 10 + i;
            if (next <= n) {
                result.push_back(next);
                solve(result, next, n);
            } else break;
        }
    }
public:
    // TC : O(N)
    // SC : O(1)
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i <= min(n, 9); i ++) {
            result.push_back(i);
            solve(result, i, n);
        }
        return result;
    }
};