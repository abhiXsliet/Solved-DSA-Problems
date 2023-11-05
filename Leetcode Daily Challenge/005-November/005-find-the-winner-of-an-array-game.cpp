// https://leetcode.com/problems/find-the-winner-of-an-array-game/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N * N)
    // SC = O(1)
    int solve_brute(vector<int>& arr, int n, int k) {  
        int winner = 0;
        int win_cnt = 0;

        while (win_cnt != k) {
            
            if (arr[0] > arr[1]) {
                if (winner == arr[0]) {
                    win_cnt++;
                }
                else {
                    winner  = arr[0];
                    win_cnt = 1;
                }
                int startEle = arr[1];
                for (int j = 1; j < n - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                arr[n - 1] = startEle;
            } 
            else {
                if (winner == arr[1]) {
                    win_cnt++;
                }
                else {
                    winner  = arr[1];
                    win_cnt = 1;
                }
                int startEle = arr[0];
                for (int j = 0; j < n - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                arr[n - 1] = startEle;
            }
        }

        return winner;
    }

    // TC = O(N*N)
    // SC = O(1)
    int solve_better(vector<int>& arr, int n, int k) {

        int maxElement = *max_element(begin(arr), end(arr));
        
        if (k >= n)
            return maxElement;

        int winner  = 0;
        int win_cnt = 0;
        
        while(win_cnt != k) {
            // Check if the max_element becomes the winner
            // then it will always be the winner
            if (winner == maxElement)
                return maxElement;

            // Determine the winner and loser index
            int winner_idx = arr[0] > arr[1] ? 0 : 1;
            int loser_idx  = 1 - winner_idx;

            // Update the winner and win_cnt
            if (winner == arr[winner_idx]) {
                win_cnt++;
            }
            else {
                winner  = arr[winner_idx];
                win_cnt = 1;
            }

            // Move the loser to the end of the arrray
            int loser_element = arr[loser_idx];
            for (int i = loser_idx; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            arr[n - 1] = loser_element;
        }
        return winner;
    }


    // TC = O(N)
    // SC = O(1)
    int solve_optimal(vector<int>& arr, int n, int k) {
        
        int maxEle = *max_element(begin(arr), end(arr));

        if (k >= n) // array will get rotated at least once and maxEle will come at 1-index
            return maxEle;

        int winner  = arr[0];
        int win_cnt = 0;

        for (int i = 1; i < n; i++) {
            
            if (arr[i] > winner) {
                winner = arr[i];
                win_cnt = 1;
            }
            else {
                win_cnt++;
            }

            if (win_cnt == k || winner == maxEle)
                return winner;
        }

        return -1; // code will not reach here since there is at least one winner
    }
public:
    int getWinner(vector<int>& arr, int k) {
        // return solve_brute(arr, arr.size(), k);

        // return solve_better(arr, arr.size(), k);

        return solve_optimal(arr, arr.size(), k);
    }
};