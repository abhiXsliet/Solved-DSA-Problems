// https://leetcode.com/problems/meeting-rooms-iii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<long long, int> P;

    // TC : O(M * log(M)) + O(M * N)    Where M = No. Of Meetings  
    // SC : O(N)                        Where N = No. Of Rooms ~= 100
    int solve_approach_1(int n, vector<vector<int>>& meetings) {
        // sorting based on the starting time of meetings
        sort(begin(meetings), end(meetings));

        // last meeting ending time 
        vector<long long> last_used_times(n, 0);
        // no. of times a meeting gets scheduled in a room
        vector<int> rooms_used_cnt(n, 0);

        for (auto& meeting : meetings) {

            int start_time = meeting[0];
            int end_time   = meeting[1];
            int duration   = end_time - start_time;

            bool found = false;
            long long early_end_room_time = LLONG_MAX;
            int early_end_room            = 0;

            for (int room = 0; room < n; room ++) {
                
                if (last_used_times[room] <= start_time) {
                    last_used_times[room] = end_time;
                    rooms_used_cnt[room] += 1;
                    found = true;
                    break;
                }

                if (last_used_times[room] < early_end_room_time) {
                    early_end_room_time = last_used_times[room];
                    early_end_room      = room;
                }
            }

            if (!found) {
                last_used_times[early_end_room] += duration;
                rooms_used_cnt[early_end_room] ++;
            }
        }

        int result_room = INT_MIN;
        int max_used    = 0;
        
        for (int room = 0; room < n; room ++) {
            if (rooms_used_cnt[room] > max_used) {
                max_used    = rooms_used_cnt[room];
                result_room = room;
            }
        }

        return result_room;
    }

    // TC : O(M * log(M)) + O(M * log(N)) Where M = No. Of Meetings
    // SC : O(N)                          Where N = No. of Rooms
    int solve_approach_2(int n, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        vector<int> rooms_used_cnt(n, 0);

        priority_queue<P, vector<P>, greater<P>> used_rooms;    // {end_time, room}

        priority_queue<int, vector<int>, greater<int>> available_rooms;

        for (int room = 0; room < n; room ++) {
            available_rooms.push(room);
        }

        for (auto& meeting : meetings) {
            
            int start_time = meeting[0];
            int end_time   = meeting[1];
            int duration   = end_time - start_time;

            while (!used_rooms.empty() && used_rooms.top().first <= start_time) {
                int room = used_rooms.top().second;
                used_rooms.pop();
                available_rooms.push(room);
            }

            if (!available_rooms.empty()) {
                int room = available_rooms.top();
                available_rooms.pop();

                used_rooms.push({end_time, room});
                rooms_used_cnt[room] ++;
            }
            else {
                int room      = used_rooms.top().second;
                long long end = used_rooms.top().first; 
                used_rooms.pop();

                used_rooms.push({end + duration, room});
                rooms_used_cnt[room] ++;
            }
        }

        int result_room = INT_MIN;
        int max_used    = 0;
        
        for (int room = 0; room < n; room ++) {
            if (rooms_used_cnt[room] > max_used) {
                max_used    = rooms_used_cnt[room];
                result_room = room;
            }
        }

        return result_room;
    }
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // return solve_approach_1(n, meetings);

        return solve_approach_2(n, meetings);
    }
};