// https://leetcode.com/problems/remove-duplicate-letters/


#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    // TC = O(N), SC = O(1)
    string solve_optimal_1(string s) {
        int n = s.length();

        vector<bool> visited(26, false);
        vector<int > last_occ_char(26, 0);

        // populate the last occurance of every char
        for (int i = 0; i < n; i++) 
            last_occ_char[s[i] - 'a'] = i;

        string result = "";

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (visited[ch - 'a'] == true) continue;

            // check if last char of result is greater than the current char
            // and it comes at later index
            while (result.length() > 0 && result.back() > ch 
                    && last_occ_char[result.back() - 'a'] > i) {
                
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(ch);
            visited[ch - 'a'] = true;
        }
        return result;
    }

    // TC = O(N), SC = O(1)
    string solve_optimal_2(string s) {
        
        int n = s.length();
        stack<char> st;
        vector<bool> visited(26, 0);
        vector<int > last_occ_char(26, 0);

        for (int i = 0; i < n; i++) {
            last_occ_char[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            
            int idx = s[i] - 'a';

            if (visited[idx] == true) continue;

            while (!st.empty() && s[i] < st.top() && last_occ_char[st.top() - 'a'] > i) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }

        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        reverse(begin(result), end(result));

        return result;
    }
public:
    string removeDuplicateLetters(string s) {
        // return solve_optimal_1(s);

        return solve_optimal_2(s);
    }
};