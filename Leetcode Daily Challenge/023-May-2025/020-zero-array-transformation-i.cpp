// https://leetcode.com/problems/zero-array-transformation-i/




#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> sweep_line(n, 0);

        for (vector<int>& query : queries) {
            int li = query[0];
            int ri = query[1];
            sweep_line[li] += 1;
           if (ri + 1 < n) sweep_line[ri + 1] -= 1;
        }
        
        for (int i = 1; i < n; i ++) {
            sweep_line[i] +=  sweep_line[i - 1];
        }

        for (int i = 0; i < n; i ++) {
            if (sweep_line[i] < nums[i]) {
                return false;
            }
        }

        return true;
    }
};