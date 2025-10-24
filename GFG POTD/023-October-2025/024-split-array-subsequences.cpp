// /https://www.geeksforgeeks.org/problems/split-array-subsequences/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        unordered_map<int, int> freq, need;
        for (int x : arr) freq[x]++;

        for (int x : arr) {
            if (freq[x] == 0) continue;

            if (need[x] > 0) {
                // x kisi subsequence me continue hoga
                need[x]--;
                need[x + 1]++;
                freq[x]--;
            } 
            else {
                // naya subsequence start krne ki koshish
                bool canForm = true;
                for (int i = 0; i < k; i++) {
                    if (freq[x + i] <= 0) {
                        canForm = false;
                        break;
                    }
                }

                if (!canForm) return false;

                // consecutive k numbers consume kro
                for (int i = 0; i < k; i++) freq[x + i]--;

                // ab next number chahiye sequence continue krne ke liye
                need[x + k]++;
            }
        }

        return true;
    }
};