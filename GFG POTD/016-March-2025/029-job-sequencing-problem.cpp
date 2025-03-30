// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1




//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N * D) Where D = max-deadline (ie., ~= N)
    // SC : O(D)
    vector<int> approach_1(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> store;
        for (int i = 0; i < n; i ++) {
            store.push_back({profit[i], deadline[i]});
        }
        
        sort(rbegin(store), rend(store));

        int maxDeadline = *max_element(begin(deadline), end(deadline));
        vector<int> schedule(maxDeadline + 1, -1);   // +1 for 1-indexed based
        
        int maxJobScheduled = 0, profitEarned = 0;
        for (int i = 0; i < n; i ++) {
            int prof = store[i].first;
            int dead = store[i].second;
            for (int j = dead; j >= 1; j --) {
                if (schedule[j] == -1) {
                    schedule[j] = i;
                    maxJobScheduled += 1;
                    profitEarned += prof;
                    break;
                }
            }
        }
        return {maxJobScheduled, profitEarned};
    }
    
    // TC : O(N*log(N)) 
    // SC : O(N)
    vector<int> approach_2(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> store;
        
        int max_deadline = 0;
        for (int i = 0; i < n; i++) {
            store.push_back({profit[i], deadline[i]});
            max_deadline = max(max_deadline, deadline[i]);
        }

        sort(rbegin(store), rend(store)); // Sort jobs in decreasing order of profit

        vector<int> parent(max_deadline + 1);    // tracks the latest available slot
        for (int i = 0; i <= max_deadline; i ++) {
            parent[i] = i;
        }
        
        function<int(int)> findParent = [&](int x) {
            if (parent[x] == x)
                return x;
                
            return parent[x] = findParent(parent[x]);   // path compression
        };
        
        int maxJobScheduled = 0, profitEarned = 0;
        
        for (int i = 0; i < n; i ++) {
            int prof = store[i].first;
            int dead = store[i].second;
            
            // Find the latest available slot <= deadline
            int availSlot = findParent(dead);
            
            if (availSlot > 0) {
                maxJobScheduled += 1;
                profitEarned += prof;
                // Mark the slot as occupied by linking it to the previous slot
                parent[availSlot] = findParent(availSlot - 1);  
            }
        }
        
        return {maxJobScheduled, profitEarned};
    }
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // return approach_1(deadline, profit);    // TLE : Brute
        return approach_2(deadline, profit); 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends