// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * log(N))
    // SC : O(N)
    int approach_1(vector<vector<int>> &events) {
        int n = events.size();

        sort(begin(events), end(events));

        priority_queue<int, vector<int>, greater<>> pq;

        int day = 1;
        int i = 0;
        int attendedEvents = 0;

        while (!pq.empty() || i < n) {
            // Add all events starting at day
            while (i < n && day == events[i][0]) {
                pq.push(events[i][1]);
                i ++;
            }

            // Attend the events that ends at the earliest
            if (!pq.empty()) {
                pq.pop();
                attendedEvents += 1;
            }

            day += 1;

            // Skip the events whose endTime < day
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }

        return attendedEvents;
    }

    // TC : O(N * log(N))
    // SC : O(N)
    int approach_2(vector<vector<int>> &events) {
        int n = events.size();

        sort(begin(events), end(events));

        priority_queue<int, vector<int>, greater<>> pq;

        int day = events[0][0]; // start at the closest starting day
        int i = 0;
        int attendedEvents = 0;

        while (!pq.empty() || i < n) {
            
            if (pq.empty()) {   // consider starting of next event is ahead of curr_day 
                day = events[i][0];
            }

            // Add all events starting at day
            while (i < n && day == events[i][0]) {
                pq.push(events[i][1]);
                i ++;
            }

            // Attend the events that ends at the earliest
            if (!pq.empty()) {
                pq.pop();
                attendedEvents += 1;
            }

            day += 1;

            // Skip the events whose endTime < day
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }

        return attendedEvents;
    }
public:
    int maxEvents(vector<vector<int>>& events) {
        // return approach_1(events);
        return approach_2(events);   // little optimization on day increment
    }
};