// https://www.geeksforgeeks.org/problems/juggler-sequence3930/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    // TC : O(N)
    // SC : O(1) and O(N) -> to return the answer
    vector<long long> approach_1(long long n) {
        vector<long long> ans;
        ans.push_back(n);
        while (n > 1) {
            if (n % 2) n = (n * sqrt(n));
            else n = sqrt(n);
            ans.push_back(n);
        }
        return ans;
    }
    
    // TC : O(N)
    // SC : O(1) and O(N) -> to return the answer
    vector<long long> approach_1_modified(long long n) {
        vector<long long> ans;
        ans.push_back(n);
        while (n > 1) {
            n = n & 1 ? pow(n, 1.5) : pow(n, 0.5);
            ans.push_back(n);
        }
        return ans;
    }
  public:
    vector<long long> jugglerSequence(long long n) {
        // return approach_1(n);
        
        return approach_1_modified(n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends