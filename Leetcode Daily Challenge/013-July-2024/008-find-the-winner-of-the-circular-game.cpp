// https://leetcode.com/problems/find-the-winner-of-the-circular-game/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(N)
    int solve(int n, int k) {
        vector<int> arr(n, 0);
        for (int i = 1; i <= n; i ++) {
            arr[i - 1] = i;
        }

        int i = 0;
        while (arr.size() > 1) { // O(N)
            i = (i + k - 1) % arr.size();    // index to be erased
            arr.erase(begin(arr) + i);       // erase element at index i : O(N)
        }
        return arr[0];
    }

    // TC : O(N^2)
    // SC : O(N)
    int solveQ(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; i ++) 
            q.push(i);

        while(q.size() > 1) {
            for (int i = 1; i < k; i ++) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }

    // TC : O(N)
    // SC : O(N) -> Recursive depth
    int func(vector<int>& arr, int k, int idx) {
        int n = arr.size();
        if (n == 1) return arr[0];

        int removeIdx = (idx + k - 1) % n;
        arr.erase(begin(arr) + removeIdx);

        return func(arr, k, removeIdx);
    }

    // TC : O(N)
    // SC : O(N) + O(N) = O(N)
    int solve_josephus(int n, int k) {
        vector<int> arr(n, 0);
        for (int i = 1; i <= n; i++) {
            arr[i - 1] = i;
        }

        return func(arr, k, 0);
    }

    // TC : O(N)
    // SC : O(N) -> Recursive Depth
    int solve_rec(int n, int k) {
        if (n == 1) return 0;
        
        int idx = solve_rec(n - 1, k);
        idx = (idx + k) % n;    // to get the original index of element prior deletion

        return idx;
    }
public:
    int findTheWinner(int n, int k) {
        // return solve(n, k);      // SIMULATION

        // return solveQ(n, k);     // SIMULATION (Queue)

        // return solve_josephus(n, k);

        return solve_rec(n, k) + 1;  // Doing +1 to get the name of the person
    }
};