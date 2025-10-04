// https://www.geeksforgeeks.org/problems/expression-add-operators/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void solve(string &s, int idx, long long target, long long val,
               long long prev, string expr, vector<string> &result) {
        if (idx == s.size()) {
            if (val == target)
                result.push_back(expr);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            // agar number leading zero se start ho raha hai (aur length > 1) to skip karo
            if (i != idx && s[idx] == '0') break;

            string part = s.substr(idx, i - idx + 1);
            long long curr = stoll(part);

            if (idx == 0) {
                // first number, koi operator nahi lagega
                solve(s, i + 1, target, curr, curr, part, result);
            } else {
                // '+' operation
                solve(s, i + 1, target, val + curr, curr, expr + "+" + part, result);

                // '-' operation
                solve(s, i + 1, target, val - curr, -curr, expr + "-" + part, result);

                // '*' operation — tricky part (undo last prev and multiply)
                solve(s, i + 1, target, val - prev + prev * curr, prev * curr, expr + "*" + part, result);
            }
        }
    }
  public:
    vector<string> findExpr(string &s, int target) {
        vector<string> result;
        solve(s, 0, target, 0, 0, "", result);
        return result;
    }
};