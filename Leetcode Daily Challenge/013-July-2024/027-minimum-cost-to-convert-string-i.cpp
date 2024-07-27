// https://leetcode.com/problems/minimum-cost-to-convert-string-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N) Where N = original.length()
    // SC : O(1)
    void floydWarshall(vector<vector<long long>>& adjMatrix, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        for (int i = 0; i < original.size(); i++) {
            int src  = original[i] - 'a';
            int dest = changed[i] - 'a';

            adjMatrix[src][dest] = min(adjMatrix[src][dest], (long long)cost[i]);
        }

        // Apply Floyd Warshall 
        for (int via = 0; via < 26; via++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][via] + adjMatrix[via][j]);
                }
            }
        }
    }

    // TC : O(N) Where N = source.length()
    // SC : O(26*26) ~= O(1)
    long long solve_approach_1(string& source, string& target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adjMatrix(26, vector<long long>(26, INT_MAX));

        // Update adjMatrix with shortest path
        floydWarshall(adjMatrix, original, changed, cost);

        long long ans = 0;

        for (int i = 0; i < source.length(); i++) {
            if (source[i] == target[i]) 
                continue;

            int src = source[i] - 'a';
            int dest = target[i] - 'a';

            if (adjMatrix[src][dest] == INT_MAX)
                return -1;
            
            ans += adjMatrix[src][dest];
        }

        return ans;
    }

    void dijkstra(char &src_node, unordered_map<char, vector<pair<char, int>>>& adjList, vector<vector<long long>>& minCostMat) {
        // MIN-HEAP
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;

        pq.push({src_node, 0});

        while (!pq.empty()) {
            char adjNode = pq.top().first;
            int dist     = pq.top().second;
            pq.pop();

            for (auto &it : adjList[adjNode]) {
                char adjNode = it.first;
                int  cost    = it.second;

                if (minCostMat[src_node - 'a'][adjNode - 'a'] > dist + cost) {
                    
                    minCostMat[src_node - 'a'][adjNode - 'a'] = dist + cost;
                    pq.push({adjNode, dist + cost});
                }
            }
        }

        return;
    }

    long long solve_approach_2(string& source, string& target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> adjList;
        
        // Prepare Adjacency List
        for (int i = 0; i < original.size(); i++) {

            adjList[original[i]].push_back({changed[i], cost[i]});
        }

        // Store min cost from node 'a' to all other nodes
        vector<vector<long long>> minCostMat(26, vector<long long>(26, INT_MAX));

        // Populate minCostMat using Dijkstra's Algorithms
        for (int i = 0; i < source.length(); i++) {
            dijkstra(source[i], adjList, minCostMat);
        }

        long long ans = 0;
        for (int i = 0; i < source.length(); i++) {
            if (source[i] == target[i])
                continue;

            int s = source[i] - 'a';
            int d = target[i] - 'a';

            if (minCostMat[s][d] == INT_MAX)
                return -1;

            ans += minCostMat[s][d];
        }

        return ans;
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // return solve_approach_1(source, target, original, changed, cost);

        return solve_approach_2(source, target, original, changed, cost);
    }
};