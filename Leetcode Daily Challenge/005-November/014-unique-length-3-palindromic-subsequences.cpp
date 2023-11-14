// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(26 * n) ~ O(n)
    // SC = O(26)     ~ O(n)
    int solve_approach_1(string& s) {
        int n = s.length();
        int result = 0;

        unordered_set<char> letters;
        for (char &ch : s) {
            letters.insert(ch);
        }

        for (char letter : letters) {

            int leftIdx  = -1;
            int rightIdx = -1;

            for (int i = 0; i < n; i++) {

                if (s[i] == letter) {
                    
                    if (leftIdx == -1)
                        leftIdx = i;
                    
                    rightIdx = i;
                }
            }

            unordered_set<char> st;
            for (int mid_elements = leftIdx + 1; mid_elements <= rightIdx - 1; mid_elements++) {
                st.insert(s[mid_elements]);
            }

            result += st.size();
        }

        return result;
    }

    // TC = O(N)
    // SC = O(1)
    int solve_approach_1_modified(string& s) {
        int n = s.length();
        int result = 0;

        // store the left and right most indices of every char
        vector<pair<int, int>> indices(26, {-1, -1});   // O(1)
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a'; // a = 0, b = 1,...

            if (indices[idx].first == -1) 
                indices[idx].first = i;
            
            indices[idx].second = i;
        }

        for (int i = 0; i < 26; i++) {  // O(1)

            int leftIdx  = indices[i].first;
            int rightIdx = indices[i].second;

            if (leftIdx == -1) 
                continue;

            unordered_set<char> st;
            for (int mid_elements = leftIdx + 1; mid_elements <= rightIdx - 1; mid_elements++) {    // O(n)
                st.insert(s[mid_elements]);
            }

            result += st.size();
        }

        return result;
    }
public:
    int countPalindromicSubsequence(string s) {
        // return solve_approach_1(s);

        return solve_approach_1_modified(s);
    }
};