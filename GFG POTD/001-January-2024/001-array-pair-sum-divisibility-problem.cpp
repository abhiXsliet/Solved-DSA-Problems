// https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    // TC : O(N*N)
    // SC : O(N)
    bool solve_brute(vector<int>& nums, int k, int n) {
        if (n % 2 != 0) 
            return false;
            
        vector<bool> used(n, 0);
        
        for (int i = 0; i < n-1; i++) {
            if (used[i] == 1) continue;
            bool foundPair = 0;
            
            for (int j = i + 1; j < n; j++) {
                if (used[j] == 1) continue;
                
                if (((nums[i] + nums[j]) % k) == 0) {
                    used[i] = 1;
                    used[j] = 1;
                    
                    foundPair = 1;
                    break;
                }
            }
            if (foundPair == false)
                return 0;
        }
        return 1;
    }
    
    // TC : O(N*N)
    // SC : O(1)
    bool solve_better(vector<int>& nums, int k, int n) {
        if (n % 2 != 0) 
            return false;
        
        for (int i = 0; i < n-1; i++) {
            if (nums[i] == -1) continue;
            bool foundPair = 0;
            
            for (int j = i + 1; j < n; j++) {
                if (nums[j] == -1) continue;
                
                if (((nums[i] + nums[j]) % k) == 0) {
                    nums[i] = -1;
                    nums[j] = -1;
                    
                    foundPair = 1;
                    break;
                }
            }
            if (foundPair == false)
                return 0;
        }
        return 1;
    }
    
    // TC : O(N)
    // SC : O(N)
    bool solve_optimal(vector<int>& nums, int k, int n) {
        if (n % 2 != 0) 
            return false;
            
        unordered_set<int> st;
        
        for (int i = 0; i < n; i++) {
            int r1 = nums[i] % k;
            int r2 = k - r1;
            
            if (st.find(r2) != st.end()) {
                st.erase(r2);
            }
            else if (r1 == 0 && st.find(0) != st.end()) {
                st.erase(0);
            }
            else {
                st.insert(r1);
            }
        }
        
        return st.size() == 0;
    }
  public:
    bool canPair(vector<int> nums, int k) {
        // return solve_brute(nums, k, nums.size());
        
        // return solve_better(nums, k, nums.size());
        
        return solve_optimal(nums, k, nums.size());
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends