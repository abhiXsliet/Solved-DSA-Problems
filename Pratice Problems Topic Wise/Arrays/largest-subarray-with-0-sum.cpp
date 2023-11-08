// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    private:
    // TC = O(N^3)
    // SC = O(1)
    int solve_brute(vector<int>& arr, int n) {
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                    
                    if (sum == 0) {
                        maxi = max(maxi, k - i + 1);
                    }
                }
            }
        }
        return maxi;
    }
   
    // TC = O(N^2)
    // SC = O(1) 
    int solve_better(vector<int>& arr, int n) {
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == 0) {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi;
    }
    
    
    int solve_optimal(vector<int>& arr, int n) {
       int maxi = 0;
       unordered_map<int, int> mpp;
       
       int sum = 0;
       for (int i = 0; i < n; i++) {
           sum += arr[i];
           
           if (sum == 0) {
               maxi =  i + 1;
           }
           else {
               if (mpp.find(sum) != mpp.end()) {
                   maxi = max(maxi, i - mpp[sum]);
               }
               else {
                   mpp[sum] = i;
               }
           }
       }
       return maxi;
    }
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // return solve_brute(A, n);
        
        // return solve_better(A, n);
        
        return solve_optimal(A, n);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends