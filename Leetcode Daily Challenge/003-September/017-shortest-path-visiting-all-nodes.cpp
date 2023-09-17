// https://leetcode.com/problems/shortest-path-visiting-all-nodes/


#include <bits/stdc++.h>
using namespace std;


class Solution {
    typedef pair<int, int> P; // {node, mask} -> (i.e, 0 -> 0001 - (1), 1 -> 0010 - (2), 2 -> 0100 - (4), 3 -> 1000 - (8))
    
    // Tc = O(N * N)
    // SC = O(N)
    int solve_bfs_on_all_nodes(vector<vector<int>>& graph) {
        int n = graph.size();

        if (n == 0 || n == 1) return 0;

        queue<P> que;
        set<P> visited;

        // BFS from all nodes
        for (int i = 0; i < n; i++) {
            // calculate ith node mask value (i.e, 0 -> 0001, 1 -> 0010, 2 -> 0100, 3 -> 1000)
            int maskValue = (1 << i); 

            que.push({i, maskValue});
            visited.insert({i, maskValue});
        }

        int allVisitedStates = (1 << n) - 1; // after all visited states -> 1111 -----> pow(2, n) - 1
        int path = 0;

        while (!que.empty()) {
            int size = que.size();
            path ++;

            while (size--) {
                P curr = que.front(); // {node, mask}
                que.pop();

                int currNode = curr.first;
                int currMask = curr.second;

                for (int &adj : graph[currNode]) {
                    
                    int nextMask = currMask | (1 << adj); // (1 << adj) gives the maskValue of adj node

                    if (nextMask == allVisitedStates) { // 1111
                        return path;
                    }

                    if (visited.find({adj, nextMask}) == visited.end()) {
                        visited.insert({adj, nextMask});
                        que.push({adj, nextMask});
                    }
                }
            }  
        }
        return -1;
    }
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        return solve_bfs_on_all_nodes(graph);
    }
};