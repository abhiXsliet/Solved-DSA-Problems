// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/


#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    // TC = O(N), SC = O(1)
    string solve_approach_1(string s) {
        int n = s.length();

        vector<bool> visited(26, 0);
        vector<int > lastIdx(26, 0);

        for (int i = 0; i < n; i++)
            lastIdx[s[i] - 'a'] = i;

        string result = "";
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';

            if(visited[ch - 'a'] == 1) continue;

            while (result.length() > 0 && result.back() > ch && lastIdx[result.back() - 'a'] > i) {
                visited[result.back() - 'a'] = 0;
                result.pop_back();
            }

            result.push_back(ch);
            visited[ch - 'a'] = 1;
        }
        
        return result;
    }

    // TC = O(N), SC = O(1)
    string solve_approach_2(string s) {
        int n = s.length();
        vector<bool> visited(26, 0);
        vector<int > lastIdx(26, 0);
        stack <char> st;

        for (int i = 0; i < n; i++)
            lastIdx[s[i] - 'a'] = i;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if(visited[ch - 'a'] == true) continue;

            while (st.size() > 0 && st.top() > ch && lastIdx[st.top() - 'a'] > i) {
                visited[st.top() - 'a'] = 0;
                st.pop();
            }

            st.push(ch);
            visited[ch - 'a'] = 1;
        }

        string result = "";
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(begin(result), end(result));
        return result;
    }
public:
    string smallestSubsequence(string s) {
        // return solve_approach_1(s);

        return solve_approach_2(s);
    }
};