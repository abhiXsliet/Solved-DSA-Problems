// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(unordered_map<int, vector<int>> &adj, vector<int> &mark, int src, int parent, int &cntZeroMarked, int &cntOneMarked) {

        if (mark[src] == 0) {
            cntZeroMarked += 1;
        } else {
            cntOneMarked += 1;
        }

        for (auto &nbr : adj[src]) {
            if (nbr != parent) {
                mark[nbr] = (mark[src] == 0) ? 1 : 0;
                dfs(adj, mark, nbr, src, cntZeroMarked, cntOneMarked);
            }
        }
    }

    unordered_map<int, vector<int>> prepareAdj(vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        for (vector<int> &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }
public:
    // TC : O(V + E)
    // SC : O(V + E)
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size(), m = edges2.size();

        unordered_map<int, vector<int>> adj1 = prepareAdj(edges1);
        unordered_map<int, vector<int>> adj2 = prepareAdj(edges2);

        // mark nodes of tree-1 : 0 and 1 -> depicting even and odd respectively
        int cntZeroMarked1 = 0, cntOneMarked1 = 0;
        vector<int> mark1(n + 1, -1);
        mark1[0] = 0;
        dfs(adj1, mark1, 0, -1, cntZeroMarked1, cntOneMarked1);

        // mark nodes of tree-2 : 0 and 1 -> depicting even and odd respectively
        int cntZeroMarked2 = 0, cntOneMarked2 = 0;
        vector<int> mark2(m + 1, -1);
        mark2[0] = 0;
        dfs(adj2, mark2, 0, -1, cntZeroMarked2, cntOneMarked2);

        int maxValAfterMarking = max(cntZeroMarked2, cntOneMarked2);  

        vector<int> result(n + 1);
        for (int i = 0; i <= n; i ++) {
            result[i] = (mark1[i] == 0) ? cntZeroMarked1 : cntOneMarked1;
            result[i] += maxValAfterMarking;
        }
        return result;
    }
};