// https://leetcode.com/problems/sum-of-distances/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    // TC : O(N)
    // SC : O(N)
    vector<ll> distance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < n; i ++) {
            mpp[nums[i]].push_back(i);
        }

        vector<ll> result(n, 0);
        for (auto &it : mpp) {
            vector<int> &vec = it.second;

            int len = vec.size();
            if (len == 1) continue;

            vector<ll> pref(len, vec[0]), suff(len, vec[len - 1]);

            for (int i = 1; i < len; i ++) {
                pref[i] = pref[i - 1] + vec[i];
                suff[len - i - 1] = suff[len - i] + vec[len - i - 1];
            }

            for (int i = 0; i < len; i ++) {
                ll leftEleCnt  = i;
                ll rightEleCnt = len - i - 1;
                
                ll leftVal = 0, rightVal = 0;
                if (i + 1 < len) {
                    rightVal = abs(suff[i + 1] - (rightEleCnt * vec[i]));
                }
                if (i - 1 >= 0) {
                    leftVal  = abs(pref[i - 1] - (leftEleCnt * vec[i]));
                }

                result[vec[i]] = (leftVal + rightVal);
            }
        }

        return result;
    }
};