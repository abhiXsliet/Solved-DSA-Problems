// https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:    
    typedef long long ll;
    const ll INF = 1e15;

    // TC : O(N*log(N))
    // SC : O(N)
    vector<ll> getMedianXsizeWindow(vector<int> &nums, vector<ll> &operations, int size, int x) {
        int n = nums.size();
        vector<ll> median(size, 0);
        multiset<ll> maxMst, minMst;
        int i = 0, j = 0;
        ll maxMstSum = 0, minMstSum = 0;
        while (j < n) {
            if (maxMst.empty() || nums[j] < *maxMst.rbegin()) {
                maxMst.insert(nums[j]);
                maxMstSum += nums[j];
            } else {
                minMst.insert(nums[j]);
                minMstSum += nums[j];
            }

            // Balance the set
            if (maxMst.size() > 1 + minMst.size()) {
                auto it = prev(maxMst.end());
                ll val = *it;
                minMst.insert(val);
                maxMst.erase(it);
                minMstSum += (val);
                maxMstSum -= (val);
            } else if (minMst.size() > maxMst.size()) {
                auto it = minMst.begin();
                ll val = *it;
                maxMst.insert(val);
                minMst.erase(it);
                maxMstSum += (val);
                minMstSum -= (val);
            }
            
            if (j - i + 1 == x) {
                if (maxMst.size() > minMst.size()) {
                    median[i] = *maxMst.rbegin();
                } else {
                    auto it = (*maxMst.rbegin() + *minMst.begin()) / 2;
                    median[i] = it;
                }

                ll maxMstVal  = maxMst.size() * median[i];
                ll minMstVal  = minMst.size() * median[i];
                operations[i] = abs(maxMstVal - maxMstSum) + abs(minMstSum - minMstVal);

                // Remove the leftmost element of the window
                if (maxMst.find(nums[i]) != maxMst.end()) {
                    auto it = maxMst.find(nums[i]);
                    maxMst.erase(it);
                    maxMstSum -= nums[i];
                } else {
                    auto it = minMst.find(nums[i]);
                    minMst.erase(it);
                    minMstSum -= nums[i];
                }
                i ++;
            }

            j ++;
        }
        return median;
    }

    // TC : O(N * K)
    // SC : O(N * K) at worst visiting all states 
    ll solve(vector<ll> &operations, int x, int idx, int k, vector<vector<ll>> &dp) {
        if (idx >= operations.size() || k <= 0) {
            return k == 0 ? 0 : INF;
        }

        if (dp[idx][k] != -1)
            return dp[idx][k];

        ll takeRes = solve(operations, x, idx + x, k - 1, dp);
        ll take    = (takeRes >= INF) ? INF : operations[idx] + takeRes;
        ll notTake = solve(operations, x, idx + 1, k, dp);
        
        return dp[idx][k] = min(take, notTake);
    }

    // TC : O(N*log(N) + N*K)
    // SC : O(N * K)
    ll approach_1(vector<int> &nums, int x, int k) {
        int n = nums.size();

        int size = (n - x + 1);
        vector<ll> operations(size, 0);
        vector<ll> median = getMedianXsizeWindow(nums, operations, size, x);

        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1));
        return solve(operations, x, 0, k, dp);
    }
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        return approach_1(nums, x, k);
    }
};