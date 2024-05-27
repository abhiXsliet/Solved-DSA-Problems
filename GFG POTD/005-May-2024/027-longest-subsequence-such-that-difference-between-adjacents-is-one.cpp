// https://www.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        unordered_map<int, int>mp;
        int maxi = 0, b, c;
        for(auto i : a) {
            b = i - 1, c = i + 1;
            mp[i] = max(mp[b] ,mp[c]) + 1;
            maxi  = max(maxi, mp[i]);
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}
// } Driver Code Ends