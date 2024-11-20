// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int brute(string& s, int k, int l, int r, vector<int>& freq, int result, int minutes) {
        // Base case: if the frequency condition is met, return current minutes
        if (freq[0] >= k && freq[1] >= k && freq[2] >= k)
            return min(result, minutes);

        // Base case: if pointers cross, stop recursion
        if (l > r)
            return result;

        // Recursive case: remove from the left
        freq[s[l] - 'a']++;
        int op1 = brute(s, k, l + 1, r, freq, result, minutes + 1);
        freq[s[l] - 'a']--; // Backtrack

        // Recursive case: remove from the right
        freq[s[r] - 'a']++;
        int op2 = brute(s, k, l, r - 1, freq, result, minutes + 1);
        freq[s[r] - 'a']--; // Backtrack

        // Return the minimum of the two options
        return min(op1, op2);
    }

    // TC : O(2^N)
    // SC : O(1)
    int solve_brute(string s, int k) {
        vector<int> freq(3, 0); // To count 'a', 'b', 'c'
        int result = INT_MAX;   // Initialize with the maximum possible result
        int ans = brute(s, k, 0, s.length() - 1, freq, result, 0);
        return ans == INT_MAX ? -1 : ans;
    }
    
    // TC : O(N)
    // SC : O(1)
    int optimal(string s, int k) {
        int n = s.length();
        vector<int> freq(3, 0);

        int l = 0;
        while (l < n && (freq[0] < k || freq[1] < k || freq[2] < k)) {
            freq[s[l] - 'a'] ++;
            l ++;
        }

        if (freq[0] < k || freq[1] < k || freq[2] < k)
            return -1;
        
        int minDeletion = l, r = n - 1;
        l -= 1;
        while (l >= 0) {
            freq[s[l] - 'a'] --;
            l --;

            while (l <= r && (freq[0] < k || freq[1] < k || freq[2] < k)) {
                freq[s[r] - 'a'] ++;
                r --;
            }

            minDeletion = min(minDeletion, n - (r - l));
        }
        return minDeletion;
    }
public:
    int takeCharacters(string s, int k) {
        // return solve_brute(s, k); // Recursion

        return optimal(s, k);   // SLIDING WINDOW
    }
};