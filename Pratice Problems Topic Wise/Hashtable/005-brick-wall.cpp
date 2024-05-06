// https://leetcode.com/problems/brick-wall/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N) Where N = No. of Rows
    // SC : O(sum of all elements of a row)
    int leastBricks(vector<vector<int>>& wall) {
        int row = wall.size();
        unordered_map<int, int> mpp; // {gap-position, gaps count}
        int maxGap = INT_MIN;
        
        for (int i = 0; i < row; i ++) {
            int prevSum = 0;
            for (int j = 0; j < wall[i].size() - 1; j ++) {
                int val   = wall[i][j] + prevSum;
                mpp[val] += 1;
                prevSum  += wall[i][j];
                maxGap    = max(maxGap, mpp[val]);
            }
        }
        // returning minimum crossed bricks
        return row - (maxGap == INT_MIN ? 0 : maxGap);
    }
};