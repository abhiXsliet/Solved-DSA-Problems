// https://leetcode.com/contest/weekly-contest-411/problems/count-substrings-that-satisfy-k-constraint-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    int brute(string s, int k) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            vector<int> freq(2, 0);
            for (int j = i; j < n; j ++) {
                freq[s[j] - '0'] ++;
                if (freq[0] <= k || freq[1] <= k)
                    ans ++;
            }
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(1)
    int optimal(string s, int k) {
        int n = s.length();
       
        int ans = 0;
        int i = 0, j = 0;
        vector<int> freq(2, 0);

        while (j < n) {
            freq[s[j] - '0'] ++;
            while (i <= j && freq[0] > k && freq[1] > k) {
                freq[s[i] - '0'] --; 
                i ++;
            }
            if (freq[0] <= k || freq[1] <= k)
                ans += (j - i + 1);

            j ++;
        }
        
        return ans;
    }
public:
    int countKConstraintSubstrings(string s, int k) {
        // return brute(s, k);

        return optimal(s, k);
    }
};