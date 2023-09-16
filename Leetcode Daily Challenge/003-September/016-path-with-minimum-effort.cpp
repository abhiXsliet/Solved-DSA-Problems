// https://leetcode.com/problems/path-with-minimum-effort/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    // TC = O(M * N * log(M * N))
    // SC = O(M * N)
    int solve_dijkstras(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        auto isSafe = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n);
        };

        // Intialize the distance array
        vector<vector<int>> distArray(m, vector<int>(n, INT_MAX));

        // create the min heap to track the min distance
        priority_queue<P, vector<P>, greater<P>> pq;

        distArray[0][0] = 0;
        pq.push({0, {0, 0}}); // {dist, {x-coor, y-coor}}

        while(!pq.empty()) {
            int diff  = pq.top().first;
            auto coor = pq.top().second;
            pq.pop();

            int x = coor.first;
            int y = coor.second;

            //Since there is no way that rest of elements can update the weight of destination cell even smaller due to the min heap.
            if (x == m - 1 && y == n - 1) return diff;

            for (auto dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if (isSafe(new_x, new_y)) {

                    int absDiff = abs(heights[x][y] - heights[new_x][new_y]);
                    int maxDiff = max(diff, absDiff);

                    if (distArray[new_x][new_y] > maxDiff) {
                        
                        distArray[new_x][new_y] = maxDiff;
                        pq.push({maxDiff, {new_x, new_y}});
                    }
                }
            }
        }
        return distArray[m - 1][n - 1];
    } 

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        return solve_dijkstras(heights);
    }
};