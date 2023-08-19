// https://leetcode.com/problems/next-greater-element-iii/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getFirstDecreasingEle(string& str, int idx1, int len) {
        // Step 1: Find the index of first decreasing element from the back
        for (int i = len - 1; i > 0; i--) {
            if (str[i] > str[i - 1]) {
                idx1 = i - 1;
                break;
            }
        }
        return idx1;
    }

    int getNextGreaterEle(string& str, int idx1, int idx2, int len) {
        // Step 2: Find the index of next greater element than the element at idx1
        if (idx1 != -1) {
            for (int i = len - 1; i > idx1; i--) {
                if (str[i] > str[idx1]) {
                    idx2 = i;
                    break;
                }
            }
        }
        return idx2;
    }

    int solve(string& str, int idx1, int idx2, int n) {
        if(idx1 != -1 && idx2 != -1) {
            swap(str[idx1], str[idx2]);
            sort(str.begin()+idx1+1, str.end());

            // try {
            //     int result = stoi(str);
            //     return (result > n) ? result : -1;
            // } catch (invalid_argument&) {
            //     return -1; // Conversion failed
            // } catch (out_of_range&) {
            //     return -1; // Integer out of range
            // }

            long long result = stoll(str);
            if(result > n && result <= INT_MAX) {
                return (int)result;
            } else {
                return -1;
            }
        }
        return -1;
    }
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int len = str.length();
        int idx1 = -1, idx2 = -1;

        idx1 = getFirstDecreasingEle(str, idx1, len);

        idx2 = getNextGreaterEle(str, idx1, idx2, len);
        
        return solve(str, idx1, idx2, n);
    }
};