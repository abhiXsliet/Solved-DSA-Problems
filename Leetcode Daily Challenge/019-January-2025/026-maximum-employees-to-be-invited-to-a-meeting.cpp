// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int BFS(int src, unordered_map<int, vector<int>>& adj, vector<bool>& vis) {
        // {node, path distance}
        queue<pair<int, int>> q;
        q.push({src, 0});
        int maxDist = 0;
        while (!q.empty()) {
            auto [fNode, fDist] = q.front();
            q.pop();

            for (auto& nbr : adj[fNode]) {
                if (!vis[nbr]) {
                    vis[nbr] = 1;
                    q.push({nbr, fDist + 1});
                    maxDist = max(maxDist, fDist + 1);
                }
            }
        }
        return maxDist;
    }
public:
    // TC : O(N)
    // SC : O(N)
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        // step-1 : make a graph in reverse
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i ++) {
            int u = i, v = favorite[i];
            adj[v].push_back(u);    // u <--- v
        }

        // step-2 : find the cycle len, if cLen = 2 then hit bfs from both nodes to calculate the maxlength 
        //                              if cLen > 2 then get the maxLen of the cycle which will eventually be answer
        int maxEmployeeCycleLen = 0;         // cLen > 2 (cycle made by more than two employees)
        int twoEmployeeCycleLen = 0;         // cLen = 2 (cycle made by only two employee) + bfs(node-1) + bfs(node-2)

        vector<bool> visited(n, false);
        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {  // finding cycle len from here =2 or >2
                // keep tracks of how many nodes visited previously while traversing?
                unordered_map<int, int> mpp;   // previousNodeCountForEachNode

                int currNode    = i;
                int currNodeCnt = 0;    // previously how many nodes we've came across while visiting this currNode

                // until cycle is not detected
                while (!visited[currNode]) {
                    visited[currNode] = 1;
                    mpp[currNode] = currNodeCnt;    // initially prevNodeCnt for currNode is 0

                    // since we are on currNode so prevNodeCnt for currNode increases by 1
                    currNodeCnt += 1;
                    int nextNode = favorite[currNode];  

                    // if nextNode is already visited means a cycle detection, so calculate cycle len
                    if (mpp.count(nextNode)) {
                        int cycleLen = currNodeCnt - mpp[nextNode];

                        maxEmployeeCycleLen = max(maxEmployeeCycleLen, cycleLen);

                        if (cycleLen == 2) {
                            vector<bool>vis(n, 0);
                            vis[currNode] = 1;
                            vis[nextNode] = 1;
                            twoEmployeeCycleLen += (2 + BFS(currNode, adj, vis) + BFS(nextNode, adj, vis));
                        }
                        break;
                    } 
                    
                    currNode = nextNode;
                }
            }
        }
        return max(maxEmployeeCycleLen, twoEmployeeCycleLen);
    }
};