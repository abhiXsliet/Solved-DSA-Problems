// https://www.geeksforgeeks.org/problems/find-transition-point-1587115620/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:    
    int transitionPoint(int arr[], int n) {
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends