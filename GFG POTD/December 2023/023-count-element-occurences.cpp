// https://www.geeksforgeeks.org/problems/count-element-occurences/1



//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    // TC = O(N * N)
    // SC = O(N)
    int solve_brute(int arr[], int n, int k) {
        set<int> st;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (arr[i] == arr[j]) cnt++;
            }
            
            if (cnt > n/k) 
                st.insert(arr[i]);
        }
        return st.size();
    }
    
    // TC : O(N)
    // SC : O(N)
    int solve_optimal(int arr[], int n, int k) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
            mpp[arr[i]]++;
          
        int cnt = 0; 
        for (auto& i: mpp) {
            if (i.second > n / k) cnt++;
        }
        return cnt;
    }
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        // return solve_brute(arr, n, k);
        
        return solve_optimal(arr, n, k);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends