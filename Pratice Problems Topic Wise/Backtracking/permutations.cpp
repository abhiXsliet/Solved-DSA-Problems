// https://leetcode.com/problems/permutations/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    // Generating all permutations for an array of size n takes O(n!) time.
    // TC = O(n! * n)
    // SC = O(n) recursive-depth
    void solve(vector<int>nums, vector<vector<int>>& ans, int index){
        //base case
        if(index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            solve(nums, ans, index+1);
            swap(nums[i], nums[index]);
        }
    }

    // TC = O(n! * n) where n! = no. of permuations and n = looping
    // SC = O(n) + O(n) + O(n) -> freq, ds, recursive-depth space
    void genPermutations(vector<int>& nums, int n, vector<int>& ds, vector<int>& freq, vector<vector<int>>& result) {
        if (ds.size() == n) {
            result.push_back(ds);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;

                genPermutations(nums, n, ds, freq, result);

                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> approach_1(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> ds;
        vector<int> freq(n, 0);
        genPermutations(nums, n, ds, freq, result);
        return result;
    }

    vector<vector<int>> approach_2(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // return approach_1(nums);

        return approach_2(nums);
    }
};