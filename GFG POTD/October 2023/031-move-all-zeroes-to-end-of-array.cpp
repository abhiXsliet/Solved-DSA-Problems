// https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
private:
    void solve_brute(int arr[], int n) {
        int left  = 0;
        int right = left + 1;
        
        while(right < n && left < right) {
            if (arr[left] == 0 && arr[right] != 0) {
                swap(arr[left], arr[right]);
                left++;
                right++;
            }
            else if (arr[left] == 0 && arr[right] == 0) {
                right++;
            }
            else {
                left++;
                right++;
            }
        }
    }
    
    void solve_better(int arr[], int n) {
        int left  = 0;
        int right = 0;
        
        while(right < n) {
            if (arr[right] != 0) {
                swap(arr[left], arr[right]);
                left++;
            }
            right++;
        }
    }
    
    void solve_optimal(int arr[], int n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if(arr[i] != 0)
                arr[cnt++] = arr[i];
        }
        
        while(cnt < n) {
            arr[cnt++] = 0;
        }
    }
public:
	void pushZerosToEnd(int arr[], int n) {
	   // solve_brute(arr, n);
	   
	   //solve_better(arr, n);
	   
	   return solve_optimal(arr, n);
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
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends