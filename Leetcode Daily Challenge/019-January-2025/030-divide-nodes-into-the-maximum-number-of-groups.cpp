// https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(V)
    // SC : O(V) due to recursive call stack
    bool isBipartite(unordered_map<int, vector<int>> &adj, vector<int> &color, int currNode, int currColor) {
        color[currNode] = currColor;    // color 1 : red, color 0 : green
        for (int& nbr : adj[currNode]) {
            if (color[nbr] == color[currNode]) {
                return false;
            } 
            if (color[nbr] == -1) {  // if adjacent node is not colored then color it with corresponding adjacent color
                int nbrColor = 1 - color[currNode];
                if (!isBipartite(adj, color, nbr, nbrColor)) {
                    return false;
                }
            }
        }
        return true;
    }

    // TC : O(V + E)
    // SC : O(V)
    int bfs(unordered_map<int, vector<int>> &adj, int src, int n) {
        vector<bool> visited(n, 0);
        queue<int> q;
        q.push(src);
        visited[src] = 1;
        int level = 1;      // it depicts the max-group in a component
        while (!q.empty()) {
            int size = q.size();
            while (size --) {
                int fNode = q.front();
                q.pop();
                for (int& nbr : adj[fNode]) {
                    if (!visited[nbr]) {
                        q.push(nbr);
                        visited[nbr] = 1;
                    }
                }
            }
            level += 1;
        }
        return level - 1;   // since exiting from while loop gets added and extra +1
    }

    // TC : O(V)
    // SC : O(V) due to recursive call stack
    int getMaxGroupFromEachComponent(unordered_map<int, vector<int>>& adj, vector<int>& level, vector<bool>& vis, int src) {
        vis[src] = 1;
        int maxGroup = level[src];
        for (int &nbr : adj[src]) {
            if (!vis[nbr]) {
                maxGroup = max(maxGroup, getMaxGroupFromEachComponent(adj, level, vis, nbr));
            }
        }
        return maxGroup;
    }
public:
    // TC : O(V * (V + E)) Where V = N
    // SC : O(V + E)
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (vector<int>& edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // step-1 : check if graph is a bipartite?
        vector<int> color(n, -1);  // initially no vertices is colored
        for (int i = 0; i < n; i ++) {
            if (color[i] == -1) {
                if (!isBipartite(adj, color, i, 1)) {
                    return -1;
                }
            }
        }

        // step-2 : if graph is not biparitite, then hit bfs from each node to get max level (i.e., no. of groups) for each node
        vector<int> level(n, 0);   // each index of levels means that no. of max-group all nodes can be assinged into
        for (int i = 0; i < n; i ++) {
            level[i] = bfs(adj, i, n);
        }

        // step-3 : if graph is disconnected then maximize the groups by adding different maximum groups of different components
        int maxGroupEachComp = 0;
        vector<bool> visited(n, 0);
        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                maxGroupEachComp += getMaxGroupFromEachComponent(adj, level, visited, i);
            }
        }
        return maxGroupEachComp;
    }
};