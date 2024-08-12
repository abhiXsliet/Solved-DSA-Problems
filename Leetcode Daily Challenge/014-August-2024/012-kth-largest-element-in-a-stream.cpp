// https://leetcode.com/problems/kth-largest-element-in-a-stream/



#include <bits/stdc++.h>
using namespace std;

// TC : O(M*log(K))
// SC : O(K) K = size of minHeap
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

    // TC : O(log(K))
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;

        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) 
                pq.pop();
        }
    }
    
    // TC : O(M * log(K)) where M = No. of times 'add' fn gets called
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) 
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */