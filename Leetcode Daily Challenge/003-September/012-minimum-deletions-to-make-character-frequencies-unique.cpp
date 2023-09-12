// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N)
    // SC = O(1)
    int solve(string s) {
        int freq[26] = {0};
        for (char &ch : s) {
            freq[ch - 'a']++;
        }

        unordered_set<int> st;
        int result = 0;
        for (int i = 0; i < 26; i++) {
            while( freq[i] > 0 && st.find(freq[i]) != st.end() ) {
                freq[i]--;
                result++;
            }
            st.insert(freq[i]);
        }
        return result;
    }

    // TC = O(N)
    // SC = O(1)
    int solve_optimal_1(string s) {
        vector<int> count(26, 0);
        int length = s.length();
        
        for (int i = 0; i < length; i++) {
            count[s[i] - 'a']++;
        }
        
        // sort the count in decreasing order
        // sort (freq, freq+26, greater<int>()); // stl

        auto cmp = [](int a, int b) {
            return a > b;
        };
        sort(count.begin(), count.end(), cmp);
        
        int result = 0;
        for (int i = 1; i < 26; i++) {
            while(count[i] >= 1 && count[i] >= count[i - 1]) {            
                count[i]--;
                result++;
            }
        }
        return result;
    }
        
    // TC = O(N)
    // SC = O(1)
    int solve_optimal_1_modified(string s) {
        int freq[26] = {0};
        for (char &ch : s) {
            freq[ch - 'a']++;
        }
        
        // sort in ascending order
        sort(freq, freq+26);

        int result = 0;
        for (int i = 24; i >= 0 && freq[i] > 0; i--) {
            if (freq[i] >= freq[i+1]) { // to maintain ascending order
                
                int prev = freq[i];
                freq[i]  = max(0, freq[i+1]-1); // to maintain the ascending order
                result  += (prev - freq[i]);

            }
        }
        return result;
    }
       
public:
    int minDeletions(string s) {
        // return solve(s);

        return solve_optimal_1(s);
        
        // return solve_optimal_1_modified(s);
    }
};