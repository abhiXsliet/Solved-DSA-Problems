// https://leetcode.com/problems/find-all-people-with-secret/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, int> P;

    // TC : ~O(M*(M+N)) where M = Number Of Meetings, N = Number Of People
    // SC : O(M+N)
    vector<int> solve_approach_1(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<P>> timeVsMeetings;
        for (auto& meeting : meetings) {
            int p1 = meeting[0];
            int p2 = meeting[1];
            int t  = meeting[2];

            timeVsMeetings[t].push_back({p1, p2});
        }

        vector<bool> knowsSecret(n, 0);
        knowsSecret[0]           = 1;
        knowsSecret[firstPerson] = 1;

        for (auto& it : timeVsMeetings) {
            int time  = it.first;
            auto meet = it.second;

            // create a adjacency list of meetings of peoples
            unordered_map<int, vector<int>> adj;
            unordered_set<int> alreadyAdded;
            queue<int> q;

            for (auto& [per_1, per_2] : meet) {

                adj[per_1].push_back(per_2);
                adj[per_2].push_back(per_1);

                if (knowsSecret[per_1] && alreadyAdded.find(per_1) == alreadyAdded.end()) {
                    q.push(per_1);
                    alreadyAdded.insert(per_1);
                }
                if (knowsSecret[per_2] && alreadyAdded.find(per_2) == alreadyAdded.end()) {
                    q.push(per_2);
                    alreadyAdded.insert(per_2);
                }
            }

            // Now, we know who meets with whom
            // Now, With help of BFS we spread the secret
            while(!q.empty()) {
                int per = q.front();
                q.pop();

                for (auto& nextPer : adj[per]) {
                    if (!knowsSecret[nextPer]) {
                        q.push(nextPer);
                        knowsSecret[nextPer] = 1;
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (knowsSecret[i] == 1) {
                result.push_back(i);
            }
        }
        return result;
    }

    // TC : O(M * (M+N)) -> M = Number Of Meetings, N = Number Of People, there can be at most N+M elements in the queue and a person may have M neighbours
    // SC : O(M+N)
    vector<int> solve_approach_2(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<P>> adj; // {p1, {{p2, t}, {p3, t}}}
        for (auto& meeting : meetings) {
            int p1 = meeting[0];
            int p2 = meeting[1];
            int t  = meeting[2];

            adj[p1].push_back({p2, t});
            adj[p2].push_back({p1, t});
        }

        queue<P> q;
        q.push({0, 0});
        q.push({firstPerson, 0});

        vector<int> earlySecretTime(n, INT_MAX);
        earlySecretTime[0]           = 0;
        earlySecretTime[firstPerson] = 0;
        
        while(!q.empty()) {
            auto [person, time] = q.front();
            q.pop();

            for (auto& nbr : adj[person]) {
                int nextPer = nbr.first;
                int t       = nbr.second;

                if (t >= time && earlySecretTime[nextPer] > t) {
                    earlySecretTime[nextPer] = t;
                    q.push({nextPer, t});
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (earlySecretTime[i] != INT_MAX) {
                result.push_back(i);
            }
        }
        return result;
    }

    void DFS(int person, int time, unordered_map<int, vector<P>>& adj, vector<int>& earlySecretTime) {
        for (auto& neigh : adj[person]) {
            int nextPer = neigh.first;
            int t       = neigh.second;

            if (t >= time && earlySecretTime[nextPer] > t) {
                earlySecretTime[nextPer] = t;
                DFS(nextPer, t, adj, earlySecretTime);
            }
        }
    }

    // TC : O(M * (M+N)) -> M = Number Of Meetings, N = Number Of People, there can be at most N+M elements in the queue and a person may have M neighbours
    // SC : O(M+N)
    vector<int> solve_approach_3(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<P>> adj; // {p1, {{p2, t}, {p3, t}}}
        for (auto& meeting : meetings) {
            int p1 = meeting[0];
            int p2 = meeting[1];
            int t  = meeting[2];

            adj[p1].push_back({p2, t});
            adj[p2].push_back({p1, t});
        }

        queue<P> q;
        q.push({0, 0});
        q.push({firstPerson, 0});

        vector<int> earlySecretTime(n, INT_MAX);
        earlySecretTime[0]           = 0;
        earlySecretTime[firstPerson] = 0;
        
        DFS(0, 0, adj, earlySecretTime);
        DFS(firstPerson, 0, adj, earlySecretTime);

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (earlySecretTime[i] != INT_MAX) {
                result.push_back(i);
            }
        }
        return result;
    }

    // TC : ~O((N+M) * (log(M+N) + M)) 
    // SC :  O(N+M)
    vector<int> solve_approach_4(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<P>> adj; // {p1, {{p2, t}, {p3, t}}}
        for (auto& meeting : meetings) {
            int p1 = meeting[0];
            int p2 = meeting[1];
            int t  = meeting[2];

            adj[p1].push_back({p2, t});
            adj[p2].push_back({p1, t});
        }

        priority_queue<P, vector<P>, greater<P>> pq; // {time, person}
        pq.push({0, 0});
        pq.push({0, firstPerson});

        vector<bool> visited(n, 0);

        while(!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();

            if (visited[person]) continue;

            visited[person] = 1;

            for (auto& neigh : adj[person]) {
                int nextPer = neigh.first;
                int t       = neigh.second;

                if (t >= time && !visited[nextPer]) {
                    pq.push({t, nextPer});
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // return solve_approach_1(n, meetings, firstPerson);

        // return solve_approach_2(n, meetings, firstPerson); // using bfs

        // return solve_approach_3(n, meetings, firstPerson); // using dfs

        return solve_approach_4(n, meetings, firstPerson);
    }
};