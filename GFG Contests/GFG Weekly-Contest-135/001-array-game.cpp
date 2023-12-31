// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-135/problems


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int min_operations(int n, vector<int>&arr, vector<int>&brr) {
	    int cnt = 0;
	    while (n > 0) {
	        if (arr[0] == brr[0]) {
	            arr.erase(begin(arr));
	            brr.erase(begin(brr));
	        }
	        else {
	            int val = arr[0];
	            for (int i = 0; i < n; i++) {
	                arr[i] = arr[i + 1];
	            }
	            arr[n - 1] = val;
	        }
	        cnt++;
	        n = arr.size();
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