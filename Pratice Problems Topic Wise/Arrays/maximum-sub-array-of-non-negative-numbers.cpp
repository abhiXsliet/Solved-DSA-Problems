// https://practice.geeksforgeeks.org/problems/maximum-sub-array5443/1



//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
private:
    vector<int> kadanes_algo_variation(int a[], int n) {
        int maxSum = INT_MIN;
        long long sum  = 0;
        
        int ansLeft = -1;
        int ansRight= -1;
        int left    =  0;   // moving
        int right   =  0;   // moving
        
        for (int i = 0; i < n; i++) {
            if (a[i] >= 0) {
                sum += a[i];
                
                if( (sum > maxSum) ||
                    ((sum == maxSum) && (ansRight - ansLeft < right - left)) ) {
                    maxSum   = sum;
                    ansLeft  = left;
                    ansRight = right;
                }
            }
            else {
                sum  = 0;
                left = i + 1;
            }
            right++;
        }
        
        if (maxSum < 0) {
            return {-1};
        }
        
        vector<int> result;
        for (int i = ansLeft; i <= ansRight; i++) {
            result.push_back(a[i]);
        }
        
        return result;
    }
public:
	vector<int> findSubarray(int a[], int n) {
	    return kadanes_algo_variation(a, n);
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
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends