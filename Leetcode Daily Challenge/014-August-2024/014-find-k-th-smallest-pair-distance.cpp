// https://leetcode.com/problems/find-k-th-smallest-pair-distance/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2 * log(K))
    // SC : O(K)
    int brute_1(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int dist = abs(nums[i] - nums[j]);
                pq.push(dist);
                if (pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }

    // TC : O(N^2 * log(N))
    // SC : O(N^2)
    int brute_2(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> smallestDist;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int dist = abs(nums[i] - nums[j]);
                smallestDist.push_back(dist);
            }
        }
        sort(begin(smallestDist), end(smallestDist));
        return smallestDist[k - 1];
    }

    // TC : O(N^2 + N^2)
    // SC : O(N^2)
    int better(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> smallestDist;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int dist = abs(nums[i] - nums[j]);
                smallestDist.push_back(dist);
            }
        }
        // worst : O(N^2) But average : O(N)
        nth_element(begin(smallestDist), begin(smallestDist) + (k - 1), end(smallestDist));
        return smallestDist[k - 1];
    }

    // TC : O(N^2)
    // SC : O(max_element)
    int optimal_1(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEl = *max_element(begin(nums), end(nums));
        vector<int> vec(maxEl + 1, 0);

        //All pairs
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(nums[i] - nums[j]);
                vec[dist]++;
            }
        }


        for (int d = 0; d <= maxEl; d++) {
            k -= vec[d];
            if (k <= 0) {
                return d; //returning kth smallest distance
            }
        }
        return -1;
    }

    bool isPossible(vector<int>& nums, int mid, int k) {
        // is it possible to have smallest dist as kthDist ??

        int cntPairs = 0;

        int i = 0, j = i + 1;
        while (j < nums.size()) {
            while (nums[j] - nums[i] > mid) i ++;
            cntPairs += (j - i);
            j ++;
        }

        return cntPairs >= k;
    }

    // TC : O(N*log(N) + N*log(max_element))
    // SC : O(1)
    int optimal_2(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));   // O(N*log(N))

        int low = 0, high = nums[n - 1] - nums[0];
        int ans = -1;
        while(low <= high) {    // O(log(max_element)*N)
            int mid = (low + high) >> 1;  
            if (isPossible(nums, mid, k)) { // isPossible to have smallest dist as mid??
                ans  = mid;
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return ans;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // return brute_1(nums, k);     // HEAP
        // return brute_2(nums, k);
        // return better(nums, k);      // using nth_element utility
        // return optimal_1(nums, k);   // Store freq of abs difference
        return optimal_2(nums, k);   // BS + Sliding Window  
    }
};