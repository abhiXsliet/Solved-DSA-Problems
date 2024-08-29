// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> parent;
    vector<int> rank;

    int findParent(int u) {
        if (parent[u] != u) 
            parent[u]  = findParent(parent[u]);
        
        return parent[u];
    }

    void Union(int u, int v) {
        int nodeU = findParent(u);
        int nodeV = findParent(v);

        if (nodeU != nodeV) {

            if (rank[nodeU] > rank[nodeV]) {
                parent[nodeV] = nodeU;
            } else if (rank[nodeU] < rank[nodeV]) {
                parent[nodeU] = nodeV;
            } else {
                parent[nodeU] = nodeV;
            }
        }
    }

    void DFS(int idx, int n, vector<bool>& visited, vector<vector<int>>& stones) {
        visited[idx] = 1;
        for (int i = 0; i < n; i ++) {
            // if row or col is same then mark visited as one group memebers
            int row = stones[idx][0];
            int col = stones[idx][1];
            
            if ((!visited[i]) && (stones[i][0] == row || stones[i][1] == col)) {
                DFS(i, n, visited, stones);
            }
        }
    }

    // TC : O(N * N)
    // SC : O(N)
    int approach_1(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, 0);

        int groups = 0;
        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                DFS(i, n, visited, stones);
                groups ++;
            }
        }

        return n - groups;
    }

    // TC : O(N^2 * alpha) ~= O(N^2)
    // SC : O(N)
    int approach_2(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
            rank[i]   = 1;
        }

        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    Union(i, j);    // O(alpha)
                }
            }
        }

        int groups = 0;
        for (int i = 0; i < n; i ++) {
            if (parent[i] == i) {
                groups ++;
            }
        }

        return n - groups;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        // return approach_1(stones);   // DFS

        return approach_2(stones);  // DSU
    }
};