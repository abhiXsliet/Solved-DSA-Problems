// https://www.geeksforgeeks.org/problems/pascal-triangle0652/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int ncr(int n, int r) {
        int ans = 1;
        if (n == r) return ans;
        if ((n - r) < r) r = n - r;
        for (int i = n; i > (n - r); i --) {
            ans *= (i);
            ans /= (n - i + 1);
        }
        return ans;
    }
    
    // TC : O(N^2)
    // SC : O(N)
    vector<int> approach_1(int n) {
        vector<int> prev(1, 1);
        for (int i = 1; i < n; i ++) {
            vector<int> curr(i + 1, 1);
            for (int j = 1; j < i; j ++) {
                curr[j] = prev[j - 1] + prev[j];
            }
            prev = curr;
        }
        return prev;
    }

    // TC : O(N)
    // SC : O(N)
    vector<int> approach_2(int n) {
        vector<int> prev(n, 1);
        int row = n - 1;
        for (int i = 1; i < n - 1; i ++) {
            prev[i] = ncr(row, i);
        }
        return prev;
    }
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // return approach_1(n);
        return approach_2(n);    // Math(ncr) : slightly better
    }
};

//{ Driver Code Starts.
void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends