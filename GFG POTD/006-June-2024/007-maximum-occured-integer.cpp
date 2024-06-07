// https://www.geeksforgeeks.org/problems/maximum-occured-integer4602/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N * R) Where R = Max-Range of left[i] to right[i]
    // SC : O(maxx-range)
    int solve_brute(int n, int l[], int r[]) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i ++) {
            int first = l[i];
            int last  = r[i];
            
            for (int j = first; j <= last; j ++) {
                mpp[j] ++;
            }
        }
        
        int maxFreq = 0;
        int maxOcc  = INT_MAX;
        
        for (auto& it : mpp) {
            if (maxFreq < it.second) {
                maxFreq = it.second;
                maxOcc  = it.first;
            }
            if (maxFreq == it.second) {
                maxOcc = min(maxOcc, it.first);
            }
        }
        
        return maxOcc;
    }
    
    // TC : O(N + MAXX) Where Maxx is the maxm value of r[]
    // SC : O(MAXX)
    int optimal(int n, int l[], int r[], int maxx) {
        vector<int> freq(maxx + 2, 0);
        
        for (int i = 0; i < n; i ++) {
            freq[l[i]] ++;
            freq[r[i] + 1] --;
        }
        
        for (int i = 1; i <= maxx; i ++) {
            freq[i] += freq[i - 1];
        }
        
        int maxOcc  = 0;
        int maxFreq = 0;
        
        for (int i = 0; i <= maxx; i ++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxOcc  = i;
            }
            if (freq[i] == maxFreq) {
                maxOcc = min(maxOcc, i);
            }
        }
        
        return maxOcc;
    }
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {
        // return solve_brute(n, l, r);
        
        return optimal(n, l, r, maxx);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    // taking testcases
    cin >> t;

    while (t--) {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++) {

            cin >> r[i];
            if (r[i] > maxx) {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends