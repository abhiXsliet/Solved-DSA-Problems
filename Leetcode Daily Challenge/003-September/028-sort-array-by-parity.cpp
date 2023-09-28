// https://leetcode.com/problems/sort-array-by-parity/


#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    // TC = O(N), SC = O(1)
    vector<int> solve_brute_1(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int idx = 0;
        
        for (int i = 0; i < n; i++) 
            if (nums[i] % 2 == 0) 
                result[idx++] = nums[i];
        
        for (int i = 0; i < n; i++) 
            if (nums[i] % 2 == 1) 
                result[idx++] = nums[i];

        return result;
    }

    // TC = O(N), SC = O(1)
    vector<int> solve_brute_2(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int lastIdx = n - 1, startIdx = 0;

        for (int i = 0; i < n; i++) 
            if (nums[i] % 2) 
                result[lastIdx--]   = nums[i];

            else result[startIdx++] = nums[i];

        return result;
    }

    // TC = O(N), SC = O(1)
    vector<int> solve_better(vector<int>& nums) {
        int n = nums.size();

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return nums;
    }

    static bool cmp(int &a, int &b) {
        return a%2 < b%2;
    }
    // TC = O(N * log(N)), SC = O(1)
    vector<int> solve_optimal(vector<int>& nums) {
        sort(begin(nums), end(nums), cmp);

        return nums;
    }
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // return solve_brute_1(nums);

        // return solve_brute_2(nums);

        // return solve_better(nums);

        return solve_optimal(nums);
    }
};