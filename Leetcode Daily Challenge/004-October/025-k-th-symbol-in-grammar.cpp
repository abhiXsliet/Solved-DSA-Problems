// https://leetcode.com/problems/k-th-symbol-in-grammar/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N)
    // SC = O(N)
    int solve_rec(int n, int k) {
        if (n == 1 && k == 1) 
            return 0;

        int length = pow(2, n - 1);
        int middle = length / 2;

        if (k <= middle) {
            return solve_rec(n - 1, k);
        }
        else {
            return !solve_rec(n - 1, k - middle);
        }
    }
public:
    int kthGrammar(int n, int k) {
        return solve_rec(n, k);
    }
};