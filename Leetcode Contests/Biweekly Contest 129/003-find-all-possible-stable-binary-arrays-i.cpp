// https://leetcode.com/contest/biweekly-contest-129/problems/find-all-possible-stable-binary-arrays-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int M = 1e9 + 7;
    int t[201][201][2];
    int solve(int zero, int one, int limit, bool flag) {
        if (zero == 0 && one == 0) return 1;
        
        if (t[zero][one][flag] != -1) return t[zero][one][flag];
        
        int ans = 0;
        if (flag == 1) { // previously i have taken 0
            for (int i = 1; i <= min(one, limit); i ++) {
                ans = (ans + solve(zero, one - i, limit, 0) % M) % M;
            }
        }
        else {  // previously i have taken 1
            for (int i = 1; i <= min(zero, limit); i ++) {
                ans = (ans + solve(zero - i, one, limit, 1) % M) % M;
            }
        }

        return t[zero][one][flag] = ans % M;
    }
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));
        
        int start_with_1 = solve(zero, one, limit, 1) % M;   
        int start_with_0 = solve(zero, one, limit, 0) % M;
        
        return (start_with_1 + start_with_0) % M;
    }
};
