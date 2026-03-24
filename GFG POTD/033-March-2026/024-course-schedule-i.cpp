// https://www.geeksforgeeks.org/problems/course-schedule-i/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N + M)
    // SC : O(N + M)
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        for (vector<int> &pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]] ++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i ++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        
        if (q.empty()) return 0;
        
        int cnt = n;
        while (!q.empty()) {
            int fNode = q.front();
            q.pop();
            
            cnt --;
            
            for (int &node : adj[fNode]) {
                indegree[node] --;
                if (!indegree[node]) 
                    q.push(node);
            }
        }
        return cnt == 0;
    }
};