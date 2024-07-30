// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(string s, int n) {
        stack<char> stk;
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            if (!stk.empty() && stk.top() == 'b' && s[i] == 'a') {
                ans += 1;
                stk.pop();
            } else stk.push(s[i]);
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(string s, int n) {
        vector<int> leftB(n, 0);
        vector<int> rightA(n, 0);

        int cntB = 0;
        for (int i = 1; i < n; i ++) {
            if (s[i - 1] == 'b') cntB ++;
            leftB[i] = cntB;
        }

        int cntA = 0;
        for (int i = n - 2; i >= 0; i --) {
            if (s[i + 1] == 'a') cntA ++;
            rightA[i] = cntA;
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i ++) {
            ans = min(ans, leftB[i] + rightA[i]);
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_3(string s, int n) {
        vector<int> rightA(n, 0);

        int cntA = 0;
        for (int i = n - 2; i >= 0; i --) {
            if (s[i + 1] == 'a') cntA ++;
            rightA[i] = cntA;
        }

        int cntB = 0;
        int ans = INT_MAX;
        for (int i = 0; i < n; i ++) {
            ans = min(ans, cntB + rightA[i]);
            if (s[i] == 'b') cntB ++;
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_4(string s, int n) {
        int cntA = 0;
        for (int i = n - 1; i >= 0; i --) {
            if (s[i] == 'a') cntA ++;
        }

        int cntB = 0;
        int ans = INT_MAX;

        for (int i = 0; i < n; i ++) {
            if (s[i] == 'a') cntA --;
            
            ans = min(ans, cntB + cntA);
            
            if (s[i] == 'b') cntB ++;
        }

        return ans;
    }
public:
    int minimumDeletions(string s) {
        // return approach_1(s, s.length());   // STACK

        // return approach_2(s, s.length());   // Track B in the left and A in right

        // return approach_3(s, s.length());   // EXtra for loop eliminated : One Pass

        return approach_4(s, s.length());   // constant space
    }
};