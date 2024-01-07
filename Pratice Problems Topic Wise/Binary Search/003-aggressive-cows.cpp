// https://www.geeksforgeeks.org/problems/aggressive-cows/0



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    bool isPossiblePlace(vector<int>& stalls, int n, int min_dist, int totalCows) {
        int lastCowIdx = stalls[0];
        int cntCows    = 1;
        for (int i = 1; i < n; i++) {
            if (stalls[i] - lastCowIdx >= min_dist) {
                cntCows ++;
                lastCowIdx = stalls[i];
            }
            if (cntCows >= totalCows) return true;
        }
        return false;
    }
    
    // TC : O(maxi * N) where maxi = diff b/w max & min element of array
    // SC : O(1)
    int solve_brute(int n, int k, vector<int>& stalls) {
        sort(begin(stalls), end(stalls));
        
        int mini = stalls[0];
        int maxi = stalls[n - 1];
        
        for (int dist = 1; dist < maxi-mini-1; dist++) {
            if (isPossiblePlace(stalls, n, dist, k) == true) 
                continue;
            else {
                return dist - 1;
            }
        }
        return -1;
    }
    
    // TC : O(N * log(maxi)) where maxi = diff. b/w min & max elements of array
    // SC : O(1)
    int solve_optimal(int n, int k, vector<int>& stalls) {
        sort(begin(stalls), end(stalls));
        
        int low  = 1;
        int high = stalls[n - 1] - stalls[0];
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossiblePlace(stalls, n, mid, k) == true) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        // minimam dist. is maximum and high is pointing to that maxm
        return high;
    }
public:
    int solve(int n, int k, vector<int> &stalls) {
        // return solve_brute(n, k, stalls);


        return solve_optimal(n, k, stalls);
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends