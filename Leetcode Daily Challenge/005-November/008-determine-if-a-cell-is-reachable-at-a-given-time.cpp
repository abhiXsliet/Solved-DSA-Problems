// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
    
    // simple dfs but constraint is 10^9 👊⚡ (Won't work with so high constraint) -> (Infinite Board)
    bool solve_brute_ultra_pro_max(int sx, int sy, int fx, int fy, int t) {
        if (sx < 0 || sy < 0)
            return false;

        if (t == 0) {
            return sx == fx && sy == fy;
        }

        for (auto& dir : directions) {
            int new_sx = sx + dir[0];
            int new_sy = sy + dir[1];

            if (solve_brute_ultra_pro_max(new_sx, new_sy, fx, fy, t-1))
                return true;
        }
        return false;
    }

    // TC = O(1)
    // SC = O(1)
    bool solve_optimal(int sx, int sy, int fx, int fy, int t) {
        int horizontal_dist = abs(fx - sx);
        int vertical_dist   = abs(fy - sy);

        // edge case -> if you want to reach (sx, sy) from (sx, sy) in t = 1 then it is not possible
        if (horizontal_dist == 0 && vertical_dist == 0 && t == 1) {
            return false;
        }

        int min_time = max(horizontal_dist, vertical_dist);

        if (t < min_time)
            return false;
        
        return true;
    }
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // return solve_brute_ultra_pro_max(sx, sy, fx, fy, t);

        return solve_optimal(sx, sy, fx, fy, t);
    }
};