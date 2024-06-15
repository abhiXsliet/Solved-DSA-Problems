// https://leetcode.com/problems/student-attendance-record-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M = 1e9+7;
    int t[100001][2][3];
    
    // TC : O(n) with memoization, without memoization O(3^n)
    // SC : O(n)
    int solve(int n, int absent, int consecutive_late) {

        if(absent >= 2 || consecutive_late >= 3) {
            return 0;
        }

        if(n == 0)
            return 1;
        
        if(t[n][absent][consecutive_late] != -1) {
            return t[n][absent][consecutive_late];
        }

        int A = solve(n-1, absent+1, 0) % M;
        int L = solve(n-1, absent, consecutive_late+1) % M;
        int P = solve(n-1, absent, 0) % M;

        return t[n][absent][consecutive_late] = ((A + L) % M + P) % M;
    }

    // TC : O(N)
    // SC : O(N)
    int tab(int n) {
        int t[100001][2][3];

        // Base Case When n = 0
        for (int A = 0; A <= 1; A ++) {
            for (int L = 0; L <= 2; L ++) {
                t[0][A][L] = 1;
            }
        }

        for (int i = 1; i <= n; i ++) {
            for (int A = 0; A <= 1; A ++) {
                for (int L = 0; L <= 2; L ++) {

                    long ans = (A + 1 <= 1 ? t[i - 1][A + 1][0] : 0); // Absent
                    ans     += (L + 1 <= 2 ? t[i - 1][A][L + 1] : 0); // Late
                    ans     += t[i - 1][A][0];                        // Present : then consecutive late streak becomes zero

                    t[i][A][L] = ans % M;
                }
            }
        }

        return t[n][0][0];
    }
    int checkRecord(int n) {
        // memset(t, -1, sizeof(t));
        // return solve(n, 0, 0);

        return tab(n);
    }
};