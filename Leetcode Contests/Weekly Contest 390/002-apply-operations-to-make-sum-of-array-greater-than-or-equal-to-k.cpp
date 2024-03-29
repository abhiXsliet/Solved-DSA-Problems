// https://leetcode.com/problems/apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(K)
    // SC : O(1)
    bool isPossible(int k, int mid) {
        for (int i = 0; i < k; i++) {
            long long sum = 1 + i;
            int opr = (mid - i + 1);
            sum = sum * opr;
            if (sum >= k) return true;
        }
        return false;
    }

    // TC : O(K*log(K))
    // SC : O(1)
    int solve_1(int k) {
        int low = 0, high = k - 1;
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;   // operations
            if (isPossible(k, mid)) {   // is it possible to form 'k' in mid operations?
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    // TC : O(K)
    // SC : O(1)
    int solve_2(int k) {
        int opr = k - 1;
        for (int sum = 2; sum <= k/2; sum++) {
            int increaseOpr  = sum - 1;         // Operation-1
            int duplicateOpr = (k / sum) - 1;   // Operation-2
            if (k % sum != 0) duplicateOpr++;
            opr = min(increaseOpr + duplicateOpr, opr);
        }
        return opr;
    }

    // TC : O(?)
    // SC : O(?)
    int solve_3(int k, int sum, int val, vector<int>& dp) {
        if (sum >= k) return 0;

        if (dp[val] != -1) return dp[val];

        int op_1 = 1 + solve_3(k, sum + 1, val + 1, dp);
        int op_2 = 1 + solve_3(k, sum + val, val  , dp);

        return dp[val] = min(op_1, op_2);
    }
public:
    int minOperations(int k) {
        // return solve_1(k);            // BS

        // return solve_2(k);            // Greedy

        vector<int> dp(k+1, -1);
        return solve_3(k, 1, 1, dp);  // 1D - DP : because we only care about the val not sum since only val helping to find the answer

        // return solve_4(k);            // O(1) : PENDING
    }
};