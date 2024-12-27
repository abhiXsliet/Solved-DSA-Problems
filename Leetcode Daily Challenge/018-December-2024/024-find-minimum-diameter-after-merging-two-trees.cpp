// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(V + E)
    // SC : O(V + E)
    void buildAdj(vector<vector<int>>& edges, unordered_map<int, vector<int>>& adj, vector<int>& indeg) {
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indeg[edge[0]] ++;
            indeg[edge[1]] ++;
        }
    }

    // TC : O(V + E)
    // SC : O(V + E)
    // Leaf stripping BFS technique to get the minimum height of the tree
    int getMinimumHeightTree(unordered_map<int, vector<int>>& adj, vector<int>& indegree) {
        int n = indegree.size();
        queue<int> q;
        // push all leaf nodes into the queue
        for (int i = 0; i < n; i ++) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }

        int minHeight = 0;
        while (n > 2) {
            int size = q.size();
            n -= size;
            while (size --) {
                int fNode = q.front();
                q.pop();

                for (auto& nbr : adj[fNode]) {
                    indegree[nbr] --;
                    if (indegree[nbr] == 1) {
                        q.push(nbr);
                    }
                }
            }
            minHeight ++;
        }
        if (q.size() == 2) 
            return 2*minHeight + 1;
        return 2*minHeight;
    }

    // TC : O(V + E)
    // SC : O(V + E)
    // This fn. provides the distance of with an end node of diameter
    pair<int, int> BFS(int src, unordered_map<int, vector<int>>& adj) {
        queue<int> q;
        unordered_map<int, bool> vis;
        q.push(src);
        vis[src] = 1;

        int farthestNode = src;
        int distance = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size --) {
                int fNode = q.front();
                q.pop();
                
                farthestNode = fNode;

                for (int &nbr : adj[fNode]) {
                    if (!vis[nbr]) {
                        q.push(nbr);
                        vis[nbr] = 1;
                    }
                }
            }
            if (!q.empty()) distance ++;
        }
        return {farthestNode, distance};
    }

    int getDiameter(unordered_map<int, vector<int>>& adj) {
        // Step - 1 : Select a random node (0) and get the farthest node (A)
        //            Which will be one end of the diameter
        auto [nodeA, dist] = BFS(0, adj);

        // Step - 2 : Find other farthest node (B) which will be other end of diameter from node (A)
        auto [nodeB, diameter] = BFS(nodeA, adj);

        return diameter;
    }

    // TC : O(V + E)
    // SC : O(V + E)
    unordered_map<int, vector<int>> prepareAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }

    // TC : O(V + E)
    // SC : O(V + E)
    int approach_1(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = prepareAdj(edges1);
        unordered_map<int, vector<int>> adj2 = prepareAdj(edges2);

        int d1 = getDiameter(adj1);
        int d2 = getDiameter(adj2);

        int combinedTreeDiameter = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        return max({d1, d2, combinedTreeDiameter});
    }

    // TC : O(N + E) + O(M + E)
    // SC : O(N + E) + O(M + E)
    int approach_2(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size(), m = edges2.size();
        vector<int> indegree1(n + 1, 0);
        vector<int> indegree2(m + 1, 0);

        unordered_map<int, vector<int>> adj1;
        unordered_map<int, vector<int>> adj2;

        buildAdj(edges1, adj1, indegree1);
        buildAdj(edges2, adj2, indegree2);

        int d1 = getMinimumHeightTree(adj1, indegree1);
        int d2 = getMinimumHeightTree(adj2, indegree2);
        int d3 = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        return max({d1, d2, d3});
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // return approach_1(edges1, edges2); // Get d1 from t-1, d2 from t-2, d3 from both (t1, t2) 
                                              // and return max{d1, d2, d3}

        return approach_2(edges1, edges2);  // BFS : Leaf Stripping Tech. to find the MHT
    }
};