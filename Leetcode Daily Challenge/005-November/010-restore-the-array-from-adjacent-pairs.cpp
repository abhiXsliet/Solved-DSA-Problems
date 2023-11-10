// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int startingPoint, int prev, unordered_map<int, vector<int>>& adj, vector<int>& result) {
        result.push_back(startingPoint);

        for (int& v : adj[startingPoint]) {
            if (v != prev) {
                dfs(v, startingPoint, adj, result);
            }
        }
    }
public:
    // TC = O(N)
    // SC = O(N)
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> result;

        // prepare adj list;
        unordered_map<int, vector<int>> adj;

        for (auto& vec : adjacentPairs) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int startingPoint = -1;

        for (auto& it : adj) {
            if (it.second.size() == 1) {
                startingPoint = it.first;
                break;
            }
        }

        dfs(startingPoint, INT_MAX, adj, result);

        return result;
    }
};