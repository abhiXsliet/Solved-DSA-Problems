// https://leetcode.com/contest/weekly-contest-389/problems/minimum-deletions-to-make-string-k-special/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N) Where N = word length
    // SC : O(26) ~= O(1)
    int solve_approach_1(string word, int k) {
        int n = word.length();
        unordered_map<char, int>mpp;
        for (char& ch : word) {
            mpp[ch] ++;
        }

        vector<int> freq;
        for (auto& it : mpp) {
            freq.push_back(it.second);
        }

        int minDeletion = INT_MAX;
        for (int i = 0; i < freq.size(); i++) {
            int minEle = freq[i];
            int range  = minEle + k;
            int cntDel = 0;
            for (int j = 0; j < freq.size(); j++) {
                if (i != j && freq[j] < minEle || freq[j] > range){
                    if (freq[j] < minEle) 
                        cntDel += freq[j];
                    else
                        cntDel += freq[j] - range;
                }
            }
            minDeletion = min(minDeletion, cntDel);
        }
        return minDeletion;
    }

    // TC : O(N) Where N = word length
    // SC : O(1)
    int solve_approach_2(string word, int k) {
        int n = word.length();
        vector<int> freq(26, 0);
        for (char& ch : word) {
            freq[ch - 'a'] ++;
        }

        sort(begin(freq), end(freq));

        int minDeletion = n;
        int cumm_Delete = 0;

        for (int i = 0; i < 26; i++) {
            int cntDel = cumm_Delete;
            for (int j = 25; j > i; j--) {
                if (freq[j] - freq[i] <= k) {
                    break;  
                }

                cntDel += freq[j] - freq[i] - k;
            }
            minDeletion = min(minDeletion, cntDel);
            cumm_Delete += freq[i];
        }
        return minDeletion;
    }

    // TC : O(2^N) where N = 26 at worst
    // SC : O(N) -> Recursive Depth
    int solve(vector<int>& arr, int k, int start, int end) {
        if (start >= end) return 0;
        if (arr[end] - arr[start] <= k) return 0;
        int option_1 = arr[start] + solve(arr, k, start + 1, end);
        int option_2 = arr[end] - arr[start] - k + solve(arr, k, start, end - 1);
        return min(option_1, option_2);
    }

    int solve_approach_3(string word, int k) {
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }
        sort(freq.begin(), freq.end());
        vector<int> arr;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) arr.push_back(freq[i]);
        }
        return solve(arr, k, 0, arr.size() - 1);
    }
public:
    int minimumDeletions(string word, int k) {
        // return solve_approach_1(word, k);

        // return solve_approach_2(word, k);   // Pruning : optimize your previous code little by eliminating redundant steps
    
        return solve_approach_3(word, k);      // Recursive
    }
};
