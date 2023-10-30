// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(log(num) base-2)
    int findBit (int num) {
        int sum = 0;
        while(num) {
            sum += (num & 1);
            num >>= 1;
        }
        return sum;
    }

    // TC = O(N*log(N))
    // SC = O(N)
    vector<int> solve_brute(vector<int>& arr, int n) {
        vector<pair<int, int>> store;

        for (int i = 0; i < n; i++) {
            int num = arr[i];

            int setBit = findBit(num);
            // int setBit = __builtin_popcount(num); // O(1)

            store.push_back({setBit, num});
        }

        // O(N*log(N))
        sort(begin(store), end(store));

        vector<int> result;
        for (int i = 0; i < store.size(); i++) {
            result.push_back(store[i].second);
        }

        return result;
    }

    // TC = O(N*log(N) * log2(num))
    // SC = O(1) -> no extra space used, SC = O(N) -> to return the answer
    vector<int> solve_better(vector<int>& arr, int n) {

        auto lambda = [&] (int& a, int& b) {
            int a_setbits = findBit(a);
            int b_setbits = findBit(b);

            if (a_setbits == b_setbits) 
                return a < b;

            return a_setbits < b_setbits;
        };

        sort(begin(arr), end(arr), lambda);

        return arr;
    }

    // TC = O(N*log(N))
    // SC = O(1)
    vector<int> solve_optimal(vector<int>& arr, int n) {

        auto lambda = [&] (int& a, int& b) {
            int a_setbits = __builtin_popcount(a); // O(1)
            int b_setbits = __builtin_popcount(b); // O(1)

            if (a_setbits == b_setbits) 
                return a < b;

            return a_setbits < b_setbits;
        };

        sort(begin(arr), end(arr), lambda);

        return arr;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        // return solve_brute(arr, arr.size());

        // return solve_better(arr, arr.size());

        return solve_optimal(arr, arr.size());
    }
};