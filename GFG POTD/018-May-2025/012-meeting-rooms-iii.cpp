// https://www.geeksforgeeks.org/problems/meeting-rooms-iii/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    typedef pair<long long, int> P;

    // TC : O(M * log(M)) + O(M * log(N)) Where M = No. Of Meetings
    // SC : O(N)                          Where N = No. of Rooms
    int mostBooked(int n, vector<vector<int>> &meetings) {
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
};

//{ Driver Code Starts.
int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends