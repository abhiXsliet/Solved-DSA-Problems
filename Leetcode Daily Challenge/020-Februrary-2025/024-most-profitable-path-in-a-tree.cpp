// https://leetcode.com/problems/most-profitable-path-in-a-tree/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobTime; // bob time to reach each node

    void bfsAlice(vector<int>& amount, vector<bool>& visited, int src, int time, int income, int &maxAliceIncome) {
        queue<vector<int>> q;
        q.push({src, time, income});    // {0, 0, 0}
        visited[0] = true;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int currNode   = it[0];
            int currTime   = it[1];
            int currIncome = it[2];

            if (!bobTime.count(currNode) || bobTime[currNode] > currTime) {   // alice reach first to this currNode since bobTime[currNode] is greater
                currIncome += (amount[currNode]);
            } else if (bobTime[currNode] == currTime) { // alice and bob both reaches at this node in same time
                currIncome += (amount[currNode] / 2);
            }

            // update maxIncome everytime alice reaches a leaf node
            if (adj[currNode].size() == 1 && currNode != 0) {   // currNode can't be a leaf node
                maxAliceIncome = max(maxAliceIncome, currIncome);
            }

            for (auto &nbr : adj[currNode]) {
                if (!visited[nbr]) {
                    q.push({nbr, currTime + 1, currIncome});
                    visited[nbr] = true;
                }
            }
        }
    }

    bool dfsBob(vector<bool>& vis, int src, int dest, int time) {
        vis[src] = 1;
        bobTime[src] = time;    // at time bob is reaching node src
        if (src == dest) {
            return true;
        }

        for (auto &nbr : adj[src]) {
            if (!vis[nbr]) {
                if (dfsBob(vis, nbr, dest, time + 1)) {
                    return true;
                }
            }
        }

        bobTime.erase(src);
        return false;
    }

    void dfsAlice(vector<int>& amount, vector<bool>& visited, int src, int time, int income, int &maxIncome) {
        visited[src] = 1;
        if (!bobTime.count(src) || bobTime[src] > time) {
            income += amount[src];
        } else if (bobTime[src] == time) {  // bob and alice reaching this node at same time
            income += (amount[src] / 2);
        }

        // update maxIncome everytime alice reaches a leaf node
        if (adj[src].size() == 1 && src != 0) { // src != 0 : starting node can't be a leaf node, explore other nodes for leaf
            maxIncome = max(maxIncome, income);
        }

        for (auto &nbr : adj[src]) {
            if (!visited[nbr]) {
                dfsAlice(amount, visited, nbr, time + 1, income, maxIncome);
            }
        }
    }

    int approach_1(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size();  
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, 0);
        dfsBob(visited, bob, 0, 0);
        
        // dest = leaf nodes : to check leaf nodes --> (adj[node].size() == 1)
        visited.assign(n, 0);
        int maxIncome = INT_MIN;  // to track the maxm. income alice could earn
        dfsAlice(amount, visited, 0, 0, 0, maxIncome);

        return maxIncome;
    }

    int approach_2(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size();  
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, 0);
        dfsBob(visited, bob, 0, 0);
        
        // dest = leaf nodes : to check leaf nodes --> (adj[node].size() == 1)
        visited.assign(n, 0);
        int maxIncome = INT_MIN;  // to track the maxm. income alice could earn
        bfsAlice(amount, visited, 0, 0, 0, maxIncome);

        return maxIncome;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // return approach_1(edges, bob, amount);  // dfsBob + dfsAlice
        return approach_2(edges, bob, amount);  // dfsBob + bfs_alice
    }
};