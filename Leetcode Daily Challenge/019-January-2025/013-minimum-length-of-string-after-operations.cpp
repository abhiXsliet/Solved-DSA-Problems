// https://leetcode.com/problems/minimum-length-of-string-after-operations/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int deleteClosest(vector<int>& arr) {
        int deleted = 0;
        for (int i = 3; i <= arr.size(); i += 2) {
            deleted += 1;
        }
        return deleted;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_1(string &s) {
        int n = s.length();
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i ++) {
            mpp[s[i] - 'a'].push_back(i);
        }   
        int totalDeleted = 0;
        for (auto& it : mpp) {
            totalDeleted += deleteClosest(it.second);
        }
        return n - 2*totalDeleted;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(string &s) {
        int n = s.length();
        vector<int> freq(26, 0);
        int deleted = 0;
        for (char &ch : s) {
            int idx = ch - 'a';
            if (freq[idx] >= 2) {
                deleted += 2;
                freq[idx] = freq[idx] + 1 - 2;
            } else {
                freq[idx] ++;
            }
        }
        return n - deleted; 
    }

    // TC : O(N)
    // SC : O(1)
    int approach_3(string &s) {
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a'] ++;
        }
        int remaining = 0;
        for (int& f : freq) {
            if (f == 0) continue;
            if (f % 2) {
                remaining += 1;
            } else {
                remaining += 2;
            }
        }
        return remaining;
    }
public:
    int minimumLength(string s) {
        // return approach_1(s);    // Brute
        // return approach_2(s);    // Better
        return approach_3(s);    // Optimal
    }
};