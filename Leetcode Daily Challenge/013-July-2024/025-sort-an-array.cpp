// https://leetcode.com/problems/sort-an-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N + K)
    // SC : O(N)
    vector<int> approach_1(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (auto& num : nums) {
            freq[num] ++;
        }

        int minEle = *min_element(begin(nums), end(nums));
        int maxEle = *max_element(begin(nums), end(nums));

        int i = 0;
        for (int num = minEle; num <= maxEle; num ++) {
            while (freq[num]) {
                nums[i] = num;
                i ++;
                freq[num] --;
            }
        }

        return nums;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        return approach_1(nums);    // counting sort
                                    // Pending Using HeapSort, BST(inorder)
    }
};