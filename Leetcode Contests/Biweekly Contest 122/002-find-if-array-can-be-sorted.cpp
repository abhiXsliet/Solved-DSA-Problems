// https://leetcode.com/contest/biweekly-contest-122/problems/find-if-array-can-be-sorted/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    unordered_map<int, int> solve(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x] = countSetBits(x);
        }
        return mp;
    }

    bool checkArrayIsSorted(const vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

public:
    bool canSortArray(vector<int>& arr) {
        int n = arr.size();
        int temp = 0;
        unordered_map<int, int> countMap = solve(arr);

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < (n - i); j++) {
                if (arr[j - 1] > arr[j] && countMap[arr[j - 1]] == countMap[arr[j]]) {
                    // swap elements
                    temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        return checkArrayIsSorted(arr);
    }
};
