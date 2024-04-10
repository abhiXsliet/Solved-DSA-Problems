// https://www.geeksforgeeks.org/problems/alone-in-couple5507/1



//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h> 
using namespace std; 
// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    // TC : O(N*log(N))
    // SC : O(1)
    int solve_1(int arr[], int n) {
        sort(arr, arr + n);
        int ans = -1;
        for (int i = 0; i < n; i+=2) {
            if (arr[i] != arr[i + 1]) {
                ans = arr[i];
                break;
            }
        }
        return ans;
    }
    
    // TC : O(N)
    // SC : O(1)
    int solve_2(int arr[], int n) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans ^= arr[i];
        }
        return ans;
    }
    public:
    int findSingle(int n, int arr[]){
        // return solve_1(arr, n);
        
        return solve_2(arr, n);
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.findSingle(N, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends