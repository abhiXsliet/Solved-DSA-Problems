// https://www.geeksforgeeks.org/problems/non-overlapping-intervals/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int n = intervals.size();
        int count = 0;  
        int last_end = INT_MIN;  
        for (const auto& interval : intervals) {
            if (interval[0] >= last_end) {
                last_end = interval[1];  
            } else {
                count++;  
                last_end = min(last_end, interval[1]); 
            }
        }

        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends