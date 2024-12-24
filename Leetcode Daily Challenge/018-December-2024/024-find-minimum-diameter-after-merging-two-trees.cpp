// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    pair<int, int> BFS(int src, unordered_map<int, vector<int>>& adj) {
        queue<int> q;
        unordered_map<int, bool> vis;
        q.push(src);
        vis[src] = 1;

        int farthestNode = src;
        int distance = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size --) {
                int fNode = q.front();
                q.pop();
                
                farthestNode = fNode;

                for (int &nbr : adj[fNode]) {
                    if (!vis[nbr]) {
                        q.push(nbr);
                        vis[nbr] = 1;
                    }
                }
            }
            if (!q.empty()) distance ++;
        }
        return {farthestNode, distance};
    }

    int getDiameter(unordered_map<int, vector<int>>& adj) {
        // Step - 1 : Select a random node (0) and get the farthest node (A)
        //            Which will be one end of the diameter
        auto [nodeA, dist] = BFS(0, adj);

        // Step - 2 : Find other farthest node (B) which will be other end of diameter from node (A)
        auto [nodeB, diameter] = BFS(nodeA, adj);

        return diameter;
    }

    unordered_map<int, vector<int>> prepareAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }

    // TC : O(V + E)
    // SC : O(V + E)
    int approach_1(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = prepareAdj(edges1);
        unordered_map<int, vector<int>> adj2 = prepareAdj(edges2);

        int d1 = getDiameter(adj1);
        int d2 = getDiameter(adj2);

        int combinedTreeDiameter = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        return max({d1, d2, combinedTreeDiameter});
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        return approach_1(edges1, edges2);
    }
};