// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isContinuous(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return true;

        int diff = arr[1] - arr[0];
        for (int i = 1; i < n; i ++) {
            if (arr[i] - arr[i - 1] != diff || diff <= 0 || diff > 1) {
                return false;
            }
        } 
        return true;
    }

    // TC : O(N * K)
    // SC : O(K)
    vector<int> brute(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n - k + 1, -1);

        for (int i = 0; i + k - 1 < n; i ++) {
            vector<int> subarray;
            for (int j = i; j <= i + k - 1; j ++) {
                subarray.push_back(nums[j]);
            }
            
            if (isContinuous(subarray)) {
                result[i] = *max_element(begin(subarray), end(subarray));
            }
        }
        
        return result;
    }

    // TC : O(N)
    // SC : O(1)
    vector<int> optimal(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return nums;

        vector<int> result(n - k + 1, -1);
        int i = 0, j = 1;
        while (j < n) {
            while (j - 1 >= 0 && j < n && nums[j - 1] + 1 == nums[j]) {
                if (j - i + 1 == k) {
                    result[i] = nums[j];
                    i ++;
                }
                j ++;
            }
            if (j < n && nums[j] != nums[j - 1] + 1) {
                i = j;
            }
            j ++;
        }
        return result;
    }
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        // return brute(nums, k);
        
        return optimal(nums, k);
    }
};