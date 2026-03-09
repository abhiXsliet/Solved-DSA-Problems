// https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int M = 1e9 + 7;
    int t[201][201][2];
    int solve(int zero, int one, int limit, bool prev) {
        if (zero == 0 && one == 0) return 1;
        
        if (t[zero][one][prev] != -1) return t[zero][one][prev];
        
        int ans = 0;
        if (prev == 0) { // previously i have taken 0
            for (int i = 1; i <= min(one, limit); i ++) {
                ans = (ans + solve(zero, one - i, limit, 1) % M) % M;
            }
        }
        else {  // previously i have taken 1
            for (int i = 1; i <= min(zero, limit); i ++) {
                ans = (ans + solve(zero - i, one, limit, 0) % M) % M;
            }
        }

        return t[zero][one][prev] = ans % M;
    }
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));
        
        int op_1 = solve(zero, one, limit, 0) % M;   
        int op_2 = solve(zero, one, limit, 1) % M;
        
        return (op_1 + op_2) % M;
    }
};