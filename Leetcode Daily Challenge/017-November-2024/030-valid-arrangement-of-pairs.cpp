// https://leetcode.com/problems/valid-arrangement-of-pairs/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(V + E) Where V = No. of vertices and E = No. of edges
    // SC : O(V + E) due to recursive stack space
    void dfsHierholzer(int currNode, unordered_map<int, vector<int>>& adj, vector<int>& eularPath) {
        while (!adj[currNode].empty()) {
            int nextNode = adj[currNode].back();
            adj[currNode].pop_back();
            dfsHierholzer(nextNode, adj, eularPath);
        }
        eularPath.push_back(currNode);
    }

    // TC : O(V + E) Where V = No. of vertices and E = No. of edges
    // SC : O(V + E) 
    void stackHierholzer(int src, unordered_map<int, vector<int>>& adj, vector<int>& eularPath) {
        stack<int> stk;
        stk.push(src);
        while (!stk.empty()) {
            int currNode = stk.top();
            if (!adj[currNode].empty()) {
                int nextNode = adj[currNode].back();
                adj[currNode].pop_back();
                stk.push(nextNode);
            } else {
                eularPath.push_back(currNode);
                stk.pop();
            }
        }
    }
public:
    // TC : O(V + E) Where V = No. of vertices and E = No. of edges
    // SC : O(V + E) 
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;
        for (vector<int>& pair : pairs) {
            adj[pair[0]].push_back(pair[1]);
            outdegree[pair[0]] ++;
            indegree[pair[1]]  ++;
        }

        int startNode = pairs[0][0];
        for (auto &it : outdegree) {
            if (outdegree[it.first] - indegree[it.first] == 1) {
                startNode = it.first;
                break;
            }
        }

        vector<int> eularPath; 
        // dfsHierholzer(startNode, adj, eularPath);    // Recursive Approach
        stackHierholzer(startNode, adj, eularPath);  // Iterative Approach
        
        reverse(begin(eularPath), end(eularPath));

        vector<vector<int>> result;
        for (int i = 0; i < eularPath.size() - 1; i ++) {
            result.push_back({eularPath[i], eularPath[i + 1]});
        }
        return result;
    }
};