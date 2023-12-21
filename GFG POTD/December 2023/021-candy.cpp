// https://www.geeksforgeeks.org/problems/candy/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    int solve_approach_1(int N, vector<int>& ratings) {
        vector<int> candys(N, 1);
        
        // left to right filling candys array
        for (int i = 1; i < N; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candys[i] = max(candys[i], candys[i - 1] + 1);
            }
        }
        
        // right to left filling candys array
        for (int i = N - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candys[i] = max(candys[i], candys[i + 1] + 1);
            }
        }
        
        return accumulate(begin(candys), end(candys), 0);
    }
    
    // TC : O(N)
    // SC : O(1)
    int solve_approach_2(int N, vector<int>& ratings) {
        int candyCnt = N;
        
        int i = 1;
        while (i < N) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }
            
            // Increasing Slope -> Increase peak value
            int peak = 0;
            while (ratings[i] > ratings[i - 1]) {
                peak ++;
                candyCnt += peak;
                i++;
                
                if (i == N) // one mountain completed here 
                    return candyCnt;
            }
            
            // Decreasing Slope -> Increase dip value
            int dip = 0;
            while (i < N && ratings[i] < ratings[i - 1]) {
                dip ++;
                candyCnt += dip;
                i++;
            }
            
            candyCnt -= min(peak, dip);
            
            if (i == N) 
                return candyCnt;
        }
        return candyCnt;
    }
  public:
    int minCandy(int N, vector<int>& ratings) {
        // return solve_approach_1(N, ratings);
        
        return solve_approach_2(N, ratings);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends