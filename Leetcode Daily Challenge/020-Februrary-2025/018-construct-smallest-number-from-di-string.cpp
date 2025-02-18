// https://leetcode.com/problems/construct-smallest-number-from-di-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool solve(string &pat, int n, vector<bool>& vis, string &res, int idx) {
        if (idx > n) return true;

        for (int val = 1; val <= 9; val ++) {
            if (vis[val]) continue;

            if (idx > 0) {
                int prevC = pat[idx - 1];
                int prevD = res[idx - 1] - '0';

                if (prevC == 'I' && val < prevD) continue;
                if (prevC == 'D' && val > prevD) continue;
            }

            vis[val] = 1;
            res[idx] = val + '0';

            if (solve(pat, n, vis, res, idx + 1))
                return true;

            vis[val] = 0;
            res[idx] = '.';
        }

        return false;
    }

    // TC : O(9^(n+1)) (worst case, but much better in practice due to early backtracking)
    // SC : O(n)
    string approach_1(string &pattern) {
        int n = pattern.length();
        vector<bool> visited(10, 0);    // since the no. is limited to 10 only
        string result = string(n + 1, '.');
        solve(pattern, n, visited, result, 0);
        return result;
    }

    // TC : O(n)
    // SC : O(n)
    string approach_2(string &pattern) {
        int n = pattern.length();
        stack<char> stk;
        int counter = 1;
        string result;

        for (int i = 0; i <= n; i ++) {
            stk.push(counter + '0');
            counter ++;

            if (i == n || pattern[i] == 'I') {
                while (!stk.empty()) {
                    result += stk.top();
                    stk.pop();
                }
            }
        }

        return result;
    }
public:
    string smallestNumber(string pattern) {
        // return approach_1(pattern);  // Trying all possible way : each index has 9 options to choose from.
        return approach_2(pattern);  // optimal : linear soln.
    }
};