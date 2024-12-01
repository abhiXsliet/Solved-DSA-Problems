// https://leetcode.com/problems/check-if-n-and-its-double-exist/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    bool brute(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i != j && arr[i] == 2*arr[j]) {
                    return true;
                }
            }
        }
        return false;
    }

    // TC : O(N)
    // SC : O(N)
    bool better_1(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mpp;    // {arr[i], index}

        int cntZero = 0;
        for (int i = 0; i < n; i ++) {
            mpp[arr[i]] = i;
            if (arr[i] == 0) cntZero ++;
        }

        if (cntZero > 1) return true;
        
        for (int i = 0; i < n; i ++) {
            if (arr[i] != 0 && arr[i] % 2 == 0) { 
                int number = arr[i] / 2;
                if (mpp.count(number) && i != mpp[number])
                    return true;
            }
        }
        return false;
    }

    // TC : O(N)
    // SC : O(N)
    bool better_2(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;    // {arr[i], index}
        for (int i = 0; i < n; i ++) {
            if (st.count(arr[i] * 2)) 
                return true;
            else if (arr[i] % 2 == 0 && st.count(arr[i] / 2)) 
                return true;
            st.insert(arr[i]);
        }
        return false;
    }

    // TC : O(log(N))
    // SC : O(1)
    int binarySearch(vector<int>& arr, int tar) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == tar)
                return mid;
            else if (arr[mid] > tar)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return -1;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    bool optimal(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        for (int i = 0; i < n; i ++) {
            int j = binarySearch(arr, 2*arr[i]);
            if (j != -1 && j != i) return true;
        }
        return false;
    }
public:
    bool checkIfExist(vector<int>& arr) {
        // return brute(arr);
        // return better_1(arr)
        // return better_2(arr);
        return optimal(arr);
    }
};