// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

// similar to : https://leetcode.com/problems/continuous-subarrays/
// similar to : https://www.geeksforgeeks.org/problems/longest-bounded-difference-subarray/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, int> P;

    // TC : O(N*N)
    // SC : O(1)
    int brute(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0, j = 0, ans = 0;
        int mini = nums[0], maxi = nums[0];

        while (j < n) {
            if (j > 0) {
                maxi = max(maxi, nums[j]);
                mini = min(mini, nums[j]);
            }
            
            while (maxi - mini > limit) {
                i ++;
                maxi = *max_element(begin(nums) + i, begin(nums) + j + 1);
                mini = *min_element(begin(nums) + i, begin(nums) + j + 1);
            }

            ans = max(ans, j - i + 1);
            j ++;
        }
        return ans;
    }

    // TC : O(N*log(N))
    // SC : O(N + N)    Where N = Space Used by priority_queue
    int better(vector<int>& nums, int limit) {
        int n = nums.size();
        
        priority_queue<P> maxPq;
        priority_queue<P, vector<P>, greater<P>> minPq;
        
        int i = 0, j = 0, maxLen = 0;
        
        while (j < n) {
            maxPq.push({nums[j], j});
            minPq.push({nums[j], j});
            
            while (maxPq.top().first - minPq.top().first > limit) {
                i = min(maxPq.top().second, minPq.top().second) + 1;

                while (maxPq.top().second < i) maxPq.pop();
                while (minPq.top().second < i) minPq.pop();
            }

            maxLen = max(maxLen, j - i + 1);
            j ++;
        }
        return maxLen;
    }

    // TC : O(N*log(N))
    // SC : O(N)        Where N = No. of elements in nums
    int optimal(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> mst;
        int i = 0, j = 0, maxLen = 0;
        
        while (j < n) {
            mst.insert(nums[j]);

            while (*mst.rbegin() - *mst.begin() > limit) {
                mst.erase(mst.find(nums[i]));
                i ++;
            }

            maxLen = max(maxLen, j - i + 1);
            j ++;
        }

        return maxLen;
    }
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // return brute(nums, limit);

        // return better(nums, limit);

        return optimal(nums, limit);
    }
};