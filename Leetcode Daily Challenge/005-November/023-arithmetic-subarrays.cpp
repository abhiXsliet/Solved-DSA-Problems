// https://leetcode.com/problems/arithmetic-subarrays/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkIsAP_2(vector<int>& arr) {
        int n = arr.size();

        int minEle = INT_MAX;
        int maxEle = INT_MIN;

        unordered_set<int> st;

        for (int& num : arr) {
            minEle = min(minEle, num);
            maxEle = max(maxEle, num);
            st.insert(num);
        }

        if ((maxEle - minEle) % (n - 1) != 0)
            return false;

        int common_diff = (maxEle - minEle) / (n - 1);

        int currEle = minEle + common_diff;

        while (currEle < maxEle) {
            if (st.find(currEle) == st.end())
                return false;
            
            // next term of A.P
            // a, a+d, a+2d, ...
            currEle += common_diff;
        }
        
        return true;
    }

    bool checkIsAP_1(vector<int>& arr) {
        int n = arr.size();
        
        sort(begin(arr), end(arr));

        int common_diff = arr[1] - arr[0];

        for (int i = 2; i < n; i++) {
            if (arr[i] - arr[i - 1] != common_diff) 
                return false;
        }
        return true;
    }

    // TC = O(M * N*log(N))
    // SC = O(N)
    vector<bool> solve_approach_1(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();

        vector<bool> result;

        for (int i = 0; i < m; i++) {
            int start = l[i];
            int end   = r[i];

            // create a array and fill elements from start to end
            vector<int> arr(begin(nums) + start, begin(nums) + end + 1);

            bool isAP = checkIsAP_1(arr);

            result.push_back(isAP);
        }
        return result;
    }

    // TC = O(M * N)
    // SC = O(N)
    vector<bool> solve_approach_2(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();

        vector<bool> result;

        for (int i = 0; i < m; i++) {
            int start = l[i];
            int end   = r[i];

            // create a array and fill elements from start to end
            vector<int> arr(begin(nums) + start, begin(nums) + end + 1);

            bool isAP = checkIsAP_2(arr);

            result.push_back(isAP);
        }
        return result;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        // return solve_approach_1(nums, l, r);

        return solve_approach_2(nums, l, r);
    }
};