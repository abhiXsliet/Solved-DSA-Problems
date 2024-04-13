// https://leetcode.com/problems/shortest-path-with-alternating-colors/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(unordered_map<int, vector<int>>& redAdj, unordered_map<int, vector<int>>& blueAdj, 
             vector<pair<int, int>>& minDist) {
        
        queue<pair<int, int>> q; // {node, color}
        q.push({0, 1});
        q.push({0, -1});

        minDist[0] = {0, 0};

        int currDist = 0;

        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [fNode, color] = q.front();
                q.pop();

                if (color == 1) {   // red then take from blueAdj
                    for (auto& nbr : blueAdj[fNode]) {
                        if (minDist[nbr].second > currDist + 1) {
                            q.push({nbr, -1});
                            minDist[nbr].second = currDist + 1;
                        }
                    }
                }
                else {  // blue then take redAdj
                    for (auto& nbr : redAdj[fNode]) {
                        if (minDist[nbr].first > currDist + 1) {
                            q.push({nbr, 1});
                            minDist[nbr].first = currDist + 1;
                        }
                    }
                }
            }
            currDist += 1;
        }
    }
public:
    // TC : O(N + M) Where N = No. of Nodes
    // SC : O(N + M) Where M = No. of Edges
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<int>> redAdj;
        unordered_map<int, vector<int>> blueAdj;

        for (auto& ed : redEdges) {
            redAdj[ed[0]].push_back(ed[1]);
        }
        for (auto& ed : blueEdges) {
            blueAdj[ed[0]].push_back(ed[1]);
        }

        vector<pair<int, int>> minDist(n, {INT_MAX, INT_MAX});
        
        bfs(redAdj, blueAdj, minDist);

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int mini = min(minDist[i].first, minDist[i].second);
            ans[i] = (mini == INT_MAX) ? -1 : mini;
        }
        return ans;
    }
};