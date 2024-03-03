// https://leetcode.com/contest/biweekly-contest-125/problems/minimum-operations-to-exceed-threshold-value-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    // TC : O(N*log(N))
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int num : nums) {
            pq.push(num);
        }
        
        int cnt = 0;
        while (pq.size() > 0) {
            ll x = pq.top(); pq.pop();
            ll y = pq.top(); pq.pop();

            if (x >= k && y >= k) return cnt;
            
            ll mini = min(x, y);
            mini   *= 2;
            
            ll maxi = max(x, y);
            ll val  = (mini + maxi);

            pq.push(val);
            cnt ++;
        }
        return cnt;
    }
};