// https://leetcode.com/problems/course-schedule-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(V + E) Where V = Vertices (0 to numsCourses - 1) & E = Adjacent Edges to other vertices
    // SC : O(V)     Space Used by queue
    vector<int> topoSort(int numCourses, unordered_map<int, vector<int>>& adj,
            vector<int>& indegree, vector<int>& result) {
        queue<int> q;
        for (int i = 0; i < numCourses; i ++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int cntNodes = 0;
        while(!q.empty()) {
            int fNode = q.front();
            q.pop();

            result.push_back(fNode);
            cntNodes += 1;

            for (auto& nbr : adj[fNode]) {
                indegree[nbr] --;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        if (cntNodes != numCourses) return {};
        return result;
    }

    // TC : O(V + E) Where V = Number of Courses
    // SC : O(V + E) Where E = Edges b/w a --> b
    vector<int> approach_1(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        vector<int> result;
        
        for (vector<int>& pre : prerequisites) {
            int a = pre[0];
            int b = pre[1];
            
            adj[b].push_back(a);
            indegree[a] ++;
        }
        
        // BFS : Course completion will happen in topological ordering
        return topoSort(numCourses, adj, indegree, result);  
    }

    // TC : O(V + E) Where V = Vertices (0 to numsCourses - 1) & E = Adjacent Edges to other vertices
    // SC : O(V)     Depth of Recursion goes to at max all vertices
    void DFS(int node, bool& hasCycle, unordered_map<int, vector<int>>& adj, 
                    vector<bool>& inRecr, vector<bool>& vis, stack<int>& stk) {
        
           vis[node] = 1;
        inRecr[node] = 1;

        for (auto& nbr : adj[node]) {
            if (!vis[nbr]) {
                DFS(nbr, hasCycle, adj, inRecr, vis, stk);
            } else if (inRecr[nbr]) {
                hasCycle = 1;
                return;
            }
        }

        inRecr[node] = 0;    
        stk.push(node);
	}

    // TC : O(V + E) Where V = Number of Courses
    // SC : O(V + E) Where E = Edges b/w nodes
    vector<int> approach_2(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        
        for (vector<int>& pre : prerequisites) {
            int a = pre[0];
            int b = pre[1];
            adj[b].push_back(a);
        }

        vector<bool>  inRecr(numCourses, 0);
        vector<bool> visited(numCourses, 0);
        stack<int>   stk;
        bool hasCycle = 0;

        for (int i = 0; i < numCourses; i ++) {
            if (!visited[i]) {
                DFS(i, hasCycle, adj, inRecr, visited, stk);
                if(hasCycle) return {}; 
            }
        }
        
        vector<int> result;
        while(!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // return approach_1(numCourses, prerequisites);  // BFS : (Kahn's Algo) -> Topological Sort

        return approach_2(numCourses, prerequisites);     // DFS : (Using Stack) -> Topological Sort
    }
};