// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // mark vertices true which has indegree edges
        vector<bool> indegree(n, 0);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            indegree[v] = 1;
        }

        // store all the vertices which has 0-indegree
        // so that with the help of these vertices all nodes can be reached
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == false) {
                result.push_back(i);
            }
        }

        return result;
    }
};