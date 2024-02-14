// https://leetcode.com/problems/rearrange-array-elements-by-sign/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N) 
    // SC = O(N/2) + O(N/2) ~ O(N) -> extra space 
    // N/2 -> since it is divided into equal parts
    vector<int> solve_brute(vector<int>& arr, int n) {
        vector<int> storeNegatives;
        vector<int> storePositives;

        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                storePositives.push_back(arr[i]);
            }
            else {
                storeNegatives.push_back(arr[i]);
            }
        }

        int ptr1  = 0;
        int ptr2  = 0;
        int idx   = 0;
        bool flag = 1;

        while (ptr1 < storePositives.size() && ptr2 < storeNegatives.size()) {
            if (flag) {
                arr[idx++] = storePositives[ptr1++];
            }
            else {
                arr[idx++] = storeNegatives[ptr2++];
            }
            flag = !flag;
        }

        // incase negatives are leftover
        while (ptr2 < storeNegatives.size()) {
            arr[idx++] = storeNegatives[ptr2++];
        }
        
        return arr;
    }

    // TC = O(N)   + O(N/2) ~ O(N)
    // SC = O(N/2) + O(N/2) ~ O(N) -> extra space 
    vector<int> solve_better(vector<int>& arr, int n) {
        vector<int> storeNegatives;
        vector<int> storePositives;

        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                storePositives.push_back(arr[i]);
            }
            else {
                storeNegatives.push_back(arr[i]);
            }
        }

        for (int i = 0; i < n/2; i++) {
            arr[2 * i]     = storePositives[i];     // even cases
            arr[2 * i + 1] = storeNegatives[i];     // odd cases
        }
        
        return arr;
    }

    // TC = O(N)
    // SC = O(1) but O(N)-> to return ans
    vector<int> solve_optimal(vector<int>& arr, int n) {
    
        vector<int> result(n, 0);
        
        int positiveIdx = 0;
        int negativeIdx = 1;

        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                result[negativeIdx] = arr[i];
                negativeIdx += 2; 
            }
            else {
                result[positiveIdx] = arr[i];
                positiveIdx += 2;
            }
        }

        return result;
    }

    void rotateRight(vector<int>& arr, int outOfPlace, int idx) {
        int temp = arr[idx];
        for (int i = idx; i > outOfPlace; i--) {
            arr[i] = arr[i - 1];
        }
        arr[outOfPlace] = temp;
    }

    // TC = O(N^2) -> TLE
    // SC = O(1)
    vector<int> solve_optimal_const_space(vector<int>& arr, int n) {
        int outOfPlace = -1;
        
        for (int i = 0; i < n; i++) {
            if (outOfPlace >= 0) {
                if(((arr[i] >= 0) && (arr[outOfPlace] < 0)) || 
                    ((arr[i] < 0 ) && (arr[outOfPlace] >= 0))) {
                    
                    rotateRight(arr, outOfPlace, i);
                
                    if (i - outOfPlace >= 2) {
                        outOfPlace += 2;
                    }
                    else outOfPlace = -1;    
                } 
            }
            
            if (outOfPlace == -1) {
                // (!(i & 0x01)) -> checks the even index
                // (i & 0x01)    -> checks the odd index
                // -ve no. & at even-place or +ve no. & at odd place
                if (((arr[i]  < 0)  && (!(i & 0x01))) ||
                    ((arr[i] >= 0)  &&   (i & 0x01))) {
                    outOfPlace = i;
                }
            }
        }
        return arr;
    }
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // return solve_brute(nums, nums.size());

        // return solve_better(nums, nums.size());

        return solve_optimal(nums, nums.size());

        // return solve_optimal_const_space(nums, nums.size());
    }
};