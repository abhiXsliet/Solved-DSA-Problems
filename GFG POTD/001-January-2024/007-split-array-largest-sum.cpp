// https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    int getSubarrayCnt(int arr[], int n, int num) {
        int subArray_cnt = 1;
        int subArray_sum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] + subArray_sum <= num) {
                subArray_sum += arr[i];
            }
            else {
                subArray_cnt ++;
                subArray_sum = arr[i];
            }
        }
        return subArray_cnt;
    }
    
    // TC : O(sum*N) where N = arrary length and sum = sum of all elements of array
    // SC : O(1)
    int solve_brute(int arr[], int n, int targetCnt) {
        int low  = 0;
        int high = 0; 
        for (int i = 0; i < n; i++) {
            low   = max(low, arr[i]);
            high += arr[i];
        }
        
        for (int num = low; num <= high; num++) {
            int cntSubarray = getSubarrayCnt(arr, n, num);
            if (cntSubarray == targetCnt) {
                return num;
            }
        }
        return targetCnt;
    }
    
    // TC : O(N*log(sum)) where N = arrary length and sum = sum of all elements of array
    // SC : O(1)
    int solve_optimal(int arr[], int n, int k) {
        int low  = 0;
        int high = 0; 
        for (int i = 0; i < n; i++) {
            low   = max(low, arr[i]);
            high += arr[i];
        }
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (getSubarrayCnt(arr, n, mid) <= k) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return low;
    }
  public:
    int splitArray(int arr[] ,int N, int K) {
        // return solve_brute(arr, N, K);
        
        return solve_optimal(arr, N, K);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends