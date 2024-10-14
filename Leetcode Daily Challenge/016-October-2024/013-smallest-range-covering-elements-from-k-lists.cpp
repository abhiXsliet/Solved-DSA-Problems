// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * K) Where N = No. of elements in nums
    // SC : O(K)     Where K = No. of lists present in nums
    vector<int> approach_1(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> store(k, 0);    // it will store the indices from each list of nums
        vector<int> result{-1000000, 1000000};

        while (true) {
            int minEle    = INT_MAX;
            int maxEle    = INT_MIN;
            int minEleIdx = -1;

            for (int i = 0; i < k; i ++) {  // traverse on each list and get the minEle from going to all 1st elements
                int ele = nums[i][store[i]];
                maxEle  = max(maxEle, ele);
                if (ele < minEle) {
                    minEle    = ele;
                    minEleIdx = i;
                }
            }

            if (maxEle - minEle < result[1] - result[0]) {
                result[1] = maxEle;
                result[0] = minEle;
            }

            // squeezing the range length by increasing idx of minEle from the list
            int newIdx = store[minEleIdx] + 1;
            if (newIdx >= nums[minEleIdx].size())
                break;
            
            // update indices of store 
            store[minEleIdx] = newIdx;
        }

        return result;
    }

    // TC : O(N * log(K)) Traversing on 'N' elements and size of heap stays the O(K)
    // SC : O(K)
    vector<int> approach_2(vector<vector<int>>& nums) {
        int k = nums.size();

        // it will store : {minEle, minIdx, listIdx}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> result {-1000000, 1000000};

        int maxEle = INT_MIN;
        for (int i = 0; i < k; i ++) {
            pq.push({nums[i][0], 0, i});
            maxEle = max(maxEle, nums[i][0]);
        }

        while (!pq.empty()) {
            vector<int> vec = pq.top();
            pq.pop();

            int minEle  = vec[0];
            int minIdx  = vec[1];
            int listIdx = vec[2];

            if (maxEle - minEle < result[1] - result[0]) {
                result[1] = maxEle;
                result[0] = minEle;
            }

            // try to shorten/squeez the range
            int newIdx = minIdx + 1;
            if (newIdx >= nums[listIdx].size())
                break;

            pq.push({nums[listIdx][newIdx], newIdx, listIdx});
            maxEle = max(maxEle, nums[listIdx][newIdx]);
        }

        return result;
    }
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // return approach_1(nums); // keep 'k' pointers to track min & max, update range accordingly
        
        return approach_2(nums);    // Used Heap to track the minVal & its index with the listIndex
    }
};