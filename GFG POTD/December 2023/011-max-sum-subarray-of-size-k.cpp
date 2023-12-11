// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1



//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{ 
private:
    // TC = O(N*K) -> TLE
    // SC = O(1)
    long solve_brute(int k, vector<int>& arr, int n) {
        long ans = 0;
        // O(n - k + 1)
        for (int i = 0; i <= n - k; i++) {
            long sum = 0;
            // O(k)
            for (int j = i; j < i + k; j++) {
                sum += arr[j];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
    
    // TC = O(N)
    // SC = O(1)
    // SLIDING WINDOW
    long solve_optimal_1(int k, vector<int>& arr, int n) {
        long sum = arr[0];
        long ans = sum;
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (j - i + 1 > k) {
                sum -= arr[i];
                i++;
            }
            sum += arr[j];
            ans = max(ans, sum);
        }
        return ans;
    }
    
    // TC = O(N)
    // SC = O(1)
    // MODIFIED KADANES ALGO
    long solve_optimal_2(int k, vector<int>& arr, int n) {
        long curr_sum = 0;
        for (int i = 0; i < k; i++) {
            curr_sum += arr[i];
        }
        
        long max_sum = curr_sum;
        for (int i = k; i < n; i++) {
            curr_sum += arr[i] - arr[i - k];
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // return solve_brute(K, Arr, N);
        
        // return solve_optimal_1(K, Arr, N);
        
        return solve_optimal_2(K, Arr, N);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends