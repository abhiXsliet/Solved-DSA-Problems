// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:  
    typedef pair<int, int> P;
    int M = 1e9 + 7;

    // TC : O(N^2 * log(N))
    // SC : O(N^2)
    int brute(vector<int>& nums, int n, int left, int right) {
        vector<int> subArrSum;
        for (int i = 0; i < n; i ++) {
            int sum = 0;
            for (int j = i; j < n; j ++) {
                sum += nums[j];
                subArrSum.push_back(sum);
            }
        }

        sort(begin(subArrSum), end(subArrSum)); 

        int result = 0;
        for (int i = left - 1; i <= right - 1; i ++) {
            result = (result + subArrSum[i]) % M;
        }
        return result;
    }

    // TC : (N^2 * log(N)) Where log(N) = push/pop opr of pq & N^2 = Total SubArray
    // SC : O(N) PQ size always maintained as N : since for every popped element we are pushing one
    int optimal_1(vector<int>& nums, int n, int left, int right) {
        priority_queue<P, vector<P>, greater<P>> pq;
        for (int i = 0; i < n; i ++) {
            pq.push({nums[i], i});
        }

        int count  = 0;
        int result = 0;
        
        while (count <= right) {
            count ++;

            int ele = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            if (count >= left && count <= right) {
                result = (result + ele) % M;
            }
            
            if (idx + 1 == n) continue;
            
            int sum = ele + nums[idx + 1];
            
            pq.push({sum, idx + 1});
        }
        
        return result;
    }
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // return brute(nums, n, left, right);

        return optimal_1(nums, n, left, right);

        // return optimal_2(nums, n, left, right);     // PENDING
    }
};