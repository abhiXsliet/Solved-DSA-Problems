// https://leetcode.com/problems/apply-operations-to-maximize-frequency-score/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    bool isPossible(vector<int>& nums, ll k, int len, vector<ll>& prefixSum, int n) {
        if (len == 0) return false;

        int i = 0;
        int j = len - 1;
        // O(N)
        while (j < n) {
            ll target_idx = (i + j) >> 1;
            ll target = nums[target_idx];

            ll left_opr  = 0;
            ll right_opr = 0;
            
            // find no of opr needed to make all elements on left side of the target equal to the target
            // no. of elements on the left side = (target_idx - i)
            // required_sum = target * (target_idx - i)
            // old_sum  = prefixSum[target_idx - 1] - prefixSum[i - 1]
            // then left_opr = abs(required_sum - old_sum)
            if (target_idx == 0) {
                left_opr = 0;
            }
            else {
                left_opr = abs( (target * (target_idx-i)) - (prefixSum[target_idx-1] - (i > 0 ? prefixSum[i - 1] : 0)) );
            }
            
            // find no of opr needed to make all elements on right side of the target equal to the target
            // no. of elements on the right side = (j - target_idx)
            // required_sum = (j - target_idx) * target
            // old_sum      = prefixSum[j] - prefixSum[target_idx];
            // then right_opr = abs(required_sum - old_sum)
            right_opr = abs( (target * (j - target_idx)) - (prefixSum[j] - prefixSum[target_idx]) );

            // If the total number of operations is less than or equal to k, 
            // then it is possible to make all elements in the subarray of size 'len' equal
            if (left_opr + right_opr <= k) 
                return true;
            
            i ++;
            j ++;
        }

        return false;
    }
public:
    // TC : O(N*log(N))
    // SC : O(N)
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();

        // sorting makes easier to make numbers equal to target
        sort(begin(nums), end(nums));

        // Calculate the prefixSum -> helpful to count left or right operations in O(1)
        vector<ll> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        // Applying Binary Search On Answer
        int left  = 1; // minimum score could be
        int right = n; // maximum score could be
        int res   = 1; // since every element is present at least once in array

        while (left <= right) { // O(log(N))
            // mid_score 
            int mid = (left + right) >> 1;

            if (isPossible(nums, k, mid, prefixSum, n)) {
                res  = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return res;
    }
};