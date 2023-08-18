// https://leetcode.com/problems/maximal-network-rank/


#include <bits/stdc++.h>
using namespace std;

class Solution {

    void prepareAdj(unordered_map<int, set<int>>& adjList, vector<vector<int>>& roads) {
        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            adjList[u].insert(v);
            adjList[v].insert(u);
        }
    }

    void prepareAdj_new(int n, vector<vector<int>>& roads, 
                    vector<int>& degree, vector<vector<bool>>& connected) {
        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            degree[u]++;
            degree[v]++;

            connected[u][v] = true;
            connected[v][u] = true;
        }
    }

    // TC = O(N^2) -> square of no. of vertices
    // SC = O(1)
    int Approach_1(int n, vector<vector<int>>& roads,
                    unordered_map<int, set<int>>& adjList) {
        // traverse on each pair
        int maxRank = INT_MIN;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int rank_i = adjList[i].size();
                int rank_j = adjList[j].size();
                int total_rank = rank_i + rank_j;

                if (adjList[i].find(j) != adjList[i].end()) {
                    total_rank -= 1;
                }

                maxRank = max(maxRank, total_rank);
            }
        }

        return maxRank;
    }
    
    // TC = O(N^2)
    // SC = O(N^2)
    int Approach_2(int n, vector<vector<int>>& roads, vector<int>& degree, 
                    vector<vector<bool>>& connected) {
        // traverse on each pair
        int maxRank = INT_MIN;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int rank_i = degree[i];
                int rank_j = degree[j];
                int total_rank = rank_i + rank_j;

                if (connected[i][j]) {
                    total_rank -= 1;
                }

                maxRank = max(maxRank, total_rank);
            }
        }

        return maxRank;
    }
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, set<int>> adjList;
        // prepare adjacency list
        prepareAdj(adjList, roads);
        // return Approach_1(n, roads, adjList);
        

        vector<int> degree(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, 0));
        prepareAdj_new(n, roads, degree, connected);
        return Approach_2(n, roads, degree, connected);
    }
};