// https://leetcode.com/problems/count-alternating-subarrays/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(N)
    // SC : O(1)
    ll approach_1(vector<int>& nums) {
        ll ans = 0LL;
        ll i = 0, j = 0, n = nums.size();
        while(j < n) {
            while (j < n - 1 && nums[j] != nums[j + 1]) {
                j ++;
            }
            // length of current alternating subarray
            ll len = (j - i) * ((j - i) + 1) / 2;
            // add the cnt of subarray in current alternating subarray
            ans += len;
            j ++;
            i = j;  // move for the next alternating subarray
        }
        return ans + n;  
    }

    // TC : O(N)
    // SC : O(1)
    ll approach_1_better(vector<int>& nums) {
        ll ans = 0LL;
        ll i = 0, j = 0, n = nums.size(), prev = -1;
        while(j < n) {
            if (nums[j] == prev) {
                i = j;
            }
            // add the cnt of subarray in current alternating subarray
            ans += (j - i + 1);
            prev = nums[j];  // move for the next alternating subarray
            j ++;
        }
        return ans;  
    }
public:
    ll countAlternatingSubarrays(vector<int>& nums) {
        // return approach_1(nums);

        return approach_1_better(nums);
    }
};