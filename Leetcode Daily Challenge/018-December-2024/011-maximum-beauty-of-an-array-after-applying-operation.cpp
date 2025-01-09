// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    bool isPossibleMidInRange(vector<int>& nums, int k, int mid) {
        for (int i = 0; i <= nums.size() - mid; i++) {
            // Check if the `mid-th` element's range overlaps with the first element's range
            if (nums[i + mid - 1] - k <= nums[i] + k) {
                return true;
            }
        }
        return false;
    }

    // TC : O(N * log(N))
    // SC : O(N)
    int approach_1(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, char>> ranges;
        for (int i = 0; i < n; i++) {
            ranges.push_back({nums[i] - k, 'S'});
            ranges.push_back({nums[i] + k, 'E'});
        }

        auto cmp = [&](pair<int, char> p1, pair<int, char> p2) {
            if (p1.first == p2.first) {
                return p1.second == 'S' && p2.second == 'E';
            } 
            return p1.first < p2.first;
        };
        sort(begin(ranges), end(ranges), cmp);

        int track = 0;
        int maxCut = 0;
        for (auto& it : ranges) {
            if (it.second == 'S') 
                track++;
            else 
                track--;
            maxCut = max(maxCut, track);
        }
        return maxCut;
    }

    // TC : O(N + range)
    // SC : O(range)
    int approach_2(vector<int>& nums, int k) {
        int n = nums.size();
        int endRange   = *max_element(begin(nums), end(nums)) + k;
        
        // diffArray to mark the start and end of each range
        vector<int> diffArray(endRange + 2, 0);   
        for (int &num : nums) {
            int start = (num - k) < 0 ? 0 : (num - k);
            int end   = (num + k);
            diffArray[start]   += 1;
            diffArray[end + 1] -= 1;
        }
        int ans = 0;
        for (int i = 1; i <= endRange; i ++) {
            diffArray[i] += diffArray[i - 1];
            ans = max(ans, diffArray[i]);
        }
        return ans;
    }

    // TC : O(N * log(N)) 
    // SC : O(1)
    int approach_3(vector<int>& nums, int k) {
        // finding the maximum number of ranges that can overlap at any point
        int n = nums.size();
        sort(begin(nums), end(nums));

        int low = 1, high = n; // min and max beauty of array
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Check if there exists a set of `mid` ranges that overlap
            if (isPossibleMidInRange(nums, k, mid)) {
                ans = mid;
                low = mid + 1;  // Try to find a larger set
            } else {
                high= mid - 1;  // Try to find a smaller set
            }
        }
        return ans;
    }

    bool overlap(vector<int>& nums, int i, int j, int k) {
        return nums[j] - k <= nums[i] + k; // return true if overlapping
    }

    // TC : O(N*log(N))
    // SC : O(1)
    int approach_4(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int result = 0;
        int i = 0, j = 0;
        while (j < n) {
            while (i < j && !overlap(nums, i, j, k)) {
                i ++;
            }
            // overlap : nums[j] - k <= num[i] + k
            result = max(result, j - i + 1);
            j ++;
        }
        return result;
    }
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // return approach_1(nums, k);  // Line Sweep Algo : Pair start ('S') and end ('E') intervals, sort them, and track maximum count by incrementing for 'S' and decrementing for 'E'

        // return approach_2(nums, k); // Line Sweep Algo : Frequency Counting in range overlapping

        // return approach_3(nums, k); // Binary Search on possible targets : [min(nums[i]) - k, max(nums[i]) + k]
        
        return approach_4(nums, k); // Sliding Window
    }
};