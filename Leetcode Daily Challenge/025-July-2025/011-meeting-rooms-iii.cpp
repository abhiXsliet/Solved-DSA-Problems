// https://leetcode.com/problems/meeting-rooms-iii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    using V  = vector<ll>;

    // TC : O(M*log(M) + M*log(N))
    // SC : O(M + N)
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(begin(meetings), end(meetings));

        priority_queue<int, vector<int>, greater<int>> freeRooms;
        // track the meeting which is currently happening : {meeEndingTime, roomNo.}
        priority_queue<V, vector<V>, greater<V>> ongoing;
        // track the number of times each room used
        vector<int> roomUsedTimesCnt(n, 0);

        for (int i = 0; i < n; i ++) freeRooms.push(i);

        for (auto &meet : meetings) {
            int currMeetStart = meet[0], currMeetEnd = meet[1];

            // Freeing up rooms whose meeting has ended
            while (!ongoing.empty() && ongoing.top()[0] <= currMeetStart) {
                freeRooms.push(ongoing.top()[1]);
                ongoing.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                roomUsedTimesCnt[room] ++;
                ongoing.push({currMeetEnd, room});

            } else {
                auto it = ongoing.top();
                ongoing.pop();

                ll earlyEndMeet = it[0];   // when room become free
                ll earlyEndRoom = it[1];   // No. of room which become free

                ll duration    = currMeetEnd - currMeetStart;
                ll nextMeetEnd = earlyEndMeet + duration;

                ongoing.push({nextMeetEnd, earlyEndRoom});
                roomUsedTimesCnt[earlyEndRoom] ++;
            }
        }

        int minRoomMaxUsed = 0, maxUsed = 0;
        for (int i = 0; i < n; i ++) {
            if (roomUsedTimesCnt[i] > maxUsed) {
                maxUsed = roomUsedTimesCnt[i];
                minRoomMaxUsed = i;
            }
        }
        return minRoomMaxUsed;
    }
};