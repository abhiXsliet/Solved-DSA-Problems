// https://www.geeksforgeeks.org/problems/second-best-minimum-spanning-tree/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct DSU {
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n);
            size.assign(n, 1);
            for(int i=0;i<n;i++) parent[i] = i;
        }
        int find(int x) {
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        bool unite(int a, int b) {
            a = find(a);
            b = find(b);
            if(a == b) return false;
            if(size[a] < size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
    };

    int kruskal(int V, vector<vector<int>>& edges, int skipEdgeIndex) {
        DSU dsu(V);
        int total = 0;
        int used = 0;

        for(int i = 0; i < edges.size(); i++) {
            if(i == skipEdgeIndex) continue; // skip this MST edge

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if(dsu.unite(u, v)) {
                total += w;
                used++;
            }
        }

        return (used == V-1 ? total : INT_MAX); // if not fully connected, invalid
    }

    int secondMST(int V, vector<vector<int>>& edges) {
        // Sort using Kruskal
        vector<vector<int>> sortedEdges = edges;
        sort(sortedEdges.begin(), sortedEdges.end(), 
             [](auto &a, auto &b){ return a[2] < b[2]; });

        int E = sortedEdges.size();

        // First MST
        DSU dsu(V);
        int mstWeight = 0;
        vector<int> mstEdges; // indexes of edges used in MST

        for(int i = 0; i < E; i++) {
            int u = sortedEdges[i][0];
            int v = sortedEdges[i][1];
            int w = sortedEdges[i][2];

            if(dsu.unite(u, v)) {
                mstWeight += w;
                mstEdges.push_back(i);
            }
        }

        // If MST not possible
        if(mstEdges.size() != V-1) return -1;

        // Try forming second MST
        int secondBest = INT_MAX;

        for(int idx : mstEdges) {
            int weight = kruskal(V, sortedEdges, idx);
            if(weight > mstWeight)
                secondBest = min(secondBest, weight);
        }

        return (secondBest == INT_MAX ? -1 : secondBest);
    }
};