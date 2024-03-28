// https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
private:
    typedef pair<int, int> P;

    // USING FLOYD WARSHALL ALGO
    // TC : O(N^3)
    // SC : O(N^2)
    int solve_approach_1(int n, vector<vector<int>>& edges, int distThres) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < edges.size(); i++) {
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
            dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for (int i = 0; i < n; i++) dist[i][i] = 0;

        // filling the dist matrix using floyd warshall
        for (int via = 0; via < n; via ++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        int cntCity = n;
        // City with the minimum number of reachable city with threshold distance
        int cityNo  = -1;

        for (int city = 0; city < n; city++) {
            int cnt = 0;
            for (int adjCity = 0; adjCity < n; adjCity++) {
                if (dist[city][adjCity] <= distThres) {
                    cnt ++;
                }
            }
            if (cnt <= cntCity) {
                cntCity = cnt;
                cityNo  = city;
            }  
        }

        return cityNo;
    }

    // TC : O(V+E(logV))
    // SC : O(V) for storing the distance array 
    vector<int> dijkstra(int src, vector<vector<P>>& adj, int n) {
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        pq.push({src, 0});

        while (!pq.empty()) {
            int u  = pq.top().first;
            pq.pop();

            for (auto& it : adj[u]) {
                int v = it.first;
                int weight = it.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({v, dist[v]});
                }
            }
        }

        return dist;
    }

    // TC : O(n∗(V+E)logV), where n is the number of nodes
    // SC : O(V+E) for storing the adjacency list
    int solve_approach_2(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<P>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int cntCity = n;
        // City with the minimum number of reachable city with threshold distance
        int cityNo  = -1;

        for (int city = 0; city < n; city++) {

            vector<int> dist = dijkstra(city, adj, n);

            int cnt = 0;
            for (int adjCity = 0; adjCity < n; adjCity++) {
                if (dist[adjCity] <= distanceThreshold) {
                    cnt ++;
                }
            }
            if (cnt <= cntCity) {
                cntCity = cnt;
                cityNo  = city;
            }  
        }

        return cityNo;
    }
public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // return solve_approach_1(n, edges, distanceThreshold);

        return solve_approach_2(n, edges, distanceThreshold);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends