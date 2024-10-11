// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, int> P;

    // TC : O(N*N) For each arrival, we're traversing over entire array
    // SC : O(N)
    int brute(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> chairs(n, -1);
        int targetArrival = times[targetFriend][0];

        sort(begin(times), end(times));

        for (vector<int> &time : times) {
            int arrival = time[0];
            int depart  = time[1];

            for (int i = 0; i < n; i ++) {
                if (arrival >= chairs[i]) {
                    chairs[i] = depart;   // set the departure time on chair

                    if (arrival == targetArrival)
                        return i;   // return chair with min. value

                    break;
                } 
            }
        }
        return 0;
    }

    // TC : O(N*log(N)) Where M = times Size
    // SC : O(N)
    int optimal(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        int targetArrival = times[targetFriend][0];

        sort(begin(times), end(times));
        int chairNo = 0;

        priority_queue<P, vector<P>, greater<P>> occupency;    // {departure, chairNo};
        priority_queue<int, vector<int>, greater<int>> freeChairs;     // holds free chair no.s

        for (int i = 0; i < n; i ++) {
            int arrival = times[i][0];
            int depart  = times[i][1];

            while (!occupency.empty() && occupency.top().first <= arrival) {
                freeChairs.push(occupency.top().second);    // Push the free chair no. into free Chairs heap
                occupency.pop();
            }

            if (freeChairs.empty()) {
                occupency.push({depart, chairNo});
                if (arrival == targetArrival)
                    return chairNo;
                chairNo ++;
            } else {

                int leastFreeChairNo = freeChairs.top();
                freeChairs.pop();

                occupency.push({depart, leastFreeChairNo});
                if (arrival == targetArrival) {
                    return leastFreeChairNo;
                }
            }
        }

        return -1;
    }
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // return brute(times, targetFriend);

        return optimal(times, targetFriend);
    }
};