// https://leetcode.com/problems/minimum-time-to-repair-cars/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    
    ll isPossible(vector<int> &ranks, ll minutes, int cars) {
        ll cntRepairs = 0;
        for (int r : ranks) {
            if (r == 0) continue;
            ll val = (ll)minutes / r;
            cntRepairs += sqrt(val);
        }
        return cntRepairs >= cars;
    }
public:
    // TC : O(N * log(high))
    // SC : O(1)
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        int max_rank = *max_element(begin(ranks), end(ranks));
        ll low  = 1;
        ll high = max_rank * ((ll)cars * cars);
        ll ans  = 0;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (isPossible(ranks, mid, cars)) {
                cout << mid << endl;
                ans  = mid;
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }

        return ans;
    }
};