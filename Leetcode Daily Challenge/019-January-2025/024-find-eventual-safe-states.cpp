// https://leetcode.com/problems/find-eventual-safe-states/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool DFS(vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& inRec, int src) {
        vis[src] = 1;
        inRec[src] = 1;
        for (int& nbr : graph[src]) {
            if (!vis[nbr] && DFS(graph, vis, inRec, nbr)) 
                return true;
            else if (inRec[nbr]) // visited and inRecursion becomes true, cycle detected
                return true;
        }
        inRec[src] = 0;
        return false;
    }

    // TC : O(N)
    // SC : O(N)
    vector<int> approach_1(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, 0);
        vector<bool> inRecursion(n, 0);
        for (int i = 0; i < n; i ++) {
            if (!visited[i])
                DFS(graph, visited, inRecursion, i);
        }

        vector<int> result;
        for (int i = 0; i < n; i ++) {
            if (!inRecursion[i]) {  // nodes outside cycle will be safe nodes
                result.push_back(i);
            }
        }
        return result;
    }

    // TC : O(V + E) where V is the number of nodes and E is the number of edges.
    // SC : O(V + E) for the adjacency list and BFS queue.
    vector<int> approach_2(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);    // new graph with reversed edges
        vector<int> indegree(n, 0);
       
        for (int u = 0; u < n; u ++) {
            for (int& v : graph[u]) {
                adj[v].push_back(u);
                indegree[u] ++;
            }
        }

        // Apply BFS to detect cycle
        queue<int> q;
        for (int i = 0; i < n; i ++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        vector<bool> isSafe(n, 0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            isSafe[u] = 1;

            for (int& v : adj[u]) {
                indegree[v] --;
                if (!indegree[v]) {
                    q.push(v);
                }
            }
        }

        vector<int> result;
        for (int node = 0; node < n; node ++) {
            if (isSafe[node]) {
                result.push_back(node);
            }
        }
        return result;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // return approach_1(graph);    // DFS : cycle detection
        return approach_2(graph);    // BFS
    }
};