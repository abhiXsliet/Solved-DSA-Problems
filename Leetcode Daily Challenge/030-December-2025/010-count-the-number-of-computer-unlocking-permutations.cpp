// https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int M = 1e9 + 7;

    int fact(vector<int>& complexity, int n) {
        long ans = 1;
        for (int i = 1; i <= n; i ++) {
            if (complexity[0] >= complexity[i]) {
                return 0;
            }

            ans = (ans * i) % M;
        }
        return (int)ans;
    }
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        return fact(complexity, n - 1);
    }
};