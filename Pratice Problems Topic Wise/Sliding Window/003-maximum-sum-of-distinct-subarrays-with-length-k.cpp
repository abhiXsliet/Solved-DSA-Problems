// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(N)
    // SC : O(N)
    ll solve_way_1(vector<int>& nums, int n, int k) {
        unordered_map<int, int> mpp;
        int i = 0, j = 0;
        ll result = 0;
        ll sum = 0;

        while (j <= n) {
            if (j - i + 1 > k) {
                sum -= nums[i];
                if(mpp[nums[i]] > 1) {
                    mpp[nums[i]]--;
                } 
                else mpp.erase(nums[i]);
                i++;
            } 
            else {
                if (j != n) {
                    sum += nums[j];
                    mpp[nums[j]] ++;
                }
                j++;
            }
            if (mpp.size() == k)
                result = max(result, sum);
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N)
    ll solve_way_2(vector<int>& nums, int n, int k) {
        unordered_map<int, int> mpp;
        ll result = 0;
        ll sum    = 0;
        int i     = 0;
        
        for (int j = 0; j <= n; j++) {
            if (j - i + 1 > k) {
                sum -= nums[i];
                if (mpp[nums[i]] > 1) mpp[nums[i]] --;
                else mpp.erase(nums[i]);
                i++;
                j--;
            }
            else {
                if (j != n) {
                    sum += nums[j];
                    mpp[nums[j]] ++;
                }
            }
            if (mpp.size() == k)
                result = max(result, sum);
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N)
    ll solve_way_3(vector<int>& nums, int n, int k) {
        unordered_map<int, int> mpp;
        ll result = 0;
        ll sum    = 0;
        
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                int leftMostIdx = i - k;
                sum -= nums[leftMostIdx]; // remove the leftmost element
                if (mpp[nums[leftMostIdx]] > 1) 
                    mpp[nums[leftMostIdx]] --;
                else 
                    mpp.erase(nums[leftMostIdx]);
            }
        
            sum += nums[i];
            mpp[nums[i]] ++;

            if (mpp.size() == k)
                result = max(result, sum);
        }
        return result;
    }
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // return solve_way_1(nums, nums.size(), k);

        // return solve_way_2(nums, nums.size(), k);

        return solve_way_3(nums, nums.size(), k);
    }
};