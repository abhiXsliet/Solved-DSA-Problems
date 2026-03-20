// https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(m * n * k² log k)
    // SC : O(k²)
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {

                set<int> st;

                // collect unique elements
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        st.insert(grid[x][y]);
                    }
                }

                int mini = INT_MAX;

                // iterate set (sorted + unique)
                auto it = st.begin();
                auto prev = it++;
                
                for (; it != st.end(); it++, prev++) {
                    mini = min(mini, *it - *prev);
                }

                result[i][j] = mini == INT_MAX ? 0 : mini;
            }
        }

        return result;
    }
};