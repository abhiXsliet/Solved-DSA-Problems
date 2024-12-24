// https://leetcode.com/problems/minimum-height-trees/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Depth-First Search to calculate the maximum depth of the tree from a given node
    int DFS(int src, unordered_map<int, vector<int>>& adj, vector<bool>& vis) {
        vis[src] = true;
        int maxDepth = 0;
        for (auto& nbr : adj[src]) {
            if (!vis[nbr]) {
                vis[nbr] = true;
                maxDepth = max(maxDepth, 1 + DFS(nbr, adj, vis));
            }
        }
        return maxDepth;
    }

    // Brute Force Approach: Compute maximum height for each node using DFS
    // TC: O(N^2) -> N nodes, each performing a DFS that takes O(N)
    // SC: O(N) -> For the adjacency list and visited array
    vector<int> approach_1(int n, vector<vector<int>>& edges) {
        // Build adjacency list
        unordered_map<int, vector<int>> adj;
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> storeMaxHeight(n, 0); // Store max height for each node
        int minHeight = n; // Initialize to a large value
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false); // Reset visited array for each node
            storeMaxHeight[i] = DFS(i, adj, visited); // Calculate max depth from node i
            minHeight = min(minHeight, storeMaxHeight[i]); // Update min height
        }

        // Find all nodes with the minimum height
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (storeMaxHeight[i] == minHeight) {
                result.push_back(i);
            }
        }
        return result;
    }

    // Optimized Approach: Leaf-Stripping using BFS
    // TC: O(N) -> Each edge and node is processed once
    // SC: O(N) -> For adjacency list, queue, and degree array
    vector<int> approach_2(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // Special case: Single node

        // Build adjacency list and degree array
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        // Initialize the queue with all leaf nodes (nodes with degree = 1)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }

        // Remove leaf nodes layer by layer until only 1 or 2 nodes remain
        while (n > 2) { // Remaining nodes form the MHT roots
            int size = q.size();
            n -= size; // Reduce the number of nodes
            while (size--) {
                int fNode = q.front();
                q.pop();

                // Decrease the degree of neighbors and push new leaves
                for (int& nbr : adj[fNode]) {
                    indegree[nbr]--;
                    if (indegree[nbr] == 1) {
                        q.push(nbr);
                    }
                }
            }
        }

        // Collect the remaining nodes as MHT roots
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // return approach_1(n, edges); // Brute force DFS approach
        
        return approach_2(n, edges);    // Optimized approach: Leaf-stripping using BFS
    }
};
