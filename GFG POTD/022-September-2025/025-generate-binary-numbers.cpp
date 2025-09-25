// https://www.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    string getBinary(int num) {
        string binary;
        while (num) {
            binary = to_string(num % 2) + binary;
            num /= 2;
        }
        return binary;
    }
    
    // TC : O(N * log(N))
    // SC : O(N)
    vector<string> approach_1(int n) {
        vector<string> result;
        for (int i = 1; i <= n; i ++) {
            result.push_back(getBinary(i));
        }
        return result;
    }
  public:
    vector<string> generateBinary(int n) {
        return approach_1(n);
        // return approach_2(n);    // pending??
    }
};