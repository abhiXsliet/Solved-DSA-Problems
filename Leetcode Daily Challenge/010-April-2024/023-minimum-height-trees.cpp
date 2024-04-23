// https://leetcode.com/problems/minimum-height-trees/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(V + E)
    // SC : O(V + E)
    vector<int> solve_optimal(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};

        vector<int> result;
        vector<int> indegree(n);
        unordered_map<int, vector<int>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> que;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 1) //adding all leafs node so that we can remove them later
                que.push(i);
        }
        
        while(n > 2) {
            int size = que.size();
            n -= size; //removing nodes with indegreee 1
            
            while(size--) {
                int u = que.front();
                que.pop();
                for(int v:adj[u]) {
                    indegree[v]--;
                    if(indegree[v] == 1)
                        que.push(v);
                }
            }
        }
        
        while(!que.empty()) {
            result.push_back(que.front());
            que.pop();
        }
        return result;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Brute will be finding height from the every node using BFS and DFS
        
        return solve_optimal(n, edges);
    }
};