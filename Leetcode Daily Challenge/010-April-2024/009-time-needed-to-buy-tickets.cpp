// https://leetcode.com/problems/time-needed-to-buy-tickets/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(K*N) Where K = Position of Kth Ticket
    // SC : O(N)   Where N = No. Of Tickets
    int approach_1(vector<int>& tickets, int k) {
        int time = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < tickets.size(); i++) {
            q.push({tickets[i], i});
        }
        while(true) {
            int tickIdx = q.front().second;
            int tickVal = q.front().first;
            q.pop();

            tickVal -= 1;
            time    += 1;
            
            if (tickIdx == k && tickVal == 0) 
                return time;

            if (tickVal != 0)
                q.push({tickVal, tickIdx});
        }
        return 0;
    }

        // TC : O(K*N) Where K = Position of Kth Ticket
    // SC : O(N)   Where N = No. Of Tickets
    int approach_1_better(vector<int>& tickets, int k) {
        int time = 0;
        queue<int> q;
        for (int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }
        while(true) {
            int tickIdx = q.front(); q.pop();

            tickets[tickIdx] -= 1;
            time             += 1;
            
            if (tickIdx == k && tickets[tickIdx] == 0) 
                return time;

            if (tickets[tickIdx] != 0)
                q.push(tickIdx);
        }
        return 0;
    }

    // TC : O(K*N) Where K = Position of Kth Ticket
    // SC : O(1)   Where N = No. Of Tickets
    int approach_2(vector<int>& tickets, int k) {
        int n   = tickets.size();
        int time = 0;
        int idx = 0;
        while(true) {
            if (tickets[idx] > 0) {
                tickets[idx] -= 1;
                time += 1;
            }
            if (k == idx && tickets[k] == 0)
                return time;
            idx ++;
            idx %= n;
        }
        return 0;
    }

    // TC : O(N) Where N = No. Of Tickets
    // SC : O(1)   
    int approach_3(vector<int>& tickets, int k) {
        int n   = tickets.size();
        int time = 0;
        for (int i = 0; i < n; i++) {
            if (i <= k)
                time += min(tickets[k], tickets[i]);
            else 
                time += min(tickets[k]-1, tickets[i]);
        }
        return time;
    }
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // return approach_1(tickets, k);

        // return approach_1_better(tickets, k);

        // return approach_2(tickets, k);

        return approach_3(tickets, k);
    }
};