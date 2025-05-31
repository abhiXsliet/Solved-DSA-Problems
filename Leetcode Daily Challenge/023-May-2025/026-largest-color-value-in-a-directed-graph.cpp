// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(V + E)
    // SC : O(V + E)
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]] ++;
        }

        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26, 0));

        for (int i = 0; i < n; i ++) {
            if (!indegree[i]) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }

        int largestColorVal = 0;
        int countNodes = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            countNodes += 1;
            largestColorVal = max(largestColorVal, dp[u][colors[u] - 'a']);

            for (int &v : adj[u]) {
                for (int i = 0; i < 26; i ++) {
                    dp[v][i] = max(dp[v][i], dp[u][i] + (colors[v] - 'a' == i));
                }

                indegree[v] --;
                if (!indegree[v]) {
                    q.push(v);
                }
            }
        }

        return (countNodes < n) ? -1 : largestColorVal;
    }
};