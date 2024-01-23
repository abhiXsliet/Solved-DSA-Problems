// https://leetcode.com/problems/course-schedule/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(V+E), where V is the number of vertices (courses) and E is the number of edges (prerequisites)
    // SC : O(V), for storing the visited vector and the queue.
    // Function to check if a topological sort is possible
    bool checkTopologicalSort(int n, unordered_map<int, vector<int>>& adj, vector<int>& indegree) {
        queue<int> q;
        int cnt = 0;
        
        // Push all nodes with 0 in-degree into the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                cnt ++;
                q.push(i);
            }
        }

        // Process nodes in the queue
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            // Decrease the in-degree of all neighbors
            // If in-degree becomes 0, push it to the queue
            for (auto& neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    cnt ++;
                    q.push(neigh);
                }
            }
        }
        // If able to visit all nodes (i.e., all the courses can be finished)
        // If not able to visit all nodes meaning cycle present
        return cnt == n;
    }

    // TC : O(V + E), where V is the number of vertices (courses) and E is the number of edges (prerequisites)
    // SC : O(V), for storing the visited vector and the stack for DFS
    // DFS function to check for cycle
    void dfs(int node, vector<int>& visited, unordered_map<int, vector<int>>& adj, bool& canFinish) {
        visited[node] = 1;

        for(auto neighbour: adj[node]) {
            // If the node is visited again, then there is a cycle
            if (visited[neighbour] == 1) {
                canFinish = false;
                return;
            }
            else if(visited[neighbour] == 0) {
                dfs(neighbour, visited, adj, canFinish);
            }
        }
        // Mark the node as processed
        visited[node] = 2;
    }

    // TC : O(V + E)
    // SC : O(V + E)
    // Approach 1: Kahn's algorithm for Topological Sort
    bool solve_approach_1(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        
        // Prepare the adjacency list and in-degree array
        for (auto& prerequisit :  prerequisites) {
            int u = prerequisit[0];
            int v = prerequisit[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        // Detect cycle using Kahn's algorithm
        // If cycle detected then course cannot be completed
        return checkTopologicalSort(numCourses, adj, indegree);
    }

    // TC : O(V + E)
    // SC : O(V + E)
    // Approach 2: DFS for cycle detection
    bool solve_approach_2(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        for(auto& prerequisit : prerequisites) {
            int u = prerequisit[0];
            int v = prerequisit[1];

            adj[u].push_back(v);
        }

        vector<int> visited(numCourses);
        bool canFinish = 1;

        // Call DFS function for each component DAG
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0) {
                dfs(i, visited, adj, canFinish);
                if (!canFinish) return false;
            }
        }

        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // return solve_approach_1(numCourses, prerequisites);

        return solve_approach_2(numCourses, prerequisites);
    }
};