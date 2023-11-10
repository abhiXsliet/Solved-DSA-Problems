// https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    // TC = O(N * N * N) -> TLE
    // SC = O(1)
    int solve_brute(int arr[], int n, int k) {
        int no_of_subarrays = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                }
                if (sum == k) 
                    no_of_subarrays++;
            }
        }
        return no_of_subarrays;
    }
    
    // TC = O(N * N) -> TLE
    // SC = O(1)
    int solve_better(int arr[], int n, int k) {
        int no_of_subarrays = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == k) 
                    no_of_subarrays++;
            }
        }
        return no_of_subarrays;
    }
    
    // TC => O(N)
    // SC => O(N)
    // Optimal code if the array has both +ve and -ve elements
    int solve_optimal(int arr[], int n, int k){
        int no_of_subarrays = 0;
        
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            no_of_subarrays += mpp[sum - k];
            mpp[sum]++;
        }
        return no_of_subarrays;
    }
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // return solve_brute(Arr, N, k);
        
        // return solve_better(Arr, N, k);
        
        return solve_optimal(Arr, N, k);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends