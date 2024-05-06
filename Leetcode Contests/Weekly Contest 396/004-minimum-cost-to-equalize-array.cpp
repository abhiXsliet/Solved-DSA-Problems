// https://leetcode.com/problems/minimum-cost-to-equalize-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    int M = 1e9 + 7;

    // TC : O(1)
    // SC : O(1)
    ll solve(vector<int>& nums, int cost1, int cost2, ll max_el, ll min_el, ll sum) {
        ll n = nums.size();
        ll total    = (n * max_el);
        ll tot_opr  = total - sum;
        ll max_opr  = max_el - min_el;

        if (2*cost1 <= cost2) return cost1 * tot_opr;

        ll min_opr = tot_opr - max_opr;
        if (max_opr > tot_opr / 2) {
            return ( (min_opr * cost2) + ((max_opr - min_opr) * cost1) );
        }

        // if total operation is even : make pair to use cost2
        if (tot_opr % 2 == 0) {
            return ( (tot_opr/2) * cost2 );
        }
        // if total operation is odd
        return ( ((tot_opr/2) * cost2) + cost1 );
    }
public:
    // TC : O(max_el)
    // SC : O(1)
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        ll max_el  = *max_element(begin(nums), end(nums));
        ll min_el  = *min_element(begin(nums), end(nums));
        ll sum     = accumulate(begin(nums), end(nums), 0LL);
        ll ans     = LONG_MAX;

        for (ll val = max_el; val <= 2*max_el; val ++) {
            ans = min(ans, solve(nums, cost1, cost2, val, min_el, sum));
        }

        return ans % M;
    }
};