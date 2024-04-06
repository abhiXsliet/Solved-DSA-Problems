// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    string solve_1(string& s, int n) {
        stack<int> stk;
        unordered_set<int> remove_idx;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else if (s[i] == ')') {
                if (stk.empty()) {
                    remove_idx.insert(i);
                }
                else {
                    stk.pop();
                }
            }
        }

        while(!stk.empty()) {
            remove_idx.insert(stk.top());
            stk.pop();
        }

        string res = "";
        for (int i = 0; i < n; i++) {
            if (remove_idx.find(i) == remove_idx.end()) {
                res.push_back(s[i]);
            }
        }
        return res;
    }

    // TC : O(N)
    // SC : O(1)
    string solve_2(string& s, int n) {
        string res  = "";
        int open_br = 0;
        
        // Iterate L ---> R to eliminate extra ')' (close brackets)
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                res.push_back(s[i]);
            }
            else if (s[i] == '(') {
                open_br ++;
                res.push_back(s[i]);
            }
            else if (open_br > 0) {     // s[i] == ')'
                open_br --;
                res.push_back(s[i]);
            }
        }

        string final_res = "";
        int close_br     = 0;

        // Iterate R ---> L to eliminate extra '(' (open brackets)
        for (int i = res.size() - 1; i >= 0; i--) {
            if (res[i] >= 'a' && res[i] <= 'z') {
                final_res.push_back(res[i]);
            }
            else if (res[i] == ')') {
                close_br ++;
                final_res.push_back(res[i]);
            }
            else if (close_br > 0) {    // s[i] == '('
                close_br --;
                final_res.push_back(res[i]);
            }
        }

        reverse(begin(final_res), end(final_res));
        return final_res;
    }

    // TC : O(N)
    // SC : O(1)
    string solve_3(string& s, int n) {
        string res      = "";
        int ignore_open = 0;
        
        // Iterate L ---> R to eliminate extra ')' (close brackets)
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                res.push_back(s[i]);
            }
            else if (s[i] == '(') {
                ignore_open ++;
                res.push_back(s[i]);
            }
            else if (ignore_open > 0) {     // s[i] == ')'
                ignore_open --;
                res.push_back(s[i]);
            }
        }

        string final_res = "";

        // Iterate R ---> L to ignore extra '(' (open brackets)
        int i = res.size() - 1;
        while(i >= 0) {
            if ((res[i] >= 'a' && res[i] <= 'z') || res[i] == ')') {
                final_res.push_back(res[i]);
            }
            else if (res[i] == '(' && ignore_open > 0) {
                ignore_open --;
                i --;
                continue;
            }
            else {
                final_res.push_back(res[i]);
            }
            i --;
        }
        reverse(begin(final_res), end(final_res));
        return final_res;
    }
public:
    string minRemoveToMakeValid(string s) {
        // return solve_1(s, s.length());

        // return solve_2(s, s.length());

        return solve_3(s, s.length());
    }
};