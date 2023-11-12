// https://leetcode.com/problems/bus-routes/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // source is the destination
        if (source == target) 
            return 0;

        // key = stops, value = {indices}
        unordered_map<int, vector<int>> adj; 

        for (int route = 0; route < routes.size(); route++) {
            for (auto& stop : routes[route]) {
                adj[stop].push_back(route);
            }
        }

        // BFS
        queue<int> que;
        vector<bool> visited(501, false);

        // push the source route into queue and marks as visited
        for (auto& route : adj[source]) {
            que.push(route);
            visited[route] = 1;
        }

        // bus count for the source 
        int busCnt = 1;

        while(!que.empty()) {
            int size = que.size();

            while(size--) {
                int route = que.front();
                que.pop();

                for (auto& stop : routes[route]) {
                    if (stop == target) {
                        return busCnt;
                    }

                    // check where the stops lies in another indices of routes
                    for (auto& nextRoute : adj[stop]) {
                        if (!visited[nextRoute]) {
                            visited[nextRoute] = true;
                            que.push(nextRoute);
                        }
                    }
                }
            }
            // after every level increase the bus count
            busCnt++;
        }

        return -1;
    }
};