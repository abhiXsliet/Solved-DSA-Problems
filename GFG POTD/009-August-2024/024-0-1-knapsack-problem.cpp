// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int t[1001][1001];
    
    // TC : O(W * N)
    // SC : O(W * N)
    int solve(int w, vector<int>& wt, vector<int>& val, int i) {
        if (i >= wt.size()) return 0;
        if (t[w][i] != -1) return t[w][i];
        
        int incl = 0, excl = 0;
        if (wt[i] <= w) {
            incl = val[i] + solve(w - wt[i], wt, val, i + 1);
        } 
        excl = 0 + solve(w, wt, val, i + 1);
        
        return t[w][i] = max(incl, excl);
    }
    
    // TC : O(W * N)
    // SC : O(W * N)
    int tab(int W, vector<int>& wt, vector<int>& val) {
        memset(t, 0, sizeof(t));
        
        for (int i = wt.size() - 1; i >= 0; i --) {
            for (int w = 0; w <= W; w ++) {
                int incl = 0, excl = 0;
                if (wt[i] <= w) {
                    incl = val[i] + t[w - wt[i]][i + 1];
                } 
                excl = 0 + t[w][i + 1];
                
                t[w][i] = max(incl, excl);
            }
        }
        
        return t[W][0];
    }
    
    // TC : O(W * N)
    // SC : O(W)
    int so(int W, vector<int>& wt, vector<int>& val) {
        vector<int> curr(W + 1, 0);
        vector<int> prev(W + 1, 0);
        
        for (int i = wt.size() - 1; i >= 0; i --) {
            for (int w = 0; w <= W; w ++) {
                int incl = 0, excl = 0;
                if (wt[i] <= w) {
                    incl = val[i] + prev[w - wt[i]];
                } 
                excl = 0 + prev[w];
                
                curr[w] = max(incl, excl);
            }
            prev = curr;
        }
        
        return prev[W];
    }
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // memset(t, -1, sizeof(t));
        // return solve(W, wt, val, 0);
        
        // return tab(W, wt, val);
        
        return so(W, wt, val);
    }
};


//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends