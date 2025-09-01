// https://www.geeksforgeeks.org/problems/sum-of-mode/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N * log(K))
    // SC : O(K)
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        
        unordered_map<int, int> freq;
        map<int, set<int>> freqToVal;
        int i = 0, j = 0, sumModes = 0;
        
        while (j < n) {
            int num = arr[j];
            int oldFreq = freq[num];
            if (oldFreq > 0) {
                freqToVal[oldFreq].erase(num);
                if (freqToVal[oldFreq].empty()) freqToVal.erase(oldFreq);
            }
            
            freq[num] ++;
            freqToVal[freq[num]].insert(arr[j]);
            
            if (j - i + 1 == k) {
                int maxFreq = freqToVal.rbegin() -> first;
                sumModes   += *freqToVal[maxFreq].begin();

                oldFreq = freq[arr[i]];
                freqToVal[oldFreq].erase(arr[i]);
                if (freqToVal[oldFreq].empty()) freqToVal.erase(oldFreq);
                
                freq[arr[i]] --;
                if (!freq[arr[i]]) freq.erase(arr[i]);
                else freqToVal[freq[arr[i]]].insert(arr[i]);
                
                i ++;
            }
            
            j ++;
        }
        
        return sumModes;
    }
};