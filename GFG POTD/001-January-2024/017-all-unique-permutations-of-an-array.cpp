// https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1



//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    // TC : O(N * N!)
    // SC : O(N * N!)
    void solve_rec(vector<int>& arr, int n, set<vector<int>>& store, int idx) {
        if (idx == n) {
            store.insert(arr);
            return;
        }
        
        for (int i = idx; i < n; i++) {
            swap(arr[i], arr[idx]);
            solve_rec(arr, n, store, idx+1);
            swap(arr[i], arr[idx]);
        }
    }
    
    vector<vector<int>> solve_approach_1(vector<int>& arr, int n) {
        set<vector<int>>store;
        
        int idx = 0;
        solve_rec(arr, n, store, idx);
        
        vector<vector<int>> result;
        for (auto& vec : store) {
            result.push_back(vec);
        }
        return result;
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    vector<vector<int>> solve_approach_2(vector<int>& arr, int n) {
        vector<vector<int>> result;
        set<vector<int>> st;
        
        result.push_back(arr);
        st.insert(arr);
        
        if (n == 1) return result;
        
        while (true) {
            int index1 = -1;
            for(int i=n-2; i>=0; i--) {
                if(arr[i] < arr[i+1]){
                    index1 = i;
                    break;
                }
            }
            
            if(index1 == -1) {
                reverse(begin(arr), end(arr));
    
            }else {
                int index2 = -1;
                for(int i = n-1; i >= 0 ; i--) {
                    if(arr[i] > arr[index1]) {
                        index2 = i;
                        break;
                    }
                }
                swap(arr[index1], arr[index2]);
                reverse(begin(arr)+index1+1, end(arr));
            }
            
            if (st.find(arr) != st.end()) break;
            
            result.push_back(arr);
            st.insert(arr);
        }
        sort(begin(result), end(result));
        return result;
    }
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // return solve_approach_1(arr, n);
        
        return solve_approach_2(arr, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends