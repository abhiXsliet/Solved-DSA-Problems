// https://leetcode.com/problems/permutations-ii/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Generating all permutations for an array of size n takes O(n!) time.
    // TC = O(n! * n)
    // SC = O(n) recursive-depth
    void solve(vector<int>nums, set<vector<int>>& st, int index){
        //base case
        if(index >= nums.size()) {
            st.insert(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            solve(nums, st, index+1);
            swap(nums[i], nums[index]);
        }
    }


    // TC = O(n! * n) where n! = no. of permuations and n = looping
    // SC = O(n) + O(n) + O(n) -> freq, ds, recursive-depth space
    void genPermute(vector<int>& nums, int n, set<vector<int>>& st, vector<int>& freq, vector<int>& ds) {
        if (ds.size() == n) {
            st.insert(ds);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!freq[i]) {
                // insert in data structure and mark its freq = 1
                ds.push_back(nums[i]);
                freq[i] = 1;
                // recursive call
                genPermute(nums, n, st, freq, ds);
                // backtrack
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> approach_1(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        vector<int> freq(n, 0);
        vector<int> ds;
        
        genPermute(nums, n, st, freq, ds);

        vector<vector<int>> result;
        for (auto& vec : st) {
            result.push_back(vec);
        }
        return result;
    }

    vector<vector<int>> approach_2(vector<int>& nums) {
        set<vector<int>> st;
        int index = 0;
        solve(nums, st, index);

        vector<vector<int>> result;
        for (auto& i:st) {
            result.push_back(i);
        }
        return result;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // return approach_1(nums);

        return approach_2(nums);
    }
};