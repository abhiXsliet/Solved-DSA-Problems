// https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int N;
    class UnionFind {
        public:
            vector<int> parent;
            vector<int> rank;

            UnionFind(int n) {
                parent.resize(n);
                rank.resize(n, 0);
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }    
        
            int find (int x) {
                if (x == parent[x]) 
                    return x;

                return parent[x] = find(parent[x]);
            }

            void Union (int x, int y) {
                int x_parent = find(x);
                int y_parent = find(y);

                if (x_parent == y_parent) 
                    return;

                if(rank[x_parent] > rank[y_parent]) {
                    parent[y_parent] = x_parent;
                } else if(rank[x_parent] < rank[y_parent]) {
                    parent[x_parent] = y_parent;
                } else {
                    parent[x_parent] = y_parent;
                    rank[y_parent]++;
                }
            }
    };

    int kruskal(vector<vector<int>> &vec, int skip_edge, int force_add_edge) {
        int sum = 0;
        UnionFind uf(N);
        
        if(force_add_edge != -1) {
            uf.Union(vec[force_add_edge][0], vec[force_add_edge][1]);
            sum += vec[force_add_edge][2];
        }

        for(int i=0; i < vec.size(); i++) {
            if(i == skip_edge)
                continue;
            
            int u  = vec[i][0];
            int v  = vec[i][1];
            int wt = vec[i][2];
            
            int parent_u = uf.find(u);
            int parent_v = uf.find(v);
            
            if(parent_u != parent_v) {
                uf.Union(u, v);
                sum += wt;
            }
        }

        //Check if all vertices are included in MST
        for(int i = 0; i < N; i++) {
            if(uf.find(i) != uf.find(0))
                return INT_MAX;
        }
        
        return sum;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;

        for(int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        auto cmp = [&](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        };

        sort(edges.begin(), edges.end(), cmp);

        int MST_WT = kruskal(edges, -1, -1);
        vector<int> critical;
        vector<int> pseudo_critical;

        for(int i = 0; i < edges.size(); i++) {
            if(kruskal(edges, i, -1) > MST_WT) { // skipping ith edge
                critical.push_back(edges[i][3]);
            }
            else if(kruskal(edges, -1, i) == MST_WT) { // force add ith edge
                pseudo_critical.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo_critical};
    }
};