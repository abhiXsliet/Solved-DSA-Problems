// https://leetcode.com/problems/construct-string-with-repeat-limit/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getIdxForSingleLargestChar(int index, vector<int>& freq) {
        for (int i = index; i >= 0; i --) {
            if (freq[i]) {
                return i;
            }
        }
        return -1;
    }

    // TC : O(N)
    // SC : O(1)
    string approach_1(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a'] ++;
        }

        string result;
        for (int i = 25; i >= 0; i --) {
            while (freq[i]) {
                int len = min(freq[i], repeatLimit);
                freq[i] -= len;
                result += string(len, i + 'a');
                if (freq[i]) {
                    int idx = getIdxForSingleLargestChar(i - 1, freq);
                    if (idx == -1) return result;
                    result += (idx + 'a');
                    freq[idx] --;
                }
            }
        }
        return result;
    }

    // TC : O(N)
    // SC : O(1)
    string approach_2(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a'] ++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; i ++) {
            if (freq[i]) {
                pq.push(i);
            }
        }

        string result;
        while (!pq.empty()) {
            int largestCharIdx = pq.top();
            pq.pop();

            int len = min(freq[largestCharIdx], repeatLimit);
            freq[largestCharIdx] -= len;
            result.append(len, largestCharIdx + 'a');

            if (freq[largestCharIdx]) {
                if (!pq.empty()) {
                    int secondLargestCharIdx = pq.top();
                    freq[secondLargestCharIdx] --;
                    if (freq[secondLargestCharIdx] == 0) pq.pop();
                    result += (secondLargestCharIdx + 'a');
                } else break;
                pq.push(largestCharIdx);
            }
        }
        return result;
    }
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // return approach_1(s, repeatLimit);   // SIMULATION

        return approach_2(s, repeatLimit);  // HEAP
    }
};