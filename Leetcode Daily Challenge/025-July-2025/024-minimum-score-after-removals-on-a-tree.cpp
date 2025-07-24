// https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, int parent, int &timer, vector<int>& xorSubTree, vector<int> &inTime, vector<int> &outTime, vector<int> &nums, unordered_map<int, vector<int>> &adj) {
        xorSubTree[node] = nums[node];
        inTime[node]     = timer;
        timer ++;

        for (auto &nbr : adj[node]) {
            if (nbr != parent) {
                dfs(nbr, node, timer, xorSubTree, inTime, outTime, nums, adj);
                xorSubTree[node] ^= xorSubTree[nbr];
            }
        }

        outTime[node] = timer;
        timer ++;
    }

    // is node u is an ancestor of node v ?
    bool isAncestor(int u, int v, vector<int> &inTime, vector<int> &outTime) {
        return (inTime[u] <= inTime[v] && outTime[v] <= outTime[u]);
    }

    int getScore(int xor1, int xor2, int xor3) {
        int mini = min({xor1, xor2, xor3});
        int maxi = max({xor1, xor2, xor3});
        return (maxi - mini);
    }
public:
    // TC : O(N^2)
    // SC : O(V + E)
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        unordered_map<int, vector<int>> adj;
        for (vector<int> &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> xorSubTree(n, 0), inTime(n, 0), outTime(n, 0);
        int timer = 0;

        // dfs with root node as 0 and parent as -1
        dfs(0, -1, timer, xorSubTree, inTime, outTime, nums, adj);

        int result = INT_MAX;

        for (int u = 1; u < n; u ++) {
            for (int v = u + 1; v < n; v ++) {
                
                int xor1;   // xor of the component-1
                int xor2;   // xor of the component-2
                int xor3;   // xor of the component-3

                if (isAncestor(u, v, inTime, outTime)) {
                    xor1 = xorSubTree[v];
                    xor2 = xorSubTree[u] ^ xor1;
                } else if (isAncestor(v, u, inTime, outTime)) {
                    xor1 = xorSubTree[u];
                    xor2 = xorSubTree[v] ^ xor1;
                } else {
                    xor1 = xorSubTree[u];
                    xor2 = xorSubTree[v];
                }
                // xor-of-root ^ xor-of-subTree-1 ^ xor-of-subTree-2
                xor3 = xorSubTree[0] ^ xor1 ^ xor2;

                result = min(result, getScore(xor1, xor2, xor3));
            }
        }

        return result;
    }
};