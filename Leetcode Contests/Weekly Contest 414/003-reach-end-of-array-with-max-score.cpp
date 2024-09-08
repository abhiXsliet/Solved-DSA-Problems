// https://leetcode.com/contest/weekly-contest-414/problems/reach-end-of-array-with-max-score/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(N^2)
    // SC : O(1)
    ll brute(vector<int>& nums) {
        int n  = nums.size();
        ll ans = 0;

        auto maxIt  = max_element(begin(nums), begin(nums) + (n - 1));
        int maxIdx  = distance(begin(nums), maxIt);

        ll maxVal  = nums[maxIdx];
        ll prevIdx = n - 1;

        while (maxIdx >= 0) {
            // cout << "prevIdx : " << prevIdx << " " << "maxIdx : " << maxIdx << " " << "maxVal : " << maxVal<< endl;
            ll val  = (prevIdx - maxIdx) * maxVal;
            ans    += val;
            prevIdx = maxIdx;

            if (maxIdx == 0) break;

            maxIt  = max_element(begin(nums), begin(nums) + maxIdx);
            maxIdx = distance(begin(nums), maxIt);
            // cout << "prevIdx : " << prevIdx << " " << "maxIdx : " << maxIdx << endl;

            maxVal = nums[maxIdx];
        }

        return ans;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    ll optimal(vector<int>& nums) {
        int n  = nums.size();
        ll ans = 0;

        priority_queue<pair<ll, ll>> pq;
        for (int i = 0; i < n - 1; i ++) {
            pq.push({nums[i], i});
        }
        
        ll prevIdx  = n - 1;

        while (!pq.empty()) {
            ll maxVal = pq.top().first;
            ll maxIdx = pq.top().second;
            pq.pop();

            if (maxIdx >= prevIdx) continue;

            ll val = (prevIdx - maxIdx) * maxVal;
            ans   += val;

            prevIdx = maxIdx;
        }
        return ans;
    }
public:
    long long findMaximumScore(vector<int>& nums) {
        // return brute(nums);  

        return optimal(nums);
    }
};