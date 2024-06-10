// https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    // TC : O(N*log(N))
    void approach_1(int n, char nuts[], char bolts[]) {
        sort(nuts, n + nuts);
        sort(bolts, n + bolts);
    }
    
    // TC : O(N)
    // SC : O(N)
    void approach_2(int n, char nuts[], char bolts[]) {
        unordered_map<char, int> mpp;
        for (int i = 0; i < n; i ++) 
            mpp[nuts[i]] ++;
            
        vector<char> vec {'!', '#', '$', '%', '&', '*', '?', '@', '^'};
        
        int j = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (mpp[vec[i]]) {
                nuts[j] = bolts[j] = vec[i];
                j ++;
            }
        }
    }
  public:
    void matchPairs(int n, char nuts[], char bolts[]) {
        // approach_1(n, nuts, bolts);
        
        approach_2(n, nuts, bolts);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends