// https://leetcode.com/problems/diagonal-traverse-ii/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    // TC = O(N)
    // SC = O(N)
    vector<int> solve_approach_1(vector<vector<int>>& nums) {
        int n = nums.size();

        // {row + col , vector<int>}
        unordered_map<int, vector<int>> mpp;    

        for (int row = n - 1; row >= 0; row--) {
            for (int col = 0; col < nums[row].size(); col++) {

                mpp[row + col].push_back(nums[row][col]);
            }
        }

        vector<int> result;
        int diagonal = 0;
        
        while (mpp.find(diagonal) != mpp.end()) {
            for (int& el : mpp[diagonal]) {
                result.push_back(el);
            }
            diagonal++;
        }
        
        return result;
    }

    // TC = O(N)
    // SC = O(max-diagonal size) = size of queue
    vector<int> solve_approach_2(vector<vector<int>>& nums) {
        int n = nums.size();

        vector<int> result;

        queue<pair<int, int>> que;

        que.push({0, 0});

        while(!que.empty()) {

            auto [row, col] = que.front();
            que.pop();

            result.push_back(nums[row][col]);

            if (col == 0 && row + 1 < n) {
                que.push({row + 1, col});
            }

            if (col + 1 < nums[row].size()) {
                que.push({row, col + 1});
            }
        }
        return result;
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // return solve_approach_1(nums);

        return solve_approach_2(nums);
    }
};