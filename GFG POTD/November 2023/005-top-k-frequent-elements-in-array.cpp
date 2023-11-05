// https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    // TC = O(n + m*log(m) + k)
    // SC = O(N + N) ~ O(N)
    vector<int> solve_brute(vector<int>& nums, int k, int n) {
        vector<int> result;
        unordered_map<int, int> mpp;
        
        for (int i = 0; i < n; i++)
            mpp[nums[i]]++;
            
        vector<pair<int, int>> sortedPairs(begin(mpp), end(mpp));
            
        auto cmp = [&](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) 
                return a.first > b.first;
            return a.second > b.second;  
        };
        
        // O(m * log(m)) where m = no. of unique elements
        sort(begin(sortedPairs), end(sortedPairs), cmp);
        
        int idx = 0;
        while(k--) {
            result.push_back(sortedPairs[idx++].first);
        }
        
        return result;
    }
    
    typedef pair<int, int> P;
    // TC = O(n + m*log(k) + k*log(k)) ~ O(m*log(k)) where m = no. of unique elements
    // SC = O(N + K) ~ O(N)
    vector<int> solve_optimal(vector<int>& nums, int k, int n) {
        vector<int> result;
        unordered_map<int, int> mpp;
        
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        
        priority_queue<P, vector<P>, greater<P>> minHeap;
        
        // O(m * log(k)) -> m is the no. of unique elements
        for (auto& it : mpp) {
            minHeap.push({it.second, it.first}); // O(log(k))
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // O(k * log(k)) -> poping 'k' elements from minHeap
        while(!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop(); // O(log(k))
        }
        
        reverse(begin(result), end(result));
        return result;
    }
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // return solve_brute(nums, k, nums.size());
        
        return solve_optimal(nums, k, nums.size());
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends