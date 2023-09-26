// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    // TC = O(N^4) -> TLE
    // SC = O(N)
    vector<vector<int> > solve_brute(vector<int> &arr, int target_sum) {
        vector<vector<int>> result;
        set <vector<int>> st;
        
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    for (int l = k + 1; l < n; l++) {
                        int sum = arr[i] + arr[j] + arr[k] + arr[l];
                        
                        if (sum == target_sum) {
                            vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                            if (st.find(temp) == st.end()) {
                                st.insert(temp);
                                result.push_back(temp);
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
    
    // TC = O(N^4) -> TLE
    // SC = O(1)
    vector<vector<int> > solve_better(vector<int> &arr, int target_sum) {
        vector<vector<int>> result;
        
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) continue; // to skip duplicates
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && arr[j] == arr[j - 1]) continue; // to skip duplicates
                for (int k = j + 1; k < n - 1; k++) {
                    if (k > j + 1 && arr[k] == arr[k - 1]) continue; // to skip duplicates
                    for (int l = k + 1; l < n; l++) {
                        if (l > k + 1 && arr[l] == arr[l - 1]) continue; // to skip duplicates
                        
                        int sum = arr[i] + arr[j] + arr[k] + arr[l];
                        
                        if (sum == target_sum) {
                            vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                            result.push_back(temp);
                        }
                    }
                }
            }
        }
        return result;
    }
    
    // TC = O(N^3)
    // SC = O(N)
    vector<vector<int>> solve_optimal(vector<int>& arr, int target_sum) {
        vector<vector<int>> result;
        int n = arr.size();
        sort(begin(arr), end(arr));
        
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) continue;
            
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && arr[j] == arr[j - 1]) continue;
                
                int left  = j + 1;
                int right = n - 1; 
                
                while (left < right) {
                    int sum = arr[i] + arr[j] + arr[left] + arr[right];
                    
                    if (sum == target_sum) {
                        result.push_back({arr[i], arr[j], arr[left], arr[right]});
                        
                        while (left < right && arr[left]  == arr[left  + 1]) left++;
                        while (left < right && arr[right] == arr[right - 1]) right--;
                        
                        left++, right--;
                    }
                    else if (sum < target_sum) left ++;
                    else right--;
                }
            }
        }
        return result;
    }
    
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // return solve_brute(arr, k);
        
        // return solve_better(arr, k);
        
        return solve_optimal(arr, k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends