// https://leetcode.com/problems/number-of-possible-sets-of-closing-branches/



#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    // TC = O(2^n * n^3)
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int result = 0;

        for (int set = 0; set < (1 << n); set++) { // set < pow(2, n) or <= pow(2, n) - 1

            // store the shortest path
            vector<vector<int>> adjMatrix(n, vector<int>(n, 1e9));

            // Update the graph based on the selected nodes - if present in set
            for (auto road : roads) {
                int u  = road[0];
                int v  = road[1];
                int wt = road[2];

                // TRICKY
                // 3 = 011 (take node 0, 1 only(since both indices are set) 
                //          & node-2(at idx-2 from back) is deleted since it is unset)
                if ((set >> u & 1) && (set >> v & 1)) {
                    
                    // ex: [[1,0,11], [1,0,16], [0,2,13]]
                    adjMatrix[u][v] = min(adjMatrix[u][v], wt);
                    adjMatrix[v][u] = min(adjMatrix[v][u], wt);
                }
            }

            // Floyd warshall -> diagonals are 0
            for (int i = 0; i < n; i++) {
                adjMatrix[i][i] = 0;
            }

            // Applying floyd warshall to find the shortest distance from any node to any other node
            for (int via = 0; via < n; via++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {

                        adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][via] + adjMatrix[via][j]);
                    }
                }
            }

            // Check if shortest distance <= maxDistance
            bool flag = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;

                    // check if (i, j) is present in set
                    if ((set >> i & 1) && (set >> j & 1)) {

                        if (adjMatrix[i][j] > maxDistance) {
                            flag = 0;
                            break;
                        }
                    }
                }
            }
            if (flag) {
                result += 1;
            }
        }

        return result;
    }
};