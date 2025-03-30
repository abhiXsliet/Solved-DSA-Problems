// https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N*log(N))
    // SC : O(N)
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        vector<pair<int, int>> store;
        for (int i = 0; i < n; i ++) {
            store.push_back({start[i], finish[i]});
        }
        
        auto cmp = [&] (pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;  
        };
        sort(begin(store), end(store), cmp);
        
        int maxActivityPerfomed = 1;
        int initial = store[0].first;
        int final   = store[0].second;
        
        for (int i = 1; i < n; i ++) {
            if (store[i].first > final) {
                initial = store[i].first;
                final   = store[i].second;
                maxActivityPerfomed += 1;
            }
        }
        
        return maxActivityPerfomed;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends