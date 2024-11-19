// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(N)
    // SC : O(K)
    ll approach_1(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        ll res = 0, sum = 0;
        int i = 0, j = 0;
        while (j < n) {
            while (i <= j && st.count(nums[j])) {
                sum -= nums[i];
                st.erase(nums[i]);
                i ++;
            }

            st.insert(nums[j]);
            sum += nums[j];
            
            if (j - i + 1 == k) {
                res = max(res, sum);
                sum -= nums[i];
                st.erase(nums[i]);
                i ++;
            }

            j ++;
        }
        return res;
    }

    // TC : O(N)
    // SC : O(K)
    ll approach_2(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int i = 0, j = 0;
        ll result = 0;
        ll sum = 0;

        while (j < n) {
            if (j - i + 1 > k) {
                sum -= nums[i];
                if(mpp[nums[i]] > 1) {
                    mpp[nums[i]]--;
                } 
                else mpp.erase(nums[i]);
                i++;
            } 

            sum += nums[j];
            mpp[nums[j]] ++;     
               
            if (mpp.size() == k)
                result = max(result, sum);

            j++;
        }
        return result;
    }
public:
    ll maximumSubarraySum(vector<int>& nums, int k) {
        // return approach_1(nums, k); 
        return approach_2(nums, k); // Remove inner while loop
    }
};