// https://leetcode.com/problems/strange-printer/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp[101][101];

    // TC : O(N^3)
    // SC : O(N^2)
    int appr_1(string& s, int n, int l, int r) {
        if (l == r) return 1;   // one char only
        if (l  > r) return 0;
        if (dp[l][r] != -1) 
            return dp[l][r];

        int i = l + 1;
        while (i <= r && s[i] == s[l]) 
            i ++;

        if (i == r + 1) // i goes out of bound : "aaaaa"
            return 1;

        // case 1 : increment i till similar char & then call for remaining string
        int simple = 1 + appr_1(s, n, i, r); 

        // case 2 : "aabaa" 'i' is at 'b' and 'j' is at i, incrementing j greedily if s[l] == s[j] else call for (i, j - 1)
        int greedy = INT_MAX;
        for (int j = i; j <= r; j ++) {
            if (s[l] == s[j]) {
                int val = appr_1(s, n, i, j - 1) + appr_1(s, n, j, r);
                greedy  = min(greedy, val);
            }
        }    

        return dp[l][r] = min(simple, greedy);
    }

    // TC : O(N^3)
    // SC : O(N^2)   
    int appr_2(string& s, int n, int i, int j) {
        if(i == j) return 1;

        if(dp[i][j] != -1) 
            return dp[i][j];

        int ans = INT_MAX;
        for(int k = i; k < j; k++) {
            ans = min(ans, appr_2(s, n, i, k) + appr_2(s, n, k + 1, j));
        }

        if(s[i] == s[j]) ans --;    // "aabaa" -> Group 1: aa which gives ans as 1 , Group 2: baa which gives ans as 2
                                    // merging group 1 + group 2 - 1 since s[i] == s[j]

        return dp[i][j] = ans;
    }

    // TC : O(N^3)
    // SC : O(N^2)
    int approach_1(string& s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        return appr_1(s, n, 0, n - 1);
    }

    // TC : O(N^3)
    // SC : O(N^2)
    int approach_2(string& s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        return appr_2(s, n, 0, n - 1);
    }
public:
    int strangePrinter(string s) {
        // return approach_1(s);    // Without MCM

        return approach_2(s);    // Using MCM : Memoization
    }
};