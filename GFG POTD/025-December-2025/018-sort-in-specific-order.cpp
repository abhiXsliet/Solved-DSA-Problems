// https://www.geeksforgeeks.org/problems/sort-in-specific-order2422/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortIt(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n - 1;

        // Phase 1: partition odds and evens
        while (i <= j) {
            if (arr[i] % 2 == 1) {
                i++;
            } else if (arr[j] % 2 == 0) {
                j--;
            } else {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        // i is the first index of even numbers
        // Phase 2: sort separately
        sort(arr.begin(), arr.begin() + i, greater<int>()); // odds desc
        sort(arr.begin() + i, arr.end());                   // evens asc
    }
};