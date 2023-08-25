// https://leetcode.com/problems/contains-duplicate-iii/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N*N) -> TLE
    // SC = O(1)
    bool solve_brute(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if( i != j && abs(i - j) <= indexDiff 
                    && abs(nums[i] - nums[j]) <= valueDiff ) {
                    return 1;
                }
            }
        }
        return 0;
    }
    // TC = O(N*K)
    // SC = O(1)
    bool solve_better(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < i+1+indexDiff; j++) {
                
                if(j >= n) break;
                if(abs(nums[i] - nums[j]) <= valueDiff)
                    return 1;
            }
        }
        return 0;
    }

    // TC = O(N*K)
    // SC = O(K)
    // Sliding Window Approach
    bool solve_optimal_1(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            int num = (nums[i]);

            for (int candidate : s) {
                if (abs(candidate - num) <= valueDiff)
                    return true;
            }

            s.insert(num);
            if (i >= indexDiff)
                s.erase(nums[i - indexDiff]);
        }
        return false;
    }

    // TC = O(N*log(K))
    // SC = O(K) where K = indexDiff
    // Sliding Window Approach
    bool solve_optimal_2(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            auto floorIt = s.lower_bound(num - valueDiff);
            if (floorIt != s.end() && *floorIt <= num + valueDiff)
                return true;

            s.insert(num);
            if (i >= indexDiff)
                s.erase(nums[i - indexDiff]);
        }
        return false;
    }

    // TC = O(N)
    // SC = O(K)
    // Using Bucket Sort
    bool solve_optimal_3(vector<int>& nums, int indexDiff, int valueDiff) {
        if (nums.size() == 0 || indexDiff <= 0 || valueDiff < 0)
            return false;

        unordered_map<int, int> numToIndex;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            // Determine the bucket that num belongs to
            int bucket = (valueDiff > 0) ? num / valueDiff : num;
            
            // Check the current bucket and adjacent buckets
            for (int j = -1; j <= 1; j++) {
                if (numToIndex.find(bucket + j) != numToIndex.end() &&
                    abs(numToIndex[bucket + j] - num) <= valueDiff) {
                    return true;
                }
            }
            
            numToIndex[bucket] = num;

            // Remove the entry if it's beyond the sliding window
            if (i >= indexDiff) {
                if (valueDiff == 0) {
                    numToIndex.erase(nums[i - indexDiff]);
                } else {
                    numToIndex.erase(nums[i - indexDiff] / valueDiff);
                }
            }
        }
        return false;
    }

public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        // return solve_brute(nums, indexDiff, valueDiff);

        // return solve_better(nums, indexDiff, valueDiff);

        // return solve_optimal_1(nums, indexDiff, valueDiff);

        // return solve_optimal_2(nums, indexDiff, valueDiff);

        return solve_optimal_3(nums, indexDiff, valueDiff);
    }
};