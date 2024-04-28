// https://leetcode.com/problems/sum-of-distances-in-tree/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long root_result_baseNode = 0;
    vector<int> count;  // store the count of subtree of a node including that node
    int N;

    int dfsRoot(unordered_map<int, vector<int>>& adj, int curr_node, int prev_node, int curr_depth) {
        int total_node = 1;
        root_result_baseNode += curr_depth;
        for (auto& child : adj[curr_node]) {
            if (child == prev_node) continue;

            total_node += dfsRoot(adj, child, curr_node, curr_depth + 1);
        }
        count[curr_node] = total_node;
        return total_node;
    }

    void DFS(unordered_map<int, vector<int>>& adj, int parent_node, int prev_node, vector<int>& result) {
        for(auto& child : adj[parent_node]) {
            if (child == prev_node) continue;

            result[child] = result[parent_node] - count[child] + (N - count[child]);

            DFS(adj, child, parent_node, result);
        }
    }
public:
    // TC : O(N)
    // SC : O(N)
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        N = n;
        count.resize(n, 0);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        root_result_baseNode = 0;

        dfsRoot(adj, 0, -1, 0);

        vector<int> result(n, 0);
        result[0] = root_result_baseNode;
        DFS(adj, 0, -1, result);

        return result;
    }
};