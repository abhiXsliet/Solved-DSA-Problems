// https://www.geeksforgeeks.org/problems/minimize-connections/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(int x, vector<int> &parent)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x], parent);
    }

    void unionSet(int a, int b, vector<int> &parent, vector<int> &rank)
    {
        a = find(a, parent);
        b = find(b, parent);
        if (a == b)
            return;

        if (rank[a] < rank[b])
            parent[a] = b;
        else if (rank[b] < rank[a])
            parent[b] = a;
        else
            parent[b] = a, rank[a]++;
    }

    int minConnect(int V, vector<vector<int>> &edges)
    {
        int E = edges.size();

        // Less than V-1 edges = impossible
        if (E < V - 1)
            return -1;

        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++)
            parent[i] = i;

        int redundant = 0;

        // Process each edge
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];

            if (find(u, parent) == find(v, parent))
            {
                // This edge is redundant (forms a cycle)
                redundant++;
            }
            else
            {
                unionSet(u, v, parent, rank);
            }
        }

        // Count connected components
        int components = 0;
        for (int i = 0; i < V; i++)
        {
            if (find(i, parent) == i)
                components++;
        }

        // Need (components - 1) edges
        int need = components - 1;

        if (redundant >= need)
            return need;

        return -1;
    }
};
