// https://leetcode.com/problems/k-diff-pairs-in-an-array/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(N)
    int solve_brute(vector<int>& nums, int n, int k) {
        set<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (i != j && abs(nums[j] - nums[i]) == k) {
                    st.insert({min(nums[i], nums[j]), max(nums[i], nums[j])});
                }
            }
        }
        return st.size();
    }

    // TC : O(log(N))
    // SC : O(1)
    bool getNextEle(vector<int>& nums, int low, int high, int tar) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == tar) {
                return true;
            }
            else if (nums[mid] > tar){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return false;
    }
    
    // TC : O(N*log(N))
    // SC : O(1)
    // USING BINARY SEARCH
    int solve_better_1(vector<int>& nums, int n, int k) {
        int pairCnt = 0;

        sort(begin(nums), end(nums));

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (getNextEle(nums, i+1, n-1, nums[i] + k)) {
                pairCnt++;
            }
        }
        return pairCnt;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    // USING TWO POINTER APPROACH
    int solve_better_2(vector<int>& nums, int n, int k) {
        int pairCnt = 0;

        sort(begin(nums), end(nums));
        int i = 0;
        int j = 1;

        while (i < n && j < n) {
            if (abs(nums[i] - nums[j]) < k) {
                j++;
            }
            else if (abs(nums[i] - nums[j]) == k) {
                pairCnt ++;
                i++, j++;

                while (j < n && nums[j] == nums[j - 1]) j++;
            }
            else {
                i++;
                // if j & i is pointing to same element
                if (j == i) j++;
            }
        }
        return pairCnt;
    }

    // TC : O(N)
    // SC : O(N)
    int solve_optimal(vector<int>& nums, int n, int k) {
        unordered_map<int, int> mpp;
        for (int num : nums) mpp[num]++;

        int pairCnt = 0;
        for (auto& it : mpp) {
            if ( (k == 0 && it.second > 1) || (k && mpp.count(it.first + k)) )
                pairCnt++;
        }

        return pairCnt;
    }
public:
    int findPairs(vector<int>& nums, int k) {
        // return solve_brute(nums, nums.size(), k);

        // return solve_better_1(nums, nums.size(), k);

        // return solve_better_2(nums, nums.size(), k);

        return solve_optimal(nums, nums.size(), k);
    }
};