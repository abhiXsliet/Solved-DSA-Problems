// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

public:
    // TC : O(N*log(N))
    // SC : O(N)
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<ll, vector<ll>, greater<>> pq(begin(nums), end(nums));
        int operations = 0;
        while (!pq.empty()) {
            if (pq.size() >= 2 && pq.top() < k) {
                ll x = pq.top(); 
                pq.pop();
                ll y = pq.top();
                pq.pop();

                operations += 1;
                pq.push(min(x, y) * 2 + max(x, y));

            } else break;
        }
        return operations;
    }
};