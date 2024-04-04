// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)    
    int solve_1(string& s, int n) {
        stack<char> stk;
        int ans = INT_MIN;
        for (char& ch : s) {
            if (ch == '(') {
                stk.push(ch);
            }
            else if (ch == ')') {
                stk.pop();
            }
            int size = stk.size();
            ans = max(ans, size);
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(1)    
    int solve_2(string& s, int n) {
        int open_brackets = 0;
        int ans = INT_MIN;
        for (char& ch : s) {
            if (ch == '(') {
                open_brackets ++;
            }
            else if (ch == ')') {
                open_brackets --;
            }
            ans = max(ans, open_brackets);
        }
        return ans;
    }
public:
    int maxDepth(string s) {
        // return solve_1(s, s.length());

        return solve_2(s, s.length());
    }
};