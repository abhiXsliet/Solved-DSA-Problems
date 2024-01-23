// https://leetcode.com/contest/weekly-contest-381/problems/minimum-number-of-pushes-to-type-word-i/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    // TC : O(N) Where N = length of word
    // SC : O(9) ~= O(1) since map ends up storing only 2 to 9 digits
    int solve_brute(string& word) {
        unordered_map<int, int> mpp;
        
        int assign_key = 2;
        int result     = 0;

        for (char& ch : word) {
            if (assign_key > 9) {
                assign_key = 2;
            }
            
            mpp[assign_key] += 1;
            result += mpp[assign_key];
            assign_key ++;
        }
        
        return result;
    }
    
    // TC : O(N) Where N = length of word
    // SC : O(9) ~= O(1) since map ends up storing only 2 to 9 digits
    int solve_better(string& word) {
        // 2, 3 .... 9
        int arr[8] = {0};
        
        int assign_idx = 0;
        int result     = 0;

        for (char& ch : word) {
            if (assign_idx > 7) {
                assign_idx = 0;
            }
            
            arr[assign_idx] += 1;
            result += arr[assign_idx];
            assign_idx ++;
        }
        
        return result;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    int solve_optimal(string& word) {
        vector<int> freq(26, 0);

        for (char& ch : word) {
            freq[ch - 'a']++;
        }

        sort(begin(freq), end(freq), greater<int>());
        
        int result = 0;
        for (int i = 0; i < 26; i++) {
            int times_key_press = i / 8 + 1;

            result += freq[i] * times_key_press;
        }
        return result;
    }
public:
    int minimumPushes(string word) {
        // return solve_brute(word);
        
        // return solve_better(word);
        
        return solve_optimal(word);
    }
};