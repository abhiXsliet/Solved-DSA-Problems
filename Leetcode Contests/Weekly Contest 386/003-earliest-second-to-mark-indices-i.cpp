// https://leetcode.com/contest/weekly-contest-386/problems/earliest-second-to-mark-indices-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, int> P;
    
    // TC : O(N*log(N)) Where N = Size of nums array
    // SC : O(N)
    bool isPossibleToMarkAllIndices(vector<int>& nums, vector<int>& changeIndices, int n, int m, int seconds) {
        // Track the last appearance of each indices into the changeIndices array
        vector<int> lastOcc_idx(n + 1, -1);
        for (int i = 0; i <= seconds; i++) {
            lastOcc_idx[changeIndices[i]] = i + 1;
        }
        
        // check if all the indices of nums is present in changeIndices
        for (int i = 1; i <= n; i++) {
            if (lastOcc_idx[i] == -1) {
                return 0;
            }
        }
        
        // 1. We can use an array to store the last_appearance of indices of changeIndices array
        // 2. We can use a map to do the same where Key is last_appearance and value will be indices
        // 3. We can do the same using minheap
        priority_queue<P, vector<P>, greater<P>> pq; // {last_appearance, idx}
        
        // O(Nlog(N))
        for (int i = 1; i <= n; i++) {
            pq.push({lastOcc_idx[i], i}); // O(log(N))
        }
        
        // Time taken to mark every indices of nums
        int minSeconds = 0;
        while (!pq.empty()) {   // O(N)
            int last_appearance = pq.top().first;
            int index           = pq.top().second;
            pq.pop();
            
            // required time for decrement to 0 and +1 to marking it
            int time_required  = nums[index - 1] + 1 + minSeconds; 
            if (time_required > last_appearance) 
                return 0;
            
            minSeconds = time_required;
        }
        return true;
    }
    
    // TC : O(M * Nlog(N)) Where M = size of changeIndices array
    // SC : O(N)           Where N = size of nums array
    int solve_approach_1(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();
        
        for (int seconds = 0; seconds < m; seconds++) {
            if (isPossibleToMarkAllIndices(nums, changeIndices, n, m, seconds)) 
                return seconds + 1;
        }
        return -1;
    }
    
    // TC : O(log(M) * Nlog(N)) Where M = size of changeIndices array
    // SC : O(N)           Where N = size of nums array
    // BINARY SEARCH ON ANSWER : lenght of changeIndices which indicates the time
    int solve_approach_2(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();
        
        int result = -1;
        // minimum time required to mark all indices
        int low    = 0;
        // maximum time required to mark all indices
        int high   = m - 1;
        while (low <= high) {   // log(M)
            int mid = low + (high - low) / 2;
            
            if (isPossibleToMarkAllIndices(nums, changeIndices, n, m, mid)) {
                result = mid + 1; // 1-based indexing
                high   = mid - 1;
            }
            else low = mid + 1;
        }
        return result;
    }
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        // return solve_approach_1(nums, changeIndices);
        
        return solve_approach_2(nums, changeIndices);
    }
};