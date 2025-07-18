// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;

    // TC : O(N*log(N))
    // SC : O(N)
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int len = n/3;

        vector<ll> leftMin(n, 0), rightMax(n, 0);
        priority_queue<ll> maxH;
        priority_queue<ll, vector<ll>, greater<>> minH;

        ll sumLeftMin = 0, sumRightMax = 0;
        for (int i = 0; i < 2*len; i ++) {
            sumLeftMin += nums[i];
            maxH.push(nums[i]);
            if (maxH.size() > len) {
                sumLeftMin -= maxH.top();
                maxH.pop();
            }
            leftMin[i] = sumLeftMin;

            sumRightMax += nums[n - i - 1];
            minH.push(nums[n - i - 1]);
            if (minH.size() > len) {
                sumRightMax -= minH.top();
                minH.pop();
            }
            rightMax[n - i - 1] = sumRightMax;
        }

        ll result = LONG_MAX;
        for (int i = len - 1; i < 2*len; i ++) {
            result = min(result, (leftMin[i] - rightMax[i + 1]));
        }
        return result;
    }
};