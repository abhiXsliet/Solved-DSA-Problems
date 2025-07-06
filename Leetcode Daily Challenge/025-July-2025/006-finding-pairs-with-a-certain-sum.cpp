// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/




#include <bits/stdc++.h>
using namespace std;

class FindSumPairs {
public:
    vector<int> a, b;
    unordered_map<int, int> mpp;

    // TC : O(N) for initialization
    // SC : O(N) for storing frequency of nums2 elements
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        for (int &num : nums2) {
            mpp[num] ++;
        }
    }
    
    // TC : O(1)
    void add(int index, int val) {
        int original = b[index];
        b[index] += val;
        mpp[original] --;
        mpp[original + val] ++;
    }
    
    // TC : O(N) for each count call
    int count(int tot) {
        int ans = 0;
        for (int &val : a) {
            int tar = (tot - val);
            if (mpp.count(tar)) {
                ans += mpp[tar];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */