// https://leetcode.com/problems/product-of-array-except-self/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    vector<int> solve_better(vector<int>& nums) {
        int n         = nums.size();
        int product   = 1;    // product without zero
        int zeroCount = 0;

        for (int& num : nums) {
            if(num != 0) 
                product *= num;
            else
                zeroCount++;
        }

        vector<int> result(n, 0);
        if (zeroCount > 1) {
            return result;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) 
                result[i] = product;
            else if (zeroCount == 0)
                result[i] = product / nums[i];
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N)
    vector<int> solve_optimal_1(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProduct(n, 0);
        vector<int> rightProduct(n, 0);

        leftProduct[0]      = 1;
        rightProduct[n - 1] = 1;

        for (int i = 1; i < n; i++) {
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            rightProduct[i] = rightProduct[i + 1] * nums[i + 1];
        }

        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            result[i] = leftProduct[i] * rightProduct[i];
        }
        return result;
    }

    // TC : O(N)
    // SC : O(1)    // optimized space using result
    vector<int> solve_optimal_2(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        result[0] = 1;

        for (int i = 1; i < n; i++) {
            result[i]   = result[i - 1] * nums[i - 1];
        }

        int rightProduct = 1;

        for (int i = n - 1; i >= 0; i--) {
            result[i]     = result[i] * rightProduct;
            rightProduct *= nums[i];
        }
        return result;
    }
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // return solve_better(nums);

        // return solve_optimal_1(nums);

        return solve_optimal_2(nums);
    }
};
