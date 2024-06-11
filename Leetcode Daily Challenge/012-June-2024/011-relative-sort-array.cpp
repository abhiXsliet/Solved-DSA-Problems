// https://leetcode.com/problems/relative-sort-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N)) Where N = Size of arr1
    // SC : O(N)
    vector<int> approach_1(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mpp;
        for (int& num : arr1) mpp[num] ++;  // log(N)
        
        arr1.clear();
        
        for (int& num : arr2) {
            while(mpp[num] > 0) {
                arr1.push_back(num);
                mpp[num] --;
            }
        }

        for (auto& it : mpp) {
            while (it.second > 0) {
                arr1.push_back(it.first);
                it.second --;
            }
        }
        return arr1;
    }

    // TC : O(N*log(N)) Where N = Size of arr1
    // SC : O(M)        Where M = Size of arr2
    vector<int> approach_2(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < arr2.size(); i ++) 
            mpp[arr2[i]] = i;
        
        for (int& num : arr1) {
            if (!mpp.count(num))
                mpp[num] = INT_MAX;
        }

        auto cmp = [&](int num1, int num2) {
            if (mpp[num1] == mpp[num2]) {
                return num1 < num2;
            }
            return mpp[num1] < mpp[num2];
        };

        sort(begin(arr1), end(arr1), cmp);

        return arr1;
    }
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // return approach_1(arr1, arr2);

        return approach_2(arr1, arr2);
    }
};