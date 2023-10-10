// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/



#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    // TC = O(N * N)
    // SC = O(N)
    int solve_brute(vector<int>& nums) {
        int n = nums.size();
        
        int result = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int minEle = nums[i];
            int maxEle = nums[i] + n - 1; // maxEle - minEle = n - 1;

            unordered_set<int> used;
            int operations = 0;
            
            for (int j = 0; j < n; j++) {
                if (nums[j] >= minEle && nums[j] <= maxEle && used.find(nums[j]) == used.end()) {
                    used.insert(nums[j]);
                    continue;
                } 
                else {
                    operations++;
                }
            }

            result = min(result, operations);
        }

        return result;
    }

    // TC = O(N * log(N))
    // SC = O(N)
    int solve_optimal(vector<int>& nums) {
        int n = nums.size();

        // sort 
        // unique elements
        set<int>st(begin(nums), end(nums));

        vector<int> temp(begin(st), end(st));

        int result = INT_MAX;

        for (int i = 0; i < temp.size(); i++) {
            
            int minEle = temp[i];
            int maxEle = minEle + n - 1;

            int j = upper_bound(begin(temp), end(temp), maxEle) - begin(temp);
            
            int within_range = j - i;
            int out_of_range = n - within_range; // operations

            result = min(result, out_of_range);
        }

        return result;
    }
public:
    int minOperations(vector<int>& nums) {
        // return solve_brute(nums);

        return solve_optimal(nums);
    }
};