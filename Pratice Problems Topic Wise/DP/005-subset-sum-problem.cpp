// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1




//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h> 
using namespace std; 
// } Driver Code Ends
//User function template for C++

class Solution{   
private:
    int t[101][10001];
    
    // TC : O(N*Sum)
    // SC : O(N*Sum)
    bool mem(vector<int>& arr, int n, int sum) {
        if (n >= 0 && sum == 0)
            return 1;
        if (n == 0 && sum >= 0) 
            return 0;
        
        if (t[n][sum] != -1) return t[n][sum];
            
        if (arr[n - 1] <= sum) {
            return t[n][sum] = ( mem(arr, n - 1, sum - arr[n - 1]) || 
                                 mem(arr, n - 1, sum) );
        } else {
            return t[n][sum] = mem(arr, n - 1, sum);
        }
    }
    
    // TC : O(N*Sum)
    // SC : O(N*Sum)
    bool tab(vector<int>& arr, int n, int sum) {
        vector<vector<bool>> t(n+1, vector<bool>(sum+1, 0));
        
        for (int i = 0; i <= n; i ++) {
            t[i][0] = 1;    // sum of 0 can be made with array of different sizes
        }
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= sum; j ++) {
                if (arr[i-1] <= j) {
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        
        return t[n][sum];
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // memset(t, -1, sizeof(t));
        // return mem(arr, arr.size(), sum);
        
        return tab(arr, arr.size(), sum);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
// } Driver Code Ends