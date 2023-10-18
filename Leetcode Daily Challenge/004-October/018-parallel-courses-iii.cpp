// https://leetcode.com/problems/parallel-courses-iii/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        for (int i = 0; i < relations.size(); i++) {
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> maxTime(n, 0);

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                maxTime[i] = time[i];
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for (int &v : adj[node]) {
                
                maxTime[v] = max(maxTime[v], maxTime[node] + time[v]);

                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return *max_element(begin(maxTime), end(maxTime));
    }
};