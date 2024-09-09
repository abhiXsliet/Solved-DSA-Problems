// https://leetcode.com/contest/weekly-contest-411/problems/count-substrings-that-satisfy-k-constraint-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    void slidingWindow(string s, int n, int k, vector<ll>& prefix, vector<int>& rightMostIdx) {
        ll ans = 0;
        int i = 0, j = 0;
        vector<int> freq(2, 0);

        while (j < n) {
            freq[s[j] - '0'] ++;
            while (i <= j && freq[0] > k && freq[1] > k) {
                freq[s[i] - '0'] --; 
                i ++;

                rightMostIdx[i] = j - 1;
            }
            if (freq[0] <= k || freq[1] <= k) {
                ans += (j - i + 1);
                prefix[j] = ans;
                
                rightMostIdx[i] = j;
            }

            j ++;
        }
    }
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.length();

        vector<int> rightMostValidIdx(n, n - 1);

        // count of k-constraint valid substring ending at index i
        vector<ll> prefix(n, 0);  
        slidingWindow(s, n, k, prefix, rightMostValidIdx);
        
        vector<ll> result;
        for (auto& query : queries) {
            int low  = query[0];
            int high = query[1];

            ll rValidIdx = min(high, rightMostValidIdx[low]);
            ll len       = rValidIdx - low + 1;

            ll  cntSubstr = (len * (len + 1)) / 2;
            cntSubstr    += prefix[high] - prefix[rValidIdx];

            result.push_back(cntSubstr);
        }
        return result;
    }
};