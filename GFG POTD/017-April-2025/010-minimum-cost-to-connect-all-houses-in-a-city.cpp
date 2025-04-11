// https://www.geeksforgeeks.org/problems/minimum-cost-to-connect-all-houses-in-a-city/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class DSU {
  public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int getParent(int x) {
        if (x == parent[x])
            return x;
            
        return parent[x] = getParent(parent[x]);    // path compression
    }
    
    void doUnion(int u, int v) {
        int u_parent = getParent(u);
        int v_parent = getParent(v);
        
        if (rank[u_parent] == rank[v_parent]) {
            parent[v_parent] = u_parent;
            rank[v_parent] += 1;
        } else if (rank[u_parent] > rank[v_parent]) {
            parent[u_parent] = v_parent;
            rank[v_parent] += 1;
        } else {
            parent[v_parent] = u_parent;
            rank[u_parent] += 1;
        }
    }
};

class Solution {
  private:
    typedef pair<int, int> P;
    typedef vector<int> T;
    
    int kruskalAlgo(int n, priority_queue<T, vector<T>, greater<T>> &pq) {
        DSU dsu(n);
        int sum = 0;
        int edgesAdded = 0;
        
        while (!pq.empty()) {
            int wt = pq.top()[0];
            int u  = pq.top()[1];
            int v  = pq.top()[2];
            pq.pop();
            
            int u_parent = dsu.getParent(u);
            int v_parent = dsu.getParent(v);
            
            if (u_parent != v_parent) {
                edgesAdded += 1;
                dsu.doUnion(u, v);
                sum += wt;
            }
            
            if (edgesAdded == n - 1) break; // pruning
        }
        return sum;
    }
    
    int primsAlgo(int n, unordered_map<int, vector<P>> &adj) {
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> visited(n, 0);
        pq.push({0, 0});    // {cost, node}
        int sum = 0;
        while (!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (visited[node]) continue;
            
            sum += cost;
            
            visited[node] = true;
            
            for (auto &it : adj[node]) {
                int nbr = it.first;
                int nbrCost = it.second;

                if (!visited[nbr]) {
                    pq.push({nbrCost, nbr});
                }
            }
        }
        return sum;
    }
    
    // TC : O(N^2 * log(N))
    // SC : O(N^2)
    int approach_1(vector<vector<int>> &houses) {
        int n = houses.size();
        unordered_map<int, vector<P>> adj;
        
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int x1 = houses[i][0], y1 = houses[i][1];
                int x2 = houses[j][0], y2 = houses[j][1];
                int dist = abs(x2 - x1) + abs(y2 - y1);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        
        return primsAlgo(n, adj);
    }

    // TC : O(N^2 * log(N))
    // SC : O(N^2)
    int approach_2(vector<vector<int>> &houses) {
        int n = houses.size();
        priority_queue<T, vector<T>, greater<T>> pq;
        
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int x1 = houses[i][0], y1 = houses[i][1];
                int x2 = houses[j][0], y2 = houses[j][1];
                int dist = abs(x2 - x1) + abs(y2 - y1);
                pq.push({dist, i, j});
            }
        }
        
        return kruskalAlgo(n, pq);
    }
  public:
    int minCost(vector<vector<int>>& houses) {
        // return approach_1(houses);   // prim's Algo
        return approach_2(houses);   // kruskal Algo
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}
// } Driver Code Ends