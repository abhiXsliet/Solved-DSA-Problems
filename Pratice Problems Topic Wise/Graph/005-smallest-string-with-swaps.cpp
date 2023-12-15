// https://leetcode.com/problems/smallest-string-with-swaps/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(2*N) ~ O(N)
    // SC = O(N) where N = s.length(); at worst all indices will form disconnected components
    void prepareAdj(vector<vector<int>>& pairs, vector<list<int>>& adj) {
        for (int i = 0; i < pairs.size(); i++) {
            int u = pairs[i][0];
            int v = pairs[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    // TC = O(V) -> going through each vertex once only
    // SC = O(V) -> recursive depth 
    void dfs(int node, vector<bool>& vis, vector<list<int>>& adj,
            vector<char>& chars, vector<int>& indices, string& s) {
        chars.push_back(s[node]);
        indices.push_back(node);

        vis[node] = 1;

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, vis, adj, chars, indices, s);
            }
        }
    }
public:
    // TC : O(V*log(V)) where V = s.length();
    // SC : O(V+E)
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();

        // Step-1 : Prepare adjacency list
        vector<list<int>> adj(n);
        prepareAdj(pairs, adj);

        vector<bool> visited(n, 0);

        // Step-2 : Traverse for every components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                
                // Step-3 : create char and indices vector
                vector<char> chars;
                vector<int> indices;

                dfs(i, visited, adj, chars, indices, s);

                // Step-4 : sort the vectors
                sort(begin(chars), end(chars));
                sort(begin(indices), end(indices));

                // Step-5 : Place the characters at their correct position
                for (int j = 0; j < chars.size(); j++) {
                    s[indices[j]] = chars[j];
                }
            }
        }
        return s;
    }
};