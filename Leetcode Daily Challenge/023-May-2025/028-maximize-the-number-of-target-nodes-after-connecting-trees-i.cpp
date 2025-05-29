// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dfs(unordered_map<int, vector<int>> &adj, int dist, int src, int parent) {
        if (dist < 0) return 0;

        int count = 1;
        for (auto &nbr : adj[src]) {
            if (nbr != parent) {
                count += dfs(adj, dist - 1, nbr, src);
            }
        }

        return count;
    }

    int bfs(unordered_map<int, vector<int>> &adj, int N, int dist, int src) {
        queue<pair<int, int>> q;    // {node, distance}
        vector<bool> visited(N, 0);
        q.push({src, 0});   
        visited[src] = 1;

        int cntTarNodes = 0;
        while (!q.empty()) {
            int currNode = q.front().first;
            int currDist = q.front().second;
            q.pop();

            if (currDist > dist) continue;

            cntTarNodes += 1;   // include curr node as target node

            for (auto &nbr : adj[currNode]) {
                if (!visited[nbr]) {
                    q.push({nbr, currDist + 1});
                    visited[nbr] = 1;
                }
            }
        }
        return cntTarNodes;
    }

    vector<int> getTargetNode(vector<vector<int>>& edges, int k) {
        int N = edges.size() + 1;
        unordered_map<int, vector<int>> adj;

        for (vector<int> &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> result(N, 0);
        for (int i = 0; i < N; i ++) {
            // result[i] = bfs(adj, N, k, i);   // BFS

            result[i] = dfs(adj, k, i, -1);    // DFS
        }
        return result;
    }
public:
    // TC : O(V * (V + E))
    // SC : O(V + E)
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // get the no. of targetNodes in tree1 only at a distance of k
        vector<int> tNodes1 = getTargetNode(edges1, k); 

        // get the no. of targetNodes in tree2 only at a distance of k - 1
        vector<int> tNodes2 = getTargetNode(edges2, k - 1);

        int maxTarNodeVal = *max_element(begin(tNodes2), end(tNodes2));

        for (int &node : tNodes1) {
            node += maxTarNodeVal;
        }

        return tNodes1;
    }
};