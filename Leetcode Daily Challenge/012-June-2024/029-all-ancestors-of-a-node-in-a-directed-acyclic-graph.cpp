// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(V + E)
    // SC : O(V) Where V = No. of Vertices & E = Edges
    vector<int> BFS(unordered_map<int, vector<int>>& adj, vector<int>& inDegree) {
        queue<int> q;
        int n = inDegree.size();
        vector<int> topoSort;

        for (int i = 0; i < n; i ++) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int fNode = q.front();
            q.pop();
            topoSort.push_back(fNode);
            for (auto& nbr : adj[fNode]) {
                inDegree[nbr] --;
                if (inDegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        return topoSort;
    }

    // TC : O(V + E) Where V = No. of Vertices & E = Edges
    // SC : O(V) => Recursive Depth
    void DFS(unordered_map<int, vector<int>>& adj, int ancestor, int node, vector<vector<int>>& result) {

        for (auto& nbr : adj[node]) {
            if (result[nbr].empty() || result[nbr].back() != ancestor) {
                result[nbr].push_back(ancestor);
                DFS(adj, ancestor, nbr, result);
            }
        }
    }

    // TC : O(V + E) Where V = No. of Vertices & E = Edges
    // SC : O(V) => Recursive Depth
    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        visited[node] = 1;
        for (auto& nbr : adj[node]) {
            if (!visited[nbr]) {
                visited[nbr] = 1;
                dfs(nbr, adj, visited);
            }
        }
    }

    // TC : O(V * (V + E))
    // SC : O(V + E) Where V = No. of Vertices & E = Edges
    vector<vector<int>> approach_1(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);    // u ------> v
        }

        vector<vector<int>> result(n);
        for (int i = 0; i < n; i ++) {
            int ancestor = i;
            DFS(adj, ancestor, i, result);
        }
        return result;
    }

    // TC : O(V * (V + E))
    // SC : O(V + E) Where V = No. of Vertices & E = Edges
    vector<vector<int>> approach_2(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);    // u <------- v
        }

        vector<vector<int>> result(n);
        for (int u = 0; u < n; u ++) {
            vector<int> ancestor;
            vector<bool> visited(n, 0);
            dfs(u, adj, visited);

            for (int i = 0; i < n; i ++) {
                if (i == u) continue;

                if (visited[i]) {   // it means 'i' is ancestor
                    ancestor.push_back(i);
                }
            }
            result[u] = ancestor;
        }
        return result;
    }

    // TC : O(V^2 + (V+E) + Vlog(V)) -> O(V+E) for building the graph and performing the topological sort, 
    //                               -> O(V^2) for processing each node and merging ancestor lists.
    //                               -> O(VlogV) for sorting the ancestor lists for each node.
    // SC : O(V^2 + E)    
    vector<vector<int>> approach_3(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n, 0);
        for (auto& edge : edges) {  // O(V + E)
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);    // u -------> v
            inDegree[v] ++;
        }

        // O(V + E)
        vector<int> topologicalSort = BFS(adj, inDegree);

        vector<unordered_set<int>> vec(n);  // to store the ancestors 
        
        // O(V*V)
        for (int& node : topologicalSort) { // node will be ancestor of 'v'
            for (auto& v : adj[node]) {
                vec[v].insert(node);
                vec[v].insert(vec[node].begin(), vec[node].end());
            }
        }

        vector<vector<int>>result(n);

        for (int i = 0; i < n; i ++) {
            result[i] = vector<int>(vec[i].begin(), vec[i].end());
            
            sort(begin(result[i]), end(result[i]));
        }

        return result;
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // return approach_1(n, edges);

        // return approach_2(n, edges);

        return approach_3(n, edges);
    }
};