// https://leetcode.com/problems/course-schedule-iv/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(V * (V + E))
    // SC : O(V)
    void BFS (unordered_map<int, vector<int>>& adj, vector<int>& indegree, unordered_map<int, unordered_set<int>>& mpp) {
        queue<int> q;
        for (int i = 0; i < indegree.size(); i ++) {
            if (!indegree[i]) 
                q.push(i);
        }

        while (!q.empty()) {
            int fNode = q.front();
            q.pop();

            for (int& nbr : adj[fNode]) {
                mpp[nbr].insert(fNode);
                // pre-requisite of fNode nodes will also become pre-requisite of nbr node as well by transitivity
                for (auto& preFnode : mpp[fNode]) { // O(V)
                    mpp[nbr].insert(preFnode);
                }

                indegree[nbr] --;
                if (!indegree[nbr]) 
                    q.push(nbr);
            }
        }
    }

    // TC : O(V)
    // SC : O(V) Recursive Depth
    bool DFS (int src, unordered_map<int, vector<int>>& adj, vector<bool>& vis, int dest) {
        vis[src] = 1;
        if (src == dest) return true;

        bool isReachable = false;
        for (auto& nbr : adj[src]) {
            if (!vis[nbr]) {
                isReachable |= DFS(nbr, adj, vis, dest);
            }
        }
        return isReachable;
    }

    // TC : O(Q * (V + E))
    // SC : O(V + E)
    vector<bool> approach_1(int numCourses, vector<vector<int>>& preReq, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (vector<int>& pre : preReq) {
            int u = pre[0], v = pre[1];
            adj[u].push_back(v);    // u ----> v
        }

        int q = queries.size();
        vector<bool> result(q, 0);
        for (int i = 0; i < q; i ++) {
            int nodeA = queries[i][0], nodeB = queries[i][1];
            vector<bool> visited(numCourses, 0);
            if(DFS(nodeA, adj, visited, nodeB)) {
                result[i] = true;
            }
        }
        return result;
    }

    // TC : O(V^2 * (V + E))
    // SC : O(V + E)
    vector<bool> approach_2(int numCourses, vector<vector<int>>& preReq, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (vector<int>& pre : preReq) {
            int u = pre[0], v = pre[1];
            adj[u].push_back(v);    // u ----> v
        }

        // preComputation[i][j] : i ---> j (i is pre-requisite for j)
        vector<vector<bool>> preComputation(numCourses, vector<bool>(numCourses, 0));
        
        for (int u = 0; u < numCourses; u ++) {
            for (int v = 0; v < numCourses; v ++) {
                vector<bool> visited(numCourses, 0);
                preComputation[u][v] = DFS(u, adj, visited, v);  // u ----> v : u is a prerequisit for v or not?
            }
        }

        int q = queries.size();
        vector<bool> result(q, 0);
        for (int i = 0; i < q; i ++) {
            int nodeA = queries[i][0], nodeB = queries[i][1];
            result[i] = preComputation[nodeA][nodeB];
        }
        return result;
    } 

    // TC : O(V * (V + E)) Kahn's Algo. : V + E and extra V for the internal loop inside kahn's 
    // SC : O(V + E)
    vector<bool> approach_3(int numCourses, vector<vector<int>>& preReq, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (vector<int>& pre : preReq) {
            int u = pre[0], v = pre[1];
            adj[u].push_back(v);    // u ----> v
            indegree[v] ++;
        }

        // {node, {before completion of node course have already completed these many courses}}
        unordered_map<int, unordered_set<int>> mpp;

        BFS(adj, indegree, mpp); // kahn's Algo

        int q = queries.size();
        vector<bool> result(q, 0);
        for (int i = 0; i < q; i ++) {
            int nodeA = queries[i][0];  // src
            int nodeB = queries[i][1];  // dest
            result[i] = mpp[nodeB].contains(nodeA);
        }
        return result;
    } 
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // return approach_1(numCourses, prerequisites, queries);   // DFS : from each query
        // return approach_2(numCourses, prerequisites, queries);   // precomputation of reachable u ---> v : worst than approach_1   
        return approach_3(numCourses, prerequisites, queries);   // BFS : Kahn's Algo
    }
};