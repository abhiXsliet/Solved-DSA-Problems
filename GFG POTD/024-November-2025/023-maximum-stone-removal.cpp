// https://www.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1/

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

    int maxRemove(vector<vector<int>> &stones)
    {
        int n = stones.size();

        // Max coordinate <= 10^4 so safe offset is 10001
        int OFFSET = 10001;
        int MAXN = 20005;

        vector<int> parent(MAXN), rank(MAXN, 0);
        for (int i = 0; i < MAXN; i++)
            parent[i] = i;

        unordered_set<int> used;

        for (auto &s : stones)
        {
            int r = s[0];
            int c = s[1] + OFFSET;

            unionSet(r, c, parent, rank);

            used.insert(r);
            used.insert(c);
        }

        int components = 0;
        for (int x : used)
        {
            if (find(x, parent) == x)
            {
                components++;
            }
        }

        return n - components;
    }
};