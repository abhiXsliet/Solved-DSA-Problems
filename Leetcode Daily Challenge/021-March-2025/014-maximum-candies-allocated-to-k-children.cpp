// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    using ll = long long;

    // TC : O(N)
    // SC : O(1)
    bool isPossibleToAllocate(vector<int> &candies, int n, ll k, ll tar) {
        if (tar == 0) return true;
        ll cntChildrens = 0;
        for (int &candy : candies) {
            if (tar > 0 && candy >= tar) {
                cntChildrens += ((ll)candy / tar);
            }
        }
        return cntChildrens >= k;
    }

    // TC : O(N*log(max-element))
    // SC : O(1)
    int approach_1(vector<int> &candies, ll k) {
        int n = candies.size();
        ll low = 0, high = *max_element(begin(candies), end(candies));
        ll ans = 0;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (isPossibleToAllocate(candies, n, k, mid)) {
                ans = mid;
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        return approach_1(candies, k);
    }
};