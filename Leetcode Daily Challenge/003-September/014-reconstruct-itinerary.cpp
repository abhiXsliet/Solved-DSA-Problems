// https://leetcode.com/problems/reconstruct-itinerary/


#include <bits/stdc++.h>
using namespace std;

// TC = O(V^2) 
// SC = O(E) which is approx constant since given that 1 <= tickets.length <= 300 and tickets[i].length == 2
class Solution {
    unordered_map<string, vector<string>> adj;
    vector<string> result;
    int numTickets = 0;

    bool DFS(string fromAirport, vector<string>& path) {
        path.push_back(fromAirport);

        // check if number of tickets + 1 == result.size()
        if (path.size() == numTickets + 1) {
            result = path;
            return true;
        }

        // Explore all neighbours of fromAirport
        vector<string>& neighbours = adj[fromAirport];

        for (int i = 0; i < neighbours.size(); i++) {
            string toAirport = neighbours[i];

            neighbours.erase(neighbours.begin()+i); // To not stuck in cycle

            if(DFS(toAirport, path))  // Explore rest neighbours of fromAirport
                return true;

            neighbours.insert(neighbours.begin()+i, toAirport); // insert the removed neighbours
        }

        path.pop_back(); // remove the current path to explore the next path
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        numTickets = tickets.size();

        // prepare adj list
        for (auto& ticket : tickets) {
            string u = ticket[0];
            string v = ticket[1];

            adj[u].push_back(v);
        }

        // sort the adj edges
        for (auto& edges : adj) {
            sort(begin(edges.second), end(edges.second));
        }

        // Start DFS from the starting node
        vector<string> path;
        DFS("JFK", path);

        return result;
    }
};