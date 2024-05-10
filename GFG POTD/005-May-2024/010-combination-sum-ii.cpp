// https://www.geeksforgeeks.org/problems/combination-sum-ii-1664263832/1



//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

//User function Template for C++
class Solution {
private:
    // TC = O(2^min(n, p)) let p = no. of elements, at maximum, can sum upto given value target
    // SC = O(n) to store the combinations
    void solve_brute(vector<int>& arr, int tar, vector<vector<int>>& ans, 
                vector<int>& store, int idx) {
        
        if (idx == arr.size()) {
            if (tar == 0) {
                ans.push_back(store);
            }
            return;
        }

        if (arr[idx] <= tar) {
            store.push_back(arr[idx]);
            solve_brute(arr, tar - arr[idx], ans, store, idx+1);
            store.pop_back();
        }
        while (idx < arr.size()-1 && arr[idx] == arr[idx+1]) {
            idx++;
        }
        
        solve_brute(arr, tar, ans, store, idx+1);
    }

    vector<vector<int>> bruteSolve(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> store;
        sort(begin(candidates), end(candidates));
        solve_brute(candidates, target, ans, store, 0);
        return ans;
    }
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k) {
        return bruteSolve(arr, k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends