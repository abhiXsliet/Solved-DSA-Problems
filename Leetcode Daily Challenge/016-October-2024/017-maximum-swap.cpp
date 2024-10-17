// https://leetcode.com/problems/maximum-swap/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2) Where N = length of string 's' (N ~= 9)
    // SC : O(N)   Where N = length of string 's'
    int brute(int num) {
        string s = to_string(num);
        int len = s.length();
        int idx = 0;
       
        while (idx < len) {
            int maxIdx = idx;
            int maxEle = s[idx];

            for (int i = len - 1; i > idx; i --) {  // finding maxEle from the right to left
                if (s[i] > maxEle) {
                    maxEle = s[i];
                    maxIdx = i;
                }
            }
          
            if (maxIdx != idx) {
                swap(s[idx], s[maxIdx]);
                break;
            }
            idx ++;
        }

        return stoi(s);
    }

    // TC : O(N) Where N = length of string 's' (N ~= 9)
    // SC : O(N) Where N = length of string 's'
    int better(int num) {
        string s = to_string(num);
        int len = s.length();
        
        // stores the rightMax element index
        vector<int> rightMaxIndices(len, len - 1);
        for (int i = len - 2; i >= 0; i --) {  // finding maxEle from the right to left
            int rightIdx = rightMaxIndices[i + 1];
            rightMaxIndices[i] = (s[i] > s[rightIdx]) ? i : rightIdx;
        }

        int idx = 0;
        while (idx < len) {
            int rightMxIdx = rightMaxIndices[idx];
            if (s[idx] < s[rightMxIdx]) {
                swap(s[idx], s[rightMxIdx]);
                break;
            }
            idx ++;
        }

        return stoi(s);
    }

    // TC : O(N)
    // SC : O(1)
    int optimal(int num) {
        string s = to_string(num);
        int n    = s.length();

        // stores the occurance of every element at index
        vector<int> store(10, -1);
        for (int i = 0; i < n; i ++) {
            store[s[i] - '0'] = i;
        }

        for (int i = 0; i < n; i ++) {
            for (int digit = 9; digit > s[i] - '0'; digit --) {
                if (store[digit] > i) {
                    swap(s[store[digit]], s[i]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
public:
    int maximumSwap(int num) {
        // return brute(num);       // Iterating right to find the maxEle to swap

        // return better(num);      // Storing max right element in a array

        return optimal(num);     // creating a vector of const size of 10 (since digits 0..9)   
    }
};