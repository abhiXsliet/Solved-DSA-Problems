// https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;
    const int M = 1e9 + 7;
    
    ll power(ll a, ll b) {
        if (b == 0) return 1;

        ll half   = power(a, b / 2);
        ll result = (half * half) % M;

        if (b % 2) {
            result = (result * a) % M;
        }

        return result;
    }
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int blockSize = ceil(sqrt(n));

        unordered_map<int, vector<vector<int>>> queryKMap;

        for (auto &query : queries) {
            int L = query[0];
            int R = query[1];
            int K = query[2];
            int V = query[3];

            if (K >= blockSize) {
                for (int i = L; i <= R; i += K) {
                    nums[i] = (1LL * nums[i] * V) % M;
                }
            } else {   
                queryKMap[K].push_back(query);
            }
        }

        for (auto &[K, queries] : queryKMap) {
            
            vector<ll> diff(n, 1);
            
            for (auto &query : queries) {
                int L = query[0];
                int R = query[1];
                int V = query[3];

                diff[L] = (diff[L] * V) % M;

                int steps = (R - L) / K;
                int nextIdx = L + (steps + 1) * K;

                if (nextIdx < n) diff[nextIdx] = (diff[nextIdx] * power(V, M - 2)) % M;
            }

            // process diff array for cumm prod.
            for (int i = 0; i < n; i ++) {
                if (i - K >= 0) {
                    diff[i] = (diff[i] * diff[i - K]) % M;
                }
            }

            // Apply diff to nums array
            for (int i = 0; i < n; i ++) {
                nums[i] = (1LL * nums[i] * diff[i]) % M;
            }
        }

        int ans = 0;
        for (int &val : nums) ans ^= val;
        return ans;
    }
};