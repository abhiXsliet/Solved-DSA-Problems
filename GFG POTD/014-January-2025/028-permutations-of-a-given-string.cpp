// https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution { 
  private:
    // TC : O(N! * N)   Where N! is the number of unique permutations & N time for pushing each answer to the vector
    // SC : O(N)        Recursive Depth
    void solve_optimized(int idx, string &s, vector<string>& result) {
        if (idx >= s.length()) {
            result.push_back(s);
            return;
        }
        
        // Use a set to track characters that have already been swapped
        bool used[256] = {false}; // Assuming ASCII characters

        for (int i = idx; i < s.length(); i ++) {
            if (used[s[i]]) continue;
            used[s[i]] = 1;
            swap(s[i], s[idx]);
            solve_optimized(idx + 1, s, result);
            swap(s[i], s[idx]);
        }
    }
  
    // TC : O(N! * Nlog(N))  n! is the number of unique permutations.
    //                       nlogn is the cost of inserting each permutation into the set.
    // SC : O(N) Recursive Depth
    void solve(int idx, string &s, set<string> &st) {
        if (idx >= s.length()) {
            st.insert(s);
            return;
        }
        
        for (int i = idx; i < s.length(); i ++) {
            swap(s[idx], s[i]);
            solve(idx + 1, s, st);
            swap(s[idx], s[i]);
        }
    }
    
    // TC : O(N! * Nlog(N))
    // SC : O(1)
    vector<string> approach_1(string& s) {
        set<string>st;
        solve(0, s, st);
        vector<string> result(begin(st), end(st));
        return result;
    }
    
    vector<string> approach_2(string& s) {
        vector<string> result;
        sort(begin(s), end(s));
        solve_optimized(0, s, result);
        return result;
    }
  public:
    vector<string> findPermutation(string &s) {
        // return approach_1(s);
        
        return approach_2(s);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends