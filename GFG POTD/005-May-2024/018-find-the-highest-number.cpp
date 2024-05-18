// https://www.geeksforgeeks.org/problems/find-the-highest-number2259/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // TC : O(log(n))
    // SC : O(1)
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n - 1;
        int ans = INT_MIN;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (mid + 1 < n && a[mid] <= a[mid + 1]) {
                ans = a[mid + 1];
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends