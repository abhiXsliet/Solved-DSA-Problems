// https://leetcode.com/problems/design-graph-with-shortest-path-calculator/


#include <bits/stdc++.h>
using namespace std;


// ------------------------------------- Approach - 1 (Dijkstra's using priority_queue) --------------------------------------------------------------------

// TC = O(M * ElogV)
// SC = O(N)

class Graph {
public:
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_map<int, vector<pair<int, int>>> adj;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            adj[u].push_back({v, cost});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        adj[u].push_back({v, cost});
    }
    
    int shortestPath(int node1, int node2) {
        // shortest distance from node-1 to all vertices
        vector<int> result(N, INT_MAX); 

        result[node1] = 0;
        pq.push({0, node1});

        while(!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& neigh : adj[node]) {

                int adjNode = neigh.first;
                int adjDist = neigh.second;

                if (dist + adjDist < result[adjNode]) {

                    result[adjNode] = dist + adjDist;
                    pq.push({dist+adjDist, adjNode});

                }
            }
        }

        // shortest distance between node1 to node2
        return result[node2] == INT_MAX ? -1 : result[node2];
    }
};


// --------------------------------------- Approach - 2 : Floyd Warshall Algorithms -------------------------------------------------------------------------


class Graph {
public:
    vector<vector<int>> adjMatrix;
    int N; 
    // TC = O(N * N * N)
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        adjMatrix = vector<vector<int>>(n, vector<int>(n, 1e9));

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            
            // cost of going from 'u' to 'v'
            adjMatrix[u][v] = cost;
        }
        // cost of going from self to self
        for (int i = 0; i < n; i++) {
            adjMatrix[i][i] = 0;
        }

        // Floyd Warshall Algo
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][via] + adjMatrix[via][j]);

                }
            }
        }
    }

    // TC = O(N*N)
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        // check new edge u ---> v cost and update min in adjMatrix
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                
                adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][u] + cost + adjMatrix[v][j]);

            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return adjMatrix[node1][node2] != 1e9 ? adjMatrix[node1][node2] : -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */