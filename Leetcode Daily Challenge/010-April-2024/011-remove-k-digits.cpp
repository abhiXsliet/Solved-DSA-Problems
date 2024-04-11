// https://leetcode.com/problems/remove-k-digits/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N) Where N = length of string num
    // SC : O(N) 
    string solve_1(string num, int k) {
        stack<char> stk;

        for (char& ch : num) {
            while(!stk.empty() && stk.top() > ch && k > 0) {
                stk.pop();
                k --;
            }
            stk.push(ch);
        }
        while(k > 0) {
            stk.pop();
            k --;
        }

        string res = "";
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        
        reverse(begin(res), end(res));
        int idx = res.find_first_not_of('0');
        if (idx != string::npos) {
            return res.substr(idx);
        }

        return "0";
    }

    // TC : O(N) Where N = length of string num
    // SC : O(N) 
    string solve_2(string num, int k) {
        string res = "";

        for (char& ch : num) {
            while(res.length() > 0 && res.back() > ch && k > 0) {
                res.pop_back();
                k --;
            }
            res.push_back(ch);
        }
        
        while(k > 0) {
            res.pop_back();
            k --;
        }

        int idx = res.find_first_not_of('0');
        if (idx != string::npos) {
            return res.substr(idx);
        }

        return "0";
    }

    // TC : O(N) Where N = length of string num
    // SC : O(N)  
    string solve_2_better(string num, int k) {
        string res = "";

        for (char& ch : num) {
            while(res.length() > 0 && res.back() > ch && k > 0) {
                res.pop_back();
                k --;
            }
            if (res.length() > 0 || ch != '0')
                res.push_back(ch);
        }

        while(res.length() > 0 && k > 0) {
            res.pop_back();
            k --;
        }

        if (res.length() > 0) return res;
        return "0";
    }
public:
    string removeKdigits(string num, int k) {
        // return solve_1(num, k);      // MONOTONIC STACK

        // return solve_2(num, k);      // STRING 

        return solve_2_better(num, k);
    }
};