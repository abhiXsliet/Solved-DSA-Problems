// https://leetcode.com/problems/different-ways-to-add-parentheses/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * 2^N)
    // SC : O(N) Recursive Depth
    vector<int> solve(string s) {
        vector<int> result;

        for (int i = 0; i < s.length(); i ++) {

            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> leftRes  = solve(s.substr(0, i));
                vector<int> rightRes = solve(s.substr(i + 1));

                for (int& a : leftRes) {
                    for (int& b : rightRes) {
                        if (s[i] == '+') {
                            result.push_back(a + b);
                        } else if (s[i] == '-') {
                            result.push_back(a - b);
                        } else if (s[i] == '*') {
                            result.push_back(a * b);
                        }
                    }
                }
            }
        }

        if (result.empty()) {
            result.push_back(stoi(s));
        }
        return result;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};