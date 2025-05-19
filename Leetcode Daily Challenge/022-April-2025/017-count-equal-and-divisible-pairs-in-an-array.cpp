// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    int brute(vector<int> &nums, int k) {
        int n = nums.size();
        int pairs = 0;
        for (int i = 0; i < n - 1; i ++) {
            for (int j = i + 1; j < n; j ++) {
                if (((i * j) % k == 0) && (nums[i] == nums[j]))
                    pairs += 1;
            }
        }
        return pairs;
    }

    unordered_set<int> getFactors(int k) {
        unordered_set<int> st;
        for (int i = 1; i*i <= k; i ++) {
            if (k % i == 0) {
                st.insert(i);
                st.insert(k/i);
            }
        }
        st.insert(k);
        return st;
    }

    // TC : O(N * (log(K) + sqrt(K)))
    // SC : O(N)
    int optimal(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> numIndices;
        for (int i = 0; i < n; i ++) {
            numIndices[nums[i]].push_back(i);
        }

        unordered_set<int> kFactors = getFactors(k);
        int result = 0;

        for (auto &[num, indices] : numIndices) {

            unordered_map<int, int> factorsFreq;

            for (const int &i : indices) {
                int GCD = gcd(i, k);
                int j   = k / GCD;

                result += factorsFreq[j];

                // insert common factors of (i, k) into freq map
                for (const int &f : kFactors) {
                    if (i % f == 0) {
                        factorsFreq[f] ++;
                    }
                }
            }
        }
        
        return result;
    }
public:
    int countPairs(vector<int>& nums, int k) {
        // return brute(nums, k);
        return optimal(nums, k);
    }
};