// https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1



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
    // TC : O(N)
    // SC : O(N)
    int findPair(int n, int x, vector<int> &arr) {
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            if (st.find(arr[i] - x) != st.end() || 
                st.find(arr[i] + x) != st.end()) 
                return 1;
            else st.insert(arr[i]);
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends