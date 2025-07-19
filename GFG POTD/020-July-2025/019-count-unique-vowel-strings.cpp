// https://www.geeksforgeeks.org/problems/count-unique-vowel-strings/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool isVowel(char &ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    long long getFactorial(int n) {
        long long ans = 1;
        for (int i = n; i >= 1; i --) {
            ans *= i;
        }
        return ans;
    }
  public:
    // TC : O(N)
    // SC : O(1) at max mpp size could be 5 only
    int vowelCount(string& s) {
        unordered_map<char, int> mpp;
        for (char &ch : s) {
            if (isVowel(ch)) {
                mpp[ch] ++;
            }
        }
        
        long long ans = (mpp.size() > 0) ? getFactorial(mpp.size()) : 0;
        for (auto &it : mpp) {
            ans *= it.second;
        }
        return ans;
    }
};