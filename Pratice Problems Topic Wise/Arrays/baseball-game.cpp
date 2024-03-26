// https://leetcode.com/problems/baseball-game/description/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    int calPoints(vector<string>& operations) {
        vector<int> records;

        for (string& s : operations) {
            if (s == "+") {
                if (records.size() >= 2) {
                    int firstR  = records[records.size() - 1];
                    int secondR = records[records.size() - 2];
                    records.push_back(firstR + secondR);
                }
            }
            else if (s == "D") {
                if (!records.empty()) {
                    int prevR = records.back();
                    records.push_back(prevR * 2);
                }
            }
            else if (s == "C") {
                if (!records.empty()) {
                    records.pop_back();
                }
            }
            else {
                records.push_back(stoi(s));
            }
        }

        int result = accumulate(begin(records), end(records), 0);
        return result;
    }
};
