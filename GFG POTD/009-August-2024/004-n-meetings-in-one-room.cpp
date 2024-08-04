// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int, int>> store;
        for (int i = 0; i < n; i ++) {
            store.push_back({end[i], start[i]});
        }
        sort(store.begin(), store.end());
        int meetCnt = 1;
        int meetEnd = store[0].first;
        int meetSt  = store[0].second;
        for (int i = 1; i < n; i ++) {
            int en = store[i].first;
            int st = store[i].second;
            if (st > meetEnd) {
                meetCnt ++;
                meetSt  = st;
                meetEnd = en;
            }
        }
        return meetCnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends