// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-116/problems


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    void rotate(int n, vector<int>&arr) {
        int first = arr[0];
        for(int i = 0; i < n-1; i++) {
            arr[i] = arr[i+1];
        }
        arr[n-1] = first;
    }
    public:
    int min_operations(int n, vector<int>&arr, vector<int>&brr) {
        
        int cnt = 0;
        while (!arr.empty() || !brr.empty()) {
            
            if (arr[0] == brr[0]) {
                cnt++;
                arr.erase(arr.begin());
                brr.erase(brr.begin());
            } else {
                cnt++;
                rotate(arr.size(), arr);
            }
        }
	    return cnt;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        
        int n;
        cin >> n;
        vector<int> arr(n), brr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> brr[i];
        }
        Solution obj;
        cout << obj.min_operations(n, arr, brr) << endl;
    }
}

// } Driver Code Ends