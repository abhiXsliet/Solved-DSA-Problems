// https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  private:
    // TC = O(N * N)
    // SC = O(N)
    vector<int> solve_brute(int arr[], int n) {
        sort (arr, arr+n);
        set<int> result;
        for (int i = 0; i < n; i++) {
            bool isDuplicate = 0;
            for (int j = i+1; j < n; j++) {
                if (arr[i] == arr[j])
                    isDuplicate = 1;
            }
            
            if(isDuplicate) 
                result.insert(arr[i]);
        }
        
        if (result.empty())
            result.insert(-1);
            
        vector<int> ans;
        for (auto& val : result)
            ans.push_back(val);
            
        return ans;
    }
    
    // TC = O(N)
    // SC = O(N)
    vector<int> solve_better(int arr[], int n) {
        map<int, int> mpp; 
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            mpp[arr[i]]++;
        }
        
        for(auto& i : mpp) {
            if (i.second > 1) {
                result.push_back(i.first);
            }
        }
        
        if (result.empty()) 
            result.push_back(-1);

        return result;
    }
    
    // TC = O(N)
    // SC = O(1)
    vector<int> solve_optimal_1(int arr[], int n) {
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            int idx = arr[i] % n;
            arr[idx] += n;
        }
        
        for (int i = 0; i < n; i++) {
            arr[i] /= n;
            if (arr[i] > 1) result.push_back(i);
        }
        
        if (result.empty()) result.push_back(-1);
        
        return result;
    }
    
    
  public:
    vector<int> duplicates(int arr[], int n) {
        
        // return solve_brute(arr, n);
        
        // return solve_better(arr, n);
        
        return solve_optimal_1(arr, n);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends